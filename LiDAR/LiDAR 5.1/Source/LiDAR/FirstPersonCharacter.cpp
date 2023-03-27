// Fill out your copyright notice in the Description page of Project Settings.

#include "FirstPersonCharacter.h"
#include "Camera/CameraComponent.h"
#include "TimerManager.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"
#include "Math/UnrealMathUtility.h"
#include "Components/SceneComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Engine/EngineTypes.h"
#include "Math/Vector.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "FirstPersonPlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Kismet/KismetMathLibrary.h"
#include "Sound/SoundCue.h"

// Sets default values
AFirstPersonCharacter::AFirstPersonCharacter()
{
    // Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
    
    //Set the size for the collision capsule
    GetCapsuleComponent()->InitCapsuleSize(55.5f, 96.0f);
    GetCapsuleComponent()->OnComponentHit.AddDynamic(this, &AFirstPersonCharacter::OnCollision);

    //Creates the camera
    FirstPersonCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
    FirstPersonCamera->SetupAttachment(GetCapsuleComponent());
    FirstPersonCamera->SetRelativeLocation(FVector(0.f, 0.f, 74.f));
    FirstPersonCamera->bUsePawnControlRotation = true;

    //Creates mesh component for use of viewing the gun
    PlayerMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
    PlayerMesh->SetupAttachment(FirstPersonCamera);
    PlayerMesh->bCastDynamicShadow = false;
    PlayerMesh->CastShadow = false;
    PlayerMesh->SetVisibility(false);

    PhysicsHandle = CreateDefaultSubobject<UPhysicsHandleComponent>(TEXT("PhysicsHandle"));

    MoveScale = 1.f;
    CrouchEyeOffset = FVector(0.f);
    CrouchSpeed = 250.f;
}

// Called when the game starts or when spawned
void AFirstPersonCharacter::BeginPlay()
{
    Super::BeginPlay();
    step = false;
    relativeX = FirstPersonCamera->GetRelativeLocation().X;
    relativeY = FirstPersonCamera->GetRelativeLocation().Y;
}

// Called every frame
void AFirstPersonCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);


    if (holdingObject)
    {
        UpdateGrabbedObject();
    }

    if (bisCrouching)
    {
        UpdateCrouch(DeltaTime);
    }
}

void AFirstPersonCharacter::OnCollision(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
    if (OtherActor == heldObject)
    {
        ReleaseObject();
    }
}
    
// Called to bind functionality to input
void AFirstPersonCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    //Enhanced Input Component
    UEnhancedInputComponent* EIC = Cast<UEnhancedInputComponent>(PlayerInputComponent);
    //First Person Player Controller
    AFirstPersonPlayerController* FPPC = Cast<AFirstPersonPlayerController>(Controller);
    check(EIC && FPPC);
    EIC->BindAction(FPPC->MoveAction, ETriggerEvent::Triggered, this, &AFirstPersonCharacter::Move);
    EIC->BindAction(FPPC->CrouchAction, ETriggerEvent::Triggered, this, &AFirstPersonCharacter::StartCrouch);
    EIC->BindAction(FPPC->CrouchAction, ETriggerEvent::Completed, this, &AFirstPersonCharacter::EndCrouch);
    EIC->BindAction(FPPC->JumpAction, ETriggerEvent::Triggered, this, &ACharacter::Jump);
    EIC->BindAction(FPPC->JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);
    EIC->BindAction(FPPC->LookAction, ETriggerEvent::Triggered, this, &AFirstPersonCharacter::Look);
    EIC->BindAction(FPPC->ShootAction, ETriggerEvent::Triggered, this, &AFirstPersonCharacter::UseItem);
    EIC->BindAction(FPPC->ShootAction, ETriggerEvent::Completed, this, &AFirstPersonCharacter::EndUseItem);
    EIC->BindAction(FPPC->IncreaseScrollAction, ETriggerEvent::Triggered, this, &AFirstPersonCharacter::IncreaseRadius);
    EIC->BindAction(FPPC->DecreaseScrollAction, ETriggerEvent::Triggered, this, &AFirstPersonCharacter::DecreaseRadius);
    EIC->BindAction(FPPC->GrabObjectAction, ETriggerEvent::Triggered, this, &AFirstPersonCharacter::GrabObject);
    EIC->BindAction(FPPC->PauseGameAction, ETriggerEvent::Triggered, this, &AFirstPersonCharacter::PauseGame);

    const ULocalPlayer* LocalPlayer = FPPC->GetLocalPlayer();
    check(LocalPlayer);
    UEnhancedInputLocalPlayerSubsystem* Subsystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
    check(Subsystem);
    Subsystem->ClearAllMappings();
    Subsystem->AddMappingContext(FPPC->MappingContext, 0);
}

