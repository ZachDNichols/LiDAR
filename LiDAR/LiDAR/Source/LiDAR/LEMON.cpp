// Fill out your copyright notice in the Description page of Project Settings.


#include "LEMON.h"
#include "FirstPersonCharacter.h"
#include "Laser.h"
#include "Dot.h"
#include "Camera/PlayerCameraManager.h"
#include "Kimset/GameplayStatistics.h"
#include "Camera/CameraComponent.h"
#include "Math/Vector.h"
#include "Components/StaticMeshComponent.h"

// Sets default values for this component's properties
ULEMON::ULEMON()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void ULEMON::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void ULEMON::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (firing)
    {
        UWorld* const World = GetWorld();
        APlayerController* PlayerController = Cast<APlayerController(Character->GetController);
        FRotator SpawnRotation = PlayerController->PlayerCameraManager->GetCameraRotation();
        FVector SpawnLocation = GetOwner()->GetActorLocation();
        
        FActorSpawnParameters SpawnParams;
        
        Laser = World->SpawnActor<ALaser>(LaserBeam, SpawnLocation, SpawnRotation, SpawnParams);
    }
}

void ULEMON::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    if(Character != nullptr)
    {
        Character->OnUseItem.RemoveDynamic(this, &ULEMON::Fire);
    }
}

void ULEMON::Fire()
{
    firing = true
}

void ULEMON::HaltFire()
{
    firing = false;
}

