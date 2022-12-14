// Fill out your copyright notice in the Description page of Project Settings.


#include "PressurePlate.h"
#include "Kismet/GameplayStatics.h"
#include "InteractableInterface.h"


// Sets default values
APressurePlate::APressurePlate()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Sets base mesh
	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
	SetRootComponent(BaseMesh);

	//Creates moving mesh
	MoveableMesh = CreateDefaultSubobject<UMovableStaticMeshComponent>(TEXT("Movable Mesh"));
	MoveableMesh->SetupAttachment(BaseMesh);

	//Adds the box component for use when overlap
	TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Overlap Area"));
	TriggerBox->SetupAttachment(BaseMesh);
}

// Called when the game starts or when spawned
void APressurePlate::BeginPlay()
{
	Super::BeginPlay();

	//Adds event listeners for beginning overlap and ending overlap
	TriggerBox->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OnBeginOverlap);
	TriggerBox->OnComponentEndOverlap.AddDynamic(this, &ThisClass::OnEndOverlap);
}

// Called every frame
void APressurePlate::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void APressurePlate::Interact(bool bIsInteracting)
{
	//Gets array of every actor that has the InteractableInterface
	TArray<AActor*> InteractableActors;
	UGameplayStatics::GetAllActorsWithInterface(GetWorld(), UInteractableInterface::StaticClass(), InteractableActors);

	//Iterates through each actor and determines if it shares the same IDs that are supposed to be interacted with
	for (AActor* Actor : InteractableActors)
	{
		int ObjectID = IInteractableInterface::Execute_GetObjectID(Actor);
		for (int ID : TargetIDs)
		{
			if (ID == ObjectID)
			{
				IInteractableInterface::Execute_Interact(Actor, bIsInteracting);
			}
		}
	}
}

void APressurePlate::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//Tells the mesh to move down and calls the interact
	if (!bIsDisabled && !bIsTriggered)
	{
		MoveableMesh->Move(true);
		Interact(true);

		bIsTriggered = true;
	}
}

void APressurePlate::OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	//Tells the mesh to move back up and calls interact with false
	if (!bIsDisabled && bResetTrigger)
	{
		MoveableMesh->Move(false);
		Interact(false);

		bIsTriggered = false;
	}
}