// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingStaticMeshActor.h"

// Sets default values
AMovingStaticMeshActor::AMovingStaticMeshActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
	SetRootComponent(BaseMesh);

	MovableMesh = CreateDefaultSubobject<UMovableStaticMeshComponent>(TEXT("Movable Mesh"));
	MovableMesh->SetupAttachment(GetRootComponent());

}

// Called when the game starts or when spawned
void AMovingStaticMeshActor::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AMovingStaticMeshActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

int AMovingStaticMeshActor::GetObjectID_Implementation()
{
	return ObjectID;
}

void AMovingStaticMeshActor::Interact_Implementation(bool bInteracting)
{
	if (!bIsDisabled)
	{
		MovableMesh->Move(bInteracting);
	}
}