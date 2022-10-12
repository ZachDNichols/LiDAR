// Fill out your copyright notice in the Description page of Project Settings.

#include "FirstPersonCharacter.h"
#include "Blueprint/UserWidget.h"
#include "LiDARHUD.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/InputSettings.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"
#include "Math/UnrealMathUtility.h"
#include "Components/StaticMeshComponent.h"
#include "Dot.h"
#include "Laser.h"
#include "Components/SceneComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"


// Sets default values
AFirstPersonCharacter::AFirstPersonCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	//Set the size for the collision capsule
	GetCapsuleComponent()->InitCapsuleSize(55.5f, 96.0f);

	//Creates the camera
	FirstPersonCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCamera->SetupAttachment(GetCapsuleComponent());
	FirstPersonCamera->SetRelativeLocation(FVector(-39.56f, 1.75f, 64.f));
	FirstPersonCamera->bUsePawnControlRotation = true;
	UCameraComponent* Camera = GetFirstPersonCameraComponent();

	//Creates mesh component for use of viewing the gun
	PlayerMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("PlayerMesh"));
	PlayerMesh->SetupAttachment(FirstPersonCamera);
	PlayerMesh->bCastDynamicShadow = false;
	PlayerMesh->CastShadow = false;
	PlayerMesh->SetRelativeRotation(FRotator(1.9f, -19.19f, 5.2f));
	PlayerMesh->SetRelativeLocation(FVector(-0.5f, -4.4f, -155.7f));
	PlayerMesh->SetVisibility(false);
    
    HoldLocation = CreateDefaultSubobject<USceneComponent>(TEXT("HoldLocation"));
    HoldLocation->SetupAttachment(GetCapsuleComponent());
    
    PhysicsHandle = CreateDefaultSubobject<UPhysicsHandleComponent>(TEXT("PhysicsHandle"));
    
    PlayerHUDClass = nullptr;
    PlayerHUD = nullptr;
}

// Called when the game starts or when spawned
void AFirstPersonCharacter::BeginPlay()
{
	Super::BeginPlay();

}

void AFirstPersonCharacter::GetGun()
{
	if (IsLocallyControlled() && PlayerHUDClass)
	{
		PlayerHUD = CreateWidget<ULiDARHUD>(GetWorld(), PlayerHUDClass);
		check(PlayerHUD);
		PlayerHUD->AddToPlayerScreen();
	}
	PlayerHUD->SetRadius(fMinRadius, fMaxRadius);
	PlayerMesh->SetVisibility(true);
	hasGun = true;
}

void AFirstPersonCharacter::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    if (PlayerHUD)
    {
        PlayerHUD->RemoveFromParent();
        PlayerHUD = nullptr;
    }
}

// Called every frame
void AFirstPersonCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    if (bIsShooting && hasGun)
        ShootLaser();
}

// Called to bind functionality to input
void AFirstPersonCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//Camera controls for a mouse
	PlayerInputComponent->BindAxis("Look Up / Down Mouse", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("Turn Right / Left Mouse", this, &APawn::AddControllerYawInput);

	// Bind movement events
	PlayerInputComponent->BindAxis("Move Forward / Backward", this, &AFirstPersonCharacter::MoveForward);
	PlayerInputComponent->BindAxis("Move Right / Left", this, &AFirstPersonCharacter::MoveRight);

	//Bind player actions
    
    //Actions for player jumping
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AFirstPersonCharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &AFirstPersonCharacter::StopJumping);

    //Actions for player crouching
	GetCharacterMovement()->NavAgentProps.bCanCrouch = true;
	PlayerInputComponent->BindAction("Crouch", IE_Pressed, this, &AFirstPersonCharacter::StartCrouch);
	PlayerInputComponent->BindAction("Crouch", IE_Released, this, &AFirstPersonCharacter::EndCrouch);

    //Actions for player shooting
	PlayerInputComponent->BindAction("Shoot", IE_Pressed, this, &AFirstPersonCharacter::BeginShoot);
    PlayerInputComponent->BindAction("Shoot", IE_Released, this, &AFirstPersonCharacter::EndShoot);
    
    //Actions for increasing and decreasing radius
    PlayerInputComponent->BindAction("Increase Radius", IE_Pressed, this, &AFirstPersonCharacter::IncreaseRadius);
    PlayerInputComponent->BindAction("Decrease Radius", IE_Pressed, this, &AFirstPersonCharacter::DecreaseRadius);
}

