// Fill out your copyright notice in the Description page of Project Settings.


#include "PressurePlate.h"

#include "Kismet/GameplayStatics.h"
#include "InteractableInterface.h"

// Sets default values
APressurePlate::APressurePlate()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
	SetRootComponent(BaseMesh);

	MoveableMesh = CreateDefaultSubobject<UMovableStaticMeshComponent>(TEXT("Movable Mesh"));
	MoveableMesh->SetupAttachment(BaseMesh);

	OverlapComponent = CreateDefaultSubobject<USphereComponent>(TEXT("Overlap Area"));
	OverlapComponent->SetupAttachment(MoveableMesh);
}

// Called when the game starts or when spawned
void APressurePlate::BeginPlay()
{
	Super::BeginPlay();

	OverlapComponent->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OnBeginOverlap);
	OverlapComponent->OnComponentEndOverlap.AddDynamic(this, &ThisClass::OnEndOverlap);
}

// Called every frame
void APressurePlate::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APressurePlate::Interact(bool bIsInteracting)
{
	TArray<AActor*> InteractableActors;
	UGameplayStatics::GetAllActorsWithInterface(GetWorld(), UInteractableInterface::StaticClass(), InteractableActors);

	for (AActor* Actor : InteractableActors)
	{
		FName InteractTag = IInteractableInterface::Execute_GetInteractTag(Actor);
		for (FName Tag : TargetTags)
		{
			if (InteractTag.IsEqual(Tag, ENameCase::IgnoreCase))
			{
				IInteractableInterface::Execute_Interact(Actor, bIsInteracting);
			}
		}
	}
}

void APressurePlate::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (!bIsDisabled && !bIsTriggered)
	{
		MoveableMesh->Move(true);
		Interact(true);

		bIsTriggered = true;
		bResetTrigger = true;
	}
}

void APressurePlate::OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (!bIsDisabled && bResetTrigger)
	{
		MoveableMesh->Move(false);
		Interact(false);

		bIsTriggered = false;
		bResetTrigger = false;
	}
}