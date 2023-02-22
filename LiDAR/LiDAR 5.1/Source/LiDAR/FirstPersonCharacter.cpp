// Fill out your copyright notice in the Description page of Project Settings.

#include "FirstPersonCharacter.h"
#include "Camera/CameraComponent.h"
#include "TimerManager.h"
#include "Components/CapsuleComponent.h"
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
#include "FirstPersonPlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/FloatingPawnMovement.h"

// Sets default values
AFirstPersonCharacter::AFirstPersonCharacter()
{
    // Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true; 
    GetCharacterMovement()->NavAgentProps.bCanCrouch = true;

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

    Movement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("Movement"));

    MoveScale = 1.f;
    CrouchEyeOffset = FVector(0.f);
    CrouchSpeed = 12.f;
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

    float CrouchInterpTime = FMath::Min(1.f, CrouchSpeed * DeltaTime);
    CrouchEyeOffset = (1.f - CrouchInterpTime) * CrouchEyeOffset;

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
    EIC->BindAction(FPPC->ShootAction, ETriggerEvent::Triggered, this, &AFirstPersonCharacter::BeginShoot);
    EIC->BindAction(FPPC->ShootAction, ETriggerEvent::Completed, this, &AFirstPersonCharacter::EndShoot);
    EIC->BindAction(FPPC->IncreaseScrollAction, ETriggerEvent::Triggered, this, &AFirstPersonCharacter::IncreaseRadius);
    EIC->BindAction(FPPC->DecreaseScrollAction, ETriggerEvent::Triggered, this, &AFirstPersonCharacter::DecreaseRadius);
    EIC->BindAction(FPPC->GrabObjectAction, ETriggerEvent::Triggered, this, &AFirstPersonCharacter::GrabObject);

    ULocalPlayer* LocalPlayer = FPPC->GetLocalPlayer();
    check(LocalPlayer);
    UEnhancedInputLocalPlayerSubsystem* Subsystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
    check(Subsystem);
    Subsystem->ClearAllMappings();
    Subsystem->AddMappingContext(FPPC->MappingContext, 0);
}

void AFirstPersonCharacter::Move(const struct FInputActionValue& ActionValue)
{
    FVector Input = ActionValue.Get<FInputActionValue::Axis3D>();
    AddMovementInput(GetActorRotation().RotateVector(Input), MoveScale);
}

void AFirstPersonCharacter::Look(const struct FInputActionValue& ActionValue)
{
    FVector2D LookAxisVector = ActionValue.Get<FVector2D>();

    AddControllerYawInput(LookAxisVector.X);
    AddControllerPitchInput(-LookAxisVector.Y);
}

void AFirstPersonCharacter::OnStartCrouch(float HalfHeightAdjust, float ScaledHalfHeightAdjust)
{
    if (HalfHeightAdjust == 0.f)
    {
        return;
    }

    float StartBaseEyeHeight = BaseEyeHeight;
    Super::OnStartCrouch(HalfHeightAdjust, ScaledHalfHeightAdjust);
    CrouchEyeOffset.Z += StartBaseEyeHeight - BaseEyeHeight + HalfHeightAdjust;
    FirstPersonCamera->SetRelativeLocation(FVector(0.f, 0.f, BaseEyeHeight), false);
}

void AFirstPersonCharacter::OnEndCrouch(float HalfHeightAdjust, float ScaledHalfHeightAdjust)
{
    if (HalfHeightAdjust == 0.f)
    {
        return;
    }

    float StartBaseEyeHeight = BaseEyeHeight;
    Super::OnEndCrouch(HalfHeightAdjust, ScaledHalfHeightAdjust);
    CrouchEyeOffset.Z += StartBaseEyeHeight - BaseEyeHeight - HalfHeightAdjust;
    FirstPersonCamera->SetRelativeLocation(FVector(0.f, 0.f, BaseEyeHeight), false);
}

void AFirstPersonCharacter::CalcCamera(float DeltaTime, struct FMinimalViewInfo& OutResult)
{
    if (FirstPersonCamera)
    {
        FirstPersonCamera->GetCameraView(DeltaTime, OutResult);
        OutResult.Location += CrouchEyeOffset;
    }
}

void AFirstPersonCharacter::GrabObject(const struct FInputActionValue& ActionValue)
{
    //UE_LOG(LogTemp, Warning, TEXT("Grab value is %s"), (ActionValue.Get<bool>() ? TEXT("true") : TEXT("false")));
    if (ActionValue.Get<bool>() == true)
    {
        UE_LOG(LogTemp, Warning, TEXT("Grabbed!"));
    }
    else if (ActionValue.Get<bool>() == false)
    {
        UE_LOG(LogTemp, Warning, TEXT("Released!"));
    }
}

void AFirstPersonCharacter::StartCrouch()
{
    Crouch();
}

void AFirstPersonCharacter::EndCrouch()
{
    UnCrouch();
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
            //If there is not a hit location, the object will go to the farthest "reach" of the player
            PhysicsHandle->SetTargetLocation(FirstPersonCamera->GetComponentLocation() + FirstPersonCamera->GetForwardVector() * FVector::Dist(Start, End));
        }
}

void AFirstPersonCharacter::ReleaseObject()
{
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

void AFirstPersonCharacter::PickupPhysicsObject()
{
    if (holdingObject)
    {
        ReleaseObject();
    }
    else if (!holdingObject)
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
        //FRotator for getting the rotation of the line
        FRotator HitRotation;
        FRotator GrabRotation = FirstPersonCamera->GetComponentRotation();
        GrabRotation.Pitch = 0.f;
        GrabRotation.Roll = 0.f;

        if (GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Visibility, TraceParams))
        {
            if (Hit.GetComponent()->IsSimulatingPhysics())
            {
                if (FirstPersonCamera->GetForwardVector().Z > -.6f)
                {
                    FVector origin = Hit.GetActor()->GetActorLocation();

                    PhysicsHandle->GrabComponentAtLocationWithRotation(Hit.GetComponent(), FName(TEXT("ObjectGrabPoint")), /*FirstPersonCamera->GetComponentLocation() + (FirstPersonCamera->GetForwardVector() * 300.f)*/ origin, GrabRotation);
                    holdingObject = true;
                    PhysicsHandle->GetGrabbedComponent()->SetCollisionObjectType(ECC_GameTraceChannel3);
                    heldObject = PhysicsHandle->GetGrabbedComponent()->GetOwner();
                    EndUseItem.Broadcast();
                }
            }
        }
    }
}
