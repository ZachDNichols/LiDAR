// Fill out your copyright notice in the Description page of Project Settings.


#include "FirstDiagloueScriptedSequence.h"
#include "Kismet/GameplayStatics.h"
#include "InteractableInterface.h"
#include "TimerManager.h"
#include "FirstPersonCharacter.h"

// Sets default values
AFirstDiagloueScriptedSequence::AFirstDiagloueScriptedSequence()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFirstDiagloueScriptedSequence::BeginPlay()
{
	Super::BeginPlay();
	TArray<AActor*> Characters;

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AFirstPersonCharacter::StaticClass(), Characters);

	if (Characters.Num() > 0)
	{
		Character = Cast<AFirstPersonCharacter>(Characters[0]);
	}

	if (Character && !bIsDisabled)
	{
		bIsTriggered = true;
		GetWorld()->GetTimerManager().SetTimer(VoiceLineTimer, this, &AFirstDiagloueScriptedSequence::PlayVoiceLine, 2.f, false);
	}
}

void AFirstDiagloueScriptedSequence::PlayVoiceLine()
{
	if (SoundAttenuation)
	{
		UGameplayStatics::PlaySoundAtLocation(GetWorld(), VoiceLine, GetActorLocation(), 1.f, 1.f, 0.f, SoundAttenuation);
	}
	else
	{
		UGameplayStatics::PlaySoundAtLocation(GetWorld(), VoiceLine, GetActorLocation(), 1.f, 1.f);
	}
	GetWorld()->GetTimerManager().SetTimer(VoiceLineTimer, this, &AFirstDiagloueScriptedSequence::Interact, 22.591f, false);
}

void AFirstDiagloueScriptedSequence::Interact()
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
void AFirstDiagloueScriptedSequence::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