void AFirstPersonCharacter::Move(const struct FInputActionValue& ActionValue)
{
    const FVector Input = ActionValue.Get<FInputActionValue::Axis3D>();
    AddMovementInput(GetActorRotation().RotateVector(Input), MoveScale);

    if (!step)
    {
        step = true;
        GetWorld()->GetTimerManager().SetTimer(FootStepTimer, this, &AFirstPersonCharacter::PlayFootStepSound, 0.32f, false, 0);
    }
}

void AFirstPersonCharacter::Look(const struct FInputActionValue& ActionValue)
{
    const FVector2D LookAxisVector = ActionValue.Get<FVector2D>();

    AddControllerYawInput(LookAxisVector.X);
    AddControllerPitchInput(-LookAxisVector.Y);
}

void AFirstPersonCharacter::GrabObject(const struct FInputActionValue& ActionValue)
{
    if (holdingObject)
    {
        ReleaseObject();
    }
    else
    {
        PickupPhysicsObject();
    }
}

void AFirstPersonCharacter::StartCrouch()
{
    if (!bCrouchState)
    {
        MoveScale = MoveScale / 2;
        bCrouchState = true;
        bisCrouching = true;
    }
}

void AFirstPersonCharacter::EndCrouch()
{
    if (bCrouchState)
    {
        MoveScale = MoveScale * 2;
        bCrouchState = false;
        bisCrouching = true;
    }
}

//TODO: Switch this system to be one that functions on getting components rather than actors
void AFirstPersonCharacter::PickupPhysicsObject()
{
    if (PhysicsHandle)
    {
        FHitResult Hit;
        FRotator Rot;
        FVector Start;

        //Sets the location and rotation based on what the player sees
        Start = FirstPersonCamera->GetComponentLocation() + (FirstPersonCamera->GetForwardVector());
        Rot = FirstPersonCamera->GetComponentRotation();

        FVector End = Start + (Rot.Vector() * grabDistance);
        FCollisionQueryParams TraceParams;
        TraceParams.AddIgnoredActor(this);

        if (GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Visibility, TraceParams))
        {
            if (Hit.GetComponent()->IsSimulatingPhysics())
            {
                if(Hit.GetActor() == GetFloorActor())
                {
                    return;
                }
                
                Hit.GetActor()->SetActorRotation(GetActorRotation());
                
                FRotator GrabRotation = GetActorRotation();
                GrabRotation.Yaw = 0.f;
                
                PhysicsHandle->GrabComponentAtLocationWithRotation(Hit.GetComponent(), NAME_None, Hit.GetActor()->GetActorLocation(), GrabRotation);
                heldObject = Hit.GetActor();
                holdingObject = true;
                UpdateGrabbedObject();
            }
        }
    }
}

