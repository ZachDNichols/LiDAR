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
#include "Sound/SoundCue.h"

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
    FirstPersonCamera->SetRelativeLocation(FVector(0.f, 0.f, 74.f));
    FirstPersonCamera->bUsePawnControlRotation = true;

    //Creates mesh component for use of viewing the gun
    PlayerMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
    PlayerMesh->SetupAttachment(FirstPersonCamera);
    PlayerMesh->bCastDynamicShadow = false;
    PlayerMesh->CastShadow = false;
    PlayerMesh->SetVisibility(false);
    
    CrouchEyeOffset = FVector(0.f);
    CrouchSpeed = 250.f;

    PhysicsHandle = CreateDefaultSubobject<UPhysicsHandleComponent>("PhysicsHandle");
}

// Called every frame
void AFirstPersonCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);


    if (bHoldingObject)
    {
        UpdateGrabbedObject();
    }

    if (bIsCrouching)
    {
        UpdateCrouch(DeltaTime);
    }

    UE_LOG(LogTemp, Display, TEXT("%f"), FootStepRate);
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
    EIC->BindAction(FPPC->SprintAction, ETriggerEvent::Started, this, &AFirstPersonCharacter::StartSprint);
    EIC->BindAction(FPPC->SprintAction, ETriggerEvent::Completed, this, &AFirstPersonCharacter::EndSprint);

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
    AddMovementInput(GetActorRotation().RotateVector(Input), 1.f);

    if (!bStep)
    {
        bStep = true;
        GetWorld()->GetTimerManager().SetTimer(FootStepTimer, this, &AFirstPersonCharacter::PlayFootStepSound, FootStepRate, false, 0);
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
    if (bHoldingObject)
    {
        ReleaseObject(false);
    }
    else
    {
        PickupPhysicsObject();
    }
}

void AFirstPersonCharacter::StartSprint()
{
    if (!bCrouchState)
    {
        GetCharacterMovement()->MaxWalkSpeed = SprintSpeed;
        FootStepRate = FootStepRate / 2;
    }
}

void AFirstPersonCharacter::EndSprint()
{
    if (!bCrouchState)
    {
        GetCharacterMovement()->MaxWalkSpeed = RegularWalkSpeed;
        FootStepRate = FootStepRate * 2;
    }
}

void AFirstPersonCharacter::StartCrouch()
{
    if (!bCrouchState)
    {
        GetCharacterMovement()->MaxWalkSpeed = CrouchSpeed;
        bCrouchState = true;
        bIsCrouching = true;
        FootStepRate = FootStepRate * 2;
    }
}

void AFirstPersonCharacter::EndCrouch()
{
    if (bCrouchState)
    {
        GetCharacterMovement()->MaxWalkSpeed = RegularWalkSpeed;
        bCrouchState = false;
        bIsCrouching = true;
        FootStepRate = FootStepRate / 2;
    }
}

void AFirstPersonCharacter::PickupPhysicsObject()
{
    const FVector Start = FirstPersonCamera->GetComponentLocation();
    const FVector End = Start + FirstPersonCamera->GetForwardVector() * GrabDistance;
    FHitResult Hit;

    if (UKismetSystemLibrary::LineTraceSingle(GetWorld(), Start, End, TraceTypeQuery1, true, TArray<AActor*>(),
                                              EDrawDebugTrace::None, Hit, true, FLinearColor::Red,
                                              FLinearColor::Green, 5.f))
    {
        if (UPrimitiveComponent* Prim = Hit.GetComponent())
        {
            if (Hit.GetComponent()->IsSimulatingPhysics())
            {
                HeldObject = Prim;
                FVector Center = HeldObject->GetCenterOfMass();
                PhysicsHandle->GrabComponentAtLocationWithRotation(HeldObject, NAME_None, Center, FirstPersonCamera->GetForwardVector().Rotation());
                HeldObject->SetWorldRotation(FirstPersonCamera->GetForwardVector().Rotation());
                PhysicsHandle->bRotationConstrained = true;
                HeldObject->SetCollisionResponseToChannel(ECC_Pawn, ECR_Ignore);
                bHoldingObject = true;

            }
        }
    }
        
}

//This elegant dumpster fire somehow updates the object in the best way I could find
//This will have to work until Epic gets their shit together and makes a game engine that works
void AFirstPersonCharacter::UpdateGrabbedObject()
{
    const FVector Start = FirstPersonCamera->GetComponentLocation();
    FVector NewLocation = FirstPersonCamera->GetComponentLocation() + FirstPersonCamera->GetForwardVector() * GrabDistance;
    FHitResult Hit;
    TArray<AActor*> IgnoredActors = {HeldObject->GetOwner(), this};
    if (UKismetSystemLibrary::LineTraceSingle(GetWorld(), Start, NewLocation, TraceTypeQuery1, true, IgnoredActors,
                                          EDrawDebugTrace::None, Hit, true, FLinearColor::Red,
                                          FLinearColor::Green, 5.f))
    {
        NewLocation = Hit.ImpactPoint;
        UE_LOG(LogTemp, Display, TEXT("%s"), *Hit.GetActor()->GetName());
    }
     
    PhysicsHandle->SetTargetLocationAndRotation(NewLocation, FirstPersonCamera->GetForwardVector().Rotation());
}

void AFirstPersonCharacter::ReleaseObject(bool bThrow)
{
    bHoldingObject = false;
    PhysicsHandle->ReleaseComponent();
    PhysicsHandle->bRotationConstrained = false;
    HeldObject->SetCollisionResponseToChannel(ECC_Pawn, ECR_Block);
    HeldObject->SetPhysicsLinearVelocity(FVector::ZeroVector);
    if (bThrow)
    {
        const FVector ShootVelocity = FirstPersonCamera->GetForwardVector() * ThrowForce;
        HeldObject->AddImpulse(ShootVelocity, NAME_None, true);
        HeldObject = nullptr;
    }
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
            bIsCrouching = false;
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
            bIsCrouching = false;
        }
        else
        {
            GetCapsuleComponent()->SetCapsuleHalfHeight(currentHalfHeight + newHalfHeight);
        }
    }
}

//If stepping and moving, a footstep sound will be played every .32 seconds. This was calculated with trial and error. I am a broken man.
void AFirstPersonCharacter::PlayFootStepSound()
{
    if (FootStepSounds.Num() > 0)
    {
        if (GetVelocity().Size() != 0 && !GetCharacterMovement()->IsFalling())
        {
            UGameplayStatics::PlaySoundAtLocation(GetWorld(), FootStepSounds[0], GetActorLocation(), 1.f, 1.f);
            GetWorld()->GetTimerManager().SetTimer(FootStepTimer, this, &AFirstPersonCharacter::ResetStep, FootStepRate, false);
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
    if (!bHoldingObject)
    {
        OnUseItem.Broadcast();
    }
    else
    {
        ReleaseObject(true);
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