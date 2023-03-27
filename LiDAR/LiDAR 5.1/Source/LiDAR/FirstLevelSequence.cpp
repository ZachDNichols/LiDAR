// Fill out your copyright notice in the Description page of Project Settings.


#include "FirstLevelSequence.h"
#include "Kismet/GameplayStatics.h"
#include "Interaction/InteractableInterface.h"
#include "TimerManager.h"
#include "FirstPersonCharacter.h"

// Called when the game starts or when spawned
void AFirstLevelSequence::BeginPlay()
{
	Super::BeginPlay();
	TArray<AActor*> Characters;


	//Gets a pointer to player
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AFirstPersonCharacter::StaticClass(), Characters);

	if (Characters.Num() > 0)
	{
		Character = Cast<AFirstPersonCharacter>(Characters[0]);
	}

	if (Character && !bIsDisabled)
	{
		bIsTriggered = true;
		GetWorld()->GetTimerManager().SetTimer(VoiceLineTimer, this, &AFirstLevelSequence::PlayVoiceLine, 2.f, false);
	}
}

//If there is a player in the world, this voice line will play, then open the door
void AFirstLevelSequence::PlayVoiceLine()
{
	UGameplayStatics::PlaySoundAtLocation(GetWorld(), VoiceLine, GetActorLocation(), 1.f, 1.f, 0.f, SoundAttenuation, VicSoundConcurrency);
	GetWorld()->GetTimerManager().SetTimer(VoiceLineTimer, this, &AFirstLevelSequence::Interact, 22.591f, false);
}

void AFirstLevelSequence::Interact()
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
				IInteractableInterface::Execute_Interact(Actor, true);
			}
		}
	}
}

// Called every frame
void AFirstLevelSequence::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

