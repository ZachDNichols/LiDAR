// Fill out your copyright notice in the Description page of Project Settings.

#include "FirstPersonCharacter.h"
#include "Camera/CameraComponent.h"
#include "TimerManager.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/InputSettings.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"
#include "Math/UnrealMathUtility.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SceneComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Engine/EngineTypes.h"
#include "Math/Vector.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"

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

    PhysicsHandle = CreateDefaultSubobject<UPhysicsHandleComponent>(TEXT("PhysicsHandle"));

}

// Called when the game starts or when spawned
void AFirstPersonCharacter::BeginPlay()
{
    Super::BeginPlay();
    step = false;
}

// Called every frame
void AFirstPersonCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);


    if (holdingObject)
    {
        SetGrabbedObject();
    }

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

    PlayerInputComponent->BindAction("Interact", IE_Pressed, this, &AFirstPersonCharacter::PickupPhysicsObject);

    PlayerInputComponent->BindAction("Esc", IE_Pressed, this, &AFirstPersonCharacter::PauseGame);
}

void AFirstPersonCharacter::PickupPhysicsObject()
{
    if (holdingObject)
    {
        ReleaseObject();
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Grab"));
        FHitResult Hit;
        FRotator Rot;
        FVector Loc;

        GetController()->GetPlayerViewPoint(Loc, Rot);

        FVector Start = Loc;
        FVector End = Start + (Rot.Vector() * 300.f);
        FCollisionQueryParams TraceParams;
        TraceParams.AddIgnoredActor(this);

        FRotator HitRotation;
        FRotator GrabRotation = FirstPersonCamera->GetComponentRotation();
        GrabRotation.Pitch = 0.f;
        GrabRotation.Roll = 0.f;

        if (GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Visibility, TraceParams))
        {
            if (Hit.GetComponent()->IsSimulatingPhysics())
            {
                //if (FirstPersonCamera->GetForwardVector().Z > -.6f)
                //{
                FVector origin = Hit.GetActor()->GetActorLocation();

                PhysicsHandle->GrabComponentAtLocationWithRotation(Hit.GetComponent(), FName(TEXT("ObjectGrabPoint")), /*FirstPersonCamera->GetComponentLocation() + (FirstPersonCamera->GetForwardVector() * 300.f)*/ origin, GrabRotation);
                holdingObject = true;
                PhysicsHandle->GetGrabbedComponent()->SetCollisionObjectType(ECC_GameTraceChannel3);
                heldObject = PhysicsHandle->GetGrabbedComponent()->GetOwner();
                EndUseItem.Broadcast();
                //}

            }
        }
    }
}

