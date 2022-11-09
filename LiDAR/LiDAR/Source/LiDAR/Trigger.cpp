// Fill out your copyright notice in the Description page of Project Settings.


#include "Trigger.h"
#include "Kismet/GameplayStatics.h"
#include "SpeakerInterface.h"
#include "InteractableInterface.h"

// Sets default values
ATrigger::ATrigger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger Box"));
	SetRootComponent(TriggerBox);
}

// Called when the game starts or when spawned
void ATrigger::BeginPlay()
{
	Super::BeginPlay();
	
	TriggerBox->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OnBeginOverlap);
}

// Called every frame
void ATrigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ATrigger::Interact(bool isInteracting)
{

	TArray<AActor*> InteractableActors;
	UGameplayStatics::GetAllActorsWithInterface(GetWorld(), UInteractableInterface::StaticClass(), InteractableActors);

	for (AActor* Actor : InteractableActors)
	{
		int ObjectID = IInteractableInterface::Execute_GetObjectID(Actor);
		for (int ID : TargetIDs)
		{
			if (ID == ObjectID)
			{
				IInteractableInterface::Execute_Interact(Actor, isInteracting);
			}
		}
	}

	if (Sound)
	{
		
		TArray<AActor*> InteractableSpeakers;
		UGameplayStatics::GetAllActorsWithInterface(GetWorld(), USpeakerInterface::StaticClass(), InteractableSpeakers);

		for (AActor* Actor : InteractableSpeakers)
		{
			FName ObjectTag = ISpeakerInterface::Execute_GetObjectTag(Actor);
			for (FName ID : TargetTags)
			{
				if (ObjectTag.IsEqual(ID, ENameCase::IgnoreCase))
				{
					ISpeakerInterface::Execute_PlaySound(Actor, Sound);
				}
			}
		}
	}
}
void ATrigger::OnBeginOverlap(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (!bIsDisabled && !isTriggered)
	{
		Interact(TriggerCall);
		isTriggered = true;
	}
}