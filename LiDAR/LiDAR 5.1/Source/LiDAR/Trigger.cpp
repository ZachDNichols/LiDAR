// Fill out your copyright notice in the Description page of Project Settings.


#include "Trigger.h"
#include "FirstPersonCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"
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

	//Event listener for overlap
	TriggerBox->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OnBeginOverlap);
}

// Called every frame
void ATrigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

//Function for overlapping
void ATrigger::Interact()
{
	//Array of actors that use InteractableInterface
	TArray<AActor*> InteractableActors;
	UGameplayStatics::GetAllActorsWithInterface(GetWorld(), UInteractableInterface::StaticClass(), InteractableActors);

	//Iterates through each actor and find actors that have the same IDs in the array of Target IDs
	for (AActor* Actor : InteractableActors)
	{
		int ObjectID = IInteractableInterface::Execute_GetObjectID(Actor);
		for (int ID : TargetIDs)
		{
			if (ID == ObjectID)
			{
				IInteractableInterface::Execute_Interact(Actor, TriggerCall);
			}
		}
	}
}
void ATrigger::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//Determines if actor overlapping is a player
	if (Cast<AFirstPersonCharacter>(OtherActor))
	{
		//Checks to make sure trigger is not disabled or triggered
		if (!bIsDisabled && !isTriggered)
		{
			//If there is a sound, the sound will play, and then check if interact needs to wait
			if (Sound)
			{
				UGameplayStatics::PlaySoundAtLocation(GetWorld(), Sound, GetActorLocation(), 1.f, 1.f);
				if (WaitForAudio)
				{
					GetWorld()->GetTimerManager().SetTimer(SoundTimer, this, &ThisClass::Interact, Sound->GetDuration(), false);
				}
				else
				{
					Interact();
				}
				isTriggered = true;
			}
			//Otherwise, interaction is called
			else
			{
				Interact();
				isTriggered = true;
			}
		}
	}
}