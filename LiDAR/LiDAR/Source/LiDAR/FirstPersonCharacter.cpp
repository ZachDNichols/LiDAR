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
    
    LaserMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LaserMesh"));
    
    PlayerHUDClass = nullptr;
    PlayerHUD = nullptr;
}

// Called when the game starts or when spawned
void AFirstPersonCharacter::BeginPlay()
{
	Super::BeginPlay();
	if (IsLocallyControlled() && PlayerHUDClass)
    {
        PlayerHUD = CreateWidget<ULiDARHUD>(GetWorld(), PlayerHUDClass);
        check(PlayerHUD);
        PlayerHUD->AddToPlayerScreen();
    }
    PlayerHUD->SetRadius(fMinRadius, fMaxRadius);
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
    if (bIsShooting)
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
    float x = FMath::RandRange(fRadius * -1, fRadius);
    float y = FMath::RandRange(fRadius * -1, fRadius);
    float z = FMath::RandRange(fRadius * -1, fRadius);
    
        //Gets world location of camera
        FVector SpawnLocation = FirstPersonCamera->GetComponentLocation();
        //Gets the end Vector beyond the player from a significant distance
        FVector EndVector = (FirstPersonCamera->GetForwardVector() * 10000) + SpawnLocation;
        EndVector = FVector(EndVector.X + x, EndVector.Y + y, EndVector.Z + z);
        //Contains collision data
        FHitResult HitResult;
        //Parameters for the line trace, there are not really any except for ignoring player collision
        FCollisionQueryParams Params;
        Params.AddIgnoredActor(this);
        //integer representing distance from player to wall
        //Checks if there is something that can be collided with in front of the player, if there is, draws a debug line
        if (GetWorld()->LineTraceSingleByChannel(HitResult, SpawnLocation, EndVector, ECollisionChannel::ECC_Visibility, Params, FCollisionResponseParams()))
        {
            DrawDebugLine(GetWorld(), SpawnLocation, EndVector, FColor::Red, false, 5.f, 0, 5.f);
            fDistance = HitResult.Distance;
            UE_LOG(LogTemp, Warning, TEXT("Distance is %d"), fDistance);
        }
}
    
void AFirstPersonCharacter::IncreaseRadius()
{
    float increment = 100.f;
    if (fRadius + increment <= fMaxRadius)
    {
        fRadius += increment;
		PlayerHUD->SetRadius(fRadius, fMaxRadius);
    }
}

void AFirstPersonCharacter::DecreaseRadius()
{
    float decrement = 100.f;
    if (fRadius - decrement >= fMinRadius)
    {
        fRadius -= decrement;
        PlayerHUD->SetRadius(fRadius, fMaxRadius);
    }
}