void AFirstPersonCharacter::SetGrabbedObject()
{
        FHitResult Hit;
        FRotator Rot;
        FVector Loc;

        //Sets the location and rotation based on what the player sees
        GetController()->GetPlayerViewPoint(Loc, Rot);

        //Sets the vector where the line trace should start
        FVector Start = Loc;
        //Sets the vector where it should end. Random numbers added to create offsets.
        FVector End = Start + (Rot.Vector() * 300.f);
        //Parameters for what should be ignored. We ignore the player collision.
        FCollisionQueryParams TraceParams;
        TraceParams.AddIgnoredActor(this);
        TraceParams.AddIgnoredActor(PhysicsHandle->GetGrabbedComponent()->GetOwner());
        //FRotator for getting the rotation of the line
        FRotator HitRotation;
        FRotator GrabRotation = FirstPersonCamera->GetComponentRotation();
        GrabRotation.Pitch = 0.f;
        GrabRotation.Roll = 0.f;

        PhysicsHandle->GetGrabbedComponent()->WakeAllRigidBodies();

        //Extent and origin of the actor being grabbed, however origin is not really used
        FVector origin;
        FVector extent;

        heldObject->GetActorBounds(false, origin, extent);

        float width = extent.X;

        FCollisionShape ObjectShape = FCollisionShape::MakeBox(extent);


        if (GetWorld()->SweepSingleByChannel(Hit, Start, End, PhysicsHandle->GetGrabbedComponent()->GetAttachmentRootActor()->GetActorRotation().Quaternion(), ECC_Visibility, ObjectShape, TraceParams))
        {
            UE_LOG(LogTemp, Warning, TEXT("SettingObject"));

            //If the point of where the object would be compared to the player's location is less than the size of the object, the object is released
            if (width*2.2f > FVector::Dist(FirstPersonCamera->GetComponentLocation(), FirstPersonCamera->GetComponentLocation() + FirstPersonCamera->GetForwardVector() * (Hit.Distance - width)))
            {
                ReleaseObject();
            }
            else
            {
                //Otherwise, object is set to the location
                FVector HoldLocation = FirstPersonCamera->GetComponentLocation() + FirstPersonCamera->GetForwardVector() * (Hit.Distance - width);
                PhysicsHandle->SetTargetLocation(HoldLocation);
            }
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("SettingObject"));
            //If there is not a hit location, the object will go to the farthest "reach" of the player
            PhysicsHandle->SetTargetLocation(FirstPersonCamera->GetComponentLocation() + FirstPersonCamera->GetForwardVector() * FVector::Dist(Start, End));
        }
}

void AFirstPersonCharacter::ReleaseObject()
{
    UE_LOG(LogTemp, Warning, TEXT("Release"));
    
    PhysicsHandle->GetGrabbedComponent()->SetCollisionObjectType(ECC_GameTraceChannel2);
    PhysicsHandle->ReleaseComponent();
    holdingObject = false;
    heldObject = nullptr;
}

void AFirstPersonCharacter::PauseGame()
{
         UGameplayStatics::SetGamePaused(GetWorld(), true);
        if (PauseMenu)
        {
            GetWorld()->GetFirstPlayerController()->bShowMouseCursor = true;
            PauseMenu->AddToViewport();
        }
}

void AFirstPersonCharacter::MoveForward(float Value)
{
    if (Value != 0.0f)
    {
        AddMovementInput(GetActorForwardVector(), Value);
        if (!step)
        {
            step = true;
            GetWorld()->GetTimerManager().SetTimer(FootStepTimer, this, &AFirstPersonCharacter::PlayFootStepSound, 0.32f, false, 0);
        }
    }
}

void AFirstPersonCharacter::MoveRight(float Value)
{
    if (Value != 0.0f)
    {
        AddMovementInput(GetActorRightVector(), Value);
        
        if (!step)
        {
            step = true;
            GetWorld()->GetTimerManager().SetTimer(FootStepTimer, this, &AFirstPersonCharacter::PlayFootStepSound, 0.32f, false);
        }
    }
}

//If stepping and moving, a footstep sound will be played every .32 seconds. This was calculated with trial and error.
void AFirstPersonCharacter::PlayFootStepSound()
{
    if (GetVelocity().Size() != 0 && !GetCharacterMovement()->IsFalling())
    {
        UGameplayStatics::PlaySoundAtLocation(GetWorld(), FootStepSounds[0], GetActorLocation(), 1.f, 1.f);
        GetWorld()->GetTimerManager().SetTimer(FootStepTimer, this, &AFirstPersonCharacter::ResetStep, 0.32f, false);
    }
    else
    {
        GetWorld()->GetTimerManager().ClearAllTimersForObject(this);
        ResetStep();
    }
}


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
    if (!holdingObject)
    {
        OnUseItem.Broadcast();
    }
}

void AFirstPersonCharacter::EndShoot()
{
    EndUseItem.Broadcast();
}


void AFirstPersonCharacter::IncreaseRadius()
{
    ScrollUp.Broadcast();
}

void AFirstPersonCharacter::DecreaseRadius()
{
    ScrollDown.Broadcast();
}