void AFirstPersonCharacter::MoveForward(float Value)
{
	if (Value != 0.0f)
	{
		AddMovementInput(GetActorForwardVector(), Value);
	}
}

void AFirstPersonCharacter::MoveRight(float Value)
{
	if (Value != 0.0f)
	{
		AddMovementInput(GetActorRightVector(), Value);
	}
}

//Handles the player crouching
void AFirstPersonCharacter::StartCrouch()
{
	Crouch();
}

//Handles the player crouching
void AFirstPersonCharacter::EndCrouch()
{
	UnCrouch();
}

void AFirstPersonCharacter::BeginShoot()
{
    bIsShooting = true;
    PrimaryActorTick.bCanEverTick = true;
}

void AFirstPersonCharacter::EndShoot()
{
    bIsShooting = false;
    PrimaryActorTick.bCanEverTick = false;
}

void AFirstPersonCharacter::ShootLaser()
{
    if (hasGun)
    {
	    //Generates random numbers to add variance to where the dots land
		float x = FMath::RandRange(fRadius * -1, fRadius);
		float y = FMath::RandRange(fRadius * -1, fRadius);
		float z = FMath::RandRange(fRadius * -1, fRadius);
	
		FHitResult Hit;
		FRotator Rot;
		FVector Loc;
	
	    //Sets the location and rotation based on what the player sees
		GetController()->GetPlayerViewPoint(Loc, Rot);
	
	    //Sets the location to look more like it is coming out of the barrel of the player gun
		Loc = Loc + (((FirstPersonCamera->GetForwardVector() * 60.f) + (FirstPersonCamera->GetRightVector() * 20.f) - (FirstPersonCamera->GetUpVector() * 22.f)) + (GetVelocity() * .09f));
	    
	    //Sets the vector where the line trace should start
	    FVector Start = Loc;
	    //Sets the vector where it shoud end. Random numbers added to create offsets.
		FVector End = Start + (Rot.Vector() * 50000);
		End = FVector(End.X + x, End.Y + y, End.Z + z);
	    //Parameters for what should be ignored. We ignore the player collision.
		FCollisionQueryParams TraceParams;
		TraceParams.AddIgnoredActor(this);
	    //FRotator for getting the rotation of the line
		FRotator HitRotation;
	    
		
		
		if (GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Visibility, TraceParams))
		{
	        //Draws debug lines for the traces
			//DrawDebugLine(GetWorld(), Start, End, FColor::Red, false, .2f);
	        //Draws debug boxes where the collision impact occure
			//DrawDebugBox(GetWorld(), Hit.ImpactPoint, FVector(5, 5, 5), FColor::Orange, false, .2f);
			
	        //Finds the hit rotation, then rotates it to align correctly
			HitRotation = (((Start - End) * -1).Rotation());
			HitRotation.Pitch -= 90.f;
	        
	        //
			FTransform SpawnTransform;
			SpawnTransform.SetLocation(Start);
			
			FActorSpawnParameters SpawnParams;
	
			LaserBeam = GetWorld()->SpawnActor<ALaser>(LaserBP, SpawnTransform, SpawnParams);
	        
	        float fDistance = Hit.Distance;
	        
			LaserBeam->SetEnd(Hit.ImpactPoint);
	
			SpawnTransform.SetLocation(Hit.ImpactPoint);
	
			Dot = GetWorld()->SpawnActor<ADot>(DotBP, SpawnTransform, SpawnParams);
		}
    }
}
    
void AFirstPersonCharacter::IncreaseRadius()
{
    if (hasGun)
    {
	    float increment = 100.f;
	    if (fRadius + increment <= fMaxRadius)
	    {
	        fRadius += increment;
			PlayerHUD->SetRadius(fRadius, fMaxRadius);
	    }
    }
}

void AFirstPersonCharacter::DecreaseRadius()
{
    if (hasGun)
    {
	    float decrement = 100.f;
	    if (fRadius - decrement >= fMinRadius)
	    {
	        fRadius -= decrement;
	        PlayerHUD->SetRadius(fRadius, fMaxRadius);
	    }
    }
}

void AFirstPersonCharacter::PickupPhysicsObject()
{
    
}