//TODO: Switch this system to be one that functions on getting componennts rather than actors
//This elegant dumpster fire somehow updates the object in the best way I could find
void AFirstPersonCharacter::UpdateGrabbedObject()
{
    FHitResult Hit;
    FRotator Rot = FirstPersonCamera->GetComponentRotation();
    FVector Start = FirstPersonCamera->GetComponentLocation();
    FVector origin;
    FVector extent;

    TArray<AActor*> IgnoredActors;
    IgnoredActors.Add(this);
    IgnoredActors.Add(heldObject);
    IgnoredActors.Add(ActorBehindPlayer());

    FVector End = Start + (Rot.Vector() * grabDistance);

    heldObject->GetActorBounds(false, origin, extent);

    float width = extent.X * 2.2f;

    PhysicsHandle->GetGrabbedComponent()->WakeAllRigidBodies();

    if (FVector::Dist(GetActorLocation(), heldObject->GetActorLocation()) > grabDistance + 80.f)
    {
        ReleaseObject();
    }

    //If the player is not looking at the an object close
    if (
        !UKismetSystemLibrary::BoxTraceSingle(
            this,
            Start,
            End,
            extent,
            Rot,
            TraceTypeQuery1,
            true,
            IgnoredActors,
            EDrawDebugTrace::None,
            Hit,
            true,
            FLinearColor::Red,
            FLinearColor::Green,
            5.f)
        )
    {
        objectRotation.Yaw = FirstPersonCamera->GetComponentRotation().Yaw;
        PhysicsHandle->SetTargetLocationAndRotation(End, objectRotation);
        return;
    }

    UE_LOG(LogTemp, Warning, TEXT("Hit: %s"), *Hit.GetActor()->GetName());

    AActor* Floor = GetFloorActor();
    FVector NewHoldLocation;

    //Determines if player is looking at the floor
    if (Floor == Hit.GetActor())
    {

        //This releases the object if the width of the held object is greater than the player while looking at the floor
        if (width > DistanceInFrontOfPlayer())
        {
            ReleaseObject();
            return;
        }

        NewHoldLocation = FirstPersonCamera->GetComponentLocation();

        //Changes where the object is placed depending on how close player is
        if (FVector::Dist(GetActorLocation(), Hit.ImpactPoint) > grabDistance / 2)
        {
            NewHoldLocation += GetActorForwardVector() * Hit.Distance;
        }
        else
        {
            NewHoldLocation += GetActorForwardVector() * (grabDistance / 2);
        }

        NewHoldLocation.Z = Hit.ImpactPoint.Z + 70.f;

        objectRotation.Yaw = FirstPersonCamera->GetComponentRotation().Yaw;
        PhysicsHandle->SetTargetLocationAndRotation(NewHoldLocation, objectRotation);
        return;
    }

    //If player gets too close to wall
    if (width > Hit.Distance)
    {
        return;
    }

    NewHoldLocation = FirstPersonCamera->GetComponentLocation();
    NewHoldLocation += FirstPersonCamera->GetForwardVector() * Hit.Distance;
    objectRotation.Yaw = FirstPersonCamera->GetComponentRotation().Yaw;
    PhysicsHandle->SetTargetLocationAndRotation(NewHoldLocation, objectRotation);

}

void AFirstPersonCharacter::ReleaseObject()
{
    FVector Velocity = PhysicsHandle->GetGrabbedComponent()->GetComponentVelocity();
    FVector MaxVelocity = FVector(200.f, 200.f, 200.f);

    if (Velocity.X > MaxVelocity.X)
    {
        Velocity.X = MaxVelocity.X;
    }
    else if (Velocity.X < MaxVelocity.X * -1)
    {
        Velocity.X = MaxVelocity.X * -1;
    }

    if (Velocity.Y > MaxVelocity.Y)
    {
        Velocity.Y = MaxVelocity.Y;
    }
    else if (Velocity.Y < MaxVelocity.Y * -1)
    {
        Velocity.Y = MaxVelocity.Y * -1;
    }

    if (Velocity.Z > MaxVelocity.Z)
    {
        Velocity.Z = MaxVelocity.Z;
    }
    else if (Velocity.Z < MaxVelocity.Z * -1)
    {
        Velocity.Z = MaxVelocity.Z * -1;
    }

    PhysicsHandle->GetGrabbedComponent()->ComponentVelocity = Velocity;

    UE_LOG(LogTemp, Warning, TEXT("%s"), *Velocity.ToString());
    
    PhysicsHandle->ReleaseComponent();
    holdingObject = false;
    heldObject = nullptr;
}

