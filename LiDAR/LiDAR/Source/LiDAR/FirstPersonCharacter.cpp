// Fill out your copyright notice in the Description page of Project Settings.

#include "FirstPersonCharacter.h"
#include "GameFramework/Actor.h"
#include "Animation/AnimInstance.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/InputSettings.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "GameFramework/Controller.h"
#include "Camera/PlayerCameraManager.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"


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
}

// Called when the game starts or when spawned
void AFirstPersonCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFirstPersonCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

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
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AFirstPersonCharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &AFirstPersonCharacter::StopJumping);

	GetCharacterMovement()->NavAgentProps.bCanCrouch = true;
	PlayerInputComponent->BindAction("Crouch", IE_Pressed, this, &AFirstPersonCharacter::StartCrouch);
	PlayerInputComponent->BindAction("Crouch", IE_Released, this, &AFirstPersonCharacter::EndCrouch);

	PlayerInputComponent->BindAction("Shoot", IE_Pressed, this, &AFirstPersonCharacter::BeginShoot);
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

void AFirstPersonCharacter::StartCrouch()
{
	Crouch();
}

void AFirstPersonCharacter::EndCrouch()
{
	UnCrouch();
}

void AFirstPersonCharacter::BeginShoot()
{
	FVector SpawnLocation = FirstPersonCamera->GetRelativeLocation();
	FVector DirectionVector = FirstPersonCamera->GetForwardVector() * 10000.f;
	FHitResult HitResult;
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this);


	if (GetWorld()->LineTraceSingleByChannel(HitResult, SpawnLocation, DirectionVector, ECollisionChannel::ECC_Visibility, Params, FCollisionResponseParams()))
	{

	}
	
	DrawDebugLine(GetWorld(), SpawnLocation, DirectionVector, FColor::Red, false, 5.0f, 0, 5.f);

}