void AFirstPersonCharacter::PauseGame()
{
    if (PauseMenu)
    {
        UGameplayStatics::SetGamePaused(GetWorld(), true);
        GetWorld()->GetFirstPlayerController()->bShowMouseCursor = true;
        PauseMenu->AddToViewport();
    }
}

//TODO: Return component instead of actor
AActor* AFirstPersonCharacter::GetFloorActor()
{
    FHitResult Hit;
    FVector Start = GetActorLocation();
    FVector End = Start + (GetActorUpVector() * -5000.f);
    FCollisionQueryParams TraceParams;
    TraceParams.AddIgnoredActor(this);

    GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Visibility, TraceParams);
    UE_LOG(LogTemp, Warning, TEXT("Hit: %s"), *Hit.GetActor()->GetName());
    
    return Hit.GetActor();
}

void AFirstPersonCharacter::UpdateCrouch(float DeltaTime)
{
    const float newHalfHeight = CrouchSpeed * DeltaTime;
    const float currentHalfHeight = GetCapsuleComponent()->GetScaledCapsuleHalfHeight();

    //Player needs to go down.
    if (bCrouchState)
    {
        if (currentHalfHeight - newHalfHeight < 52)
        {
            GetCapsuleComponent()->SetCapsuleHalfHeight(52.f);
            bisCrouching = false;
        }
        else
        {
            GetCapsuleComponent()->SetCapsuleHalfHeight(currentHalfHeight - newHalfHeight);
        }
    }
    else
    {
        if (currentHalfHeight + newHalfHeight > 96.f)
        {
            GetCapsuleComponent()->SetCapsuleHalfHeight(96.f);
            bisCrouching = false;
        }
        else
        {
            GetCapsuleComponent()->SetCapsuleHalfHeight(currentHalfHeight + newHalfHeight);
        }
    }
}


float AFirstPersonCharacter::DistanceInFrontOfPlayer()
{
    FHitResult Hit;
    FVector Start = GetActorLocation();
    FVector End = Start + (GetActorForwardVector() * grabDistance);
    FCollisionQueryParams TraceParams;
    TraceParams.AddIgnoredActor(this);
    TraceParams.AddIgnoredActor(heldObject);

    GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Visibility, TraceParams);
    return FVector::Dist(Start, Hit.ImpactPoint);
}

//TODO: Return component instead of actor
AActor* AFirstPersonCharacter::ActorBehindPlayer()
{
    FHitResult Hit;
    FVector Start = GetActorLocation();
    FVector End = Start + (GetActorForwardVector() * -5000.f);
    FCollisionQueryParams TraceParams;
    TraceParams.AddIgnoredActor(this);
    TraceParams.AddIgnoredActor(heldObject);

    GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Visibility, TraceParams);

    return Hit.GetActor();
}


//If stepping and moving, a footstep sound will be played every .32 seconds. This was calculated with trial and error. I am a broken man.
void AFirstPersonCharacter::PlayFootStepSound()
{
    if (FootStepSounds.Num() > 0)
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

}

void AFirstPersonCharacter::UseItem()
{
    if (!holdingObject)
    {
        OnUseItem.Broadcast();
    }
}

void AFirstPersonCharacter::EndUseItem()
{
    OnEndUseItem.Broadcast();
}

void AFirstPersonCharacter::IncreaseRadius()
{
    ScrollUp.Broadcast();
}

void AFirstPersonCharacter::DecreaseRadius()
{
    ScrollDown.Broadcast();
}