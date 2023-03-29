// Copyright 2023 Zach Nichols, All Rights Reserved


#include "BoxTrigger.h"

#include "FirstPersonCharacter.h"
#include "Interaction/InteractableInterface.h"
#include "Kismet/GameplayStatics.h"

ABoxTrigger::ABoxTrigger()
{
	OnActorBeginOverlap.AddDynamic(this, &ABoxTrigger::OnBeginOverlap);
}

void ABoxTrigger::OnBeginOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	if (Cast<AFirstPersonCharacter>(OtherActor))
	{
		if (bMultipleIDs && TargetObjects.Num() > 0)
		{
			TriggerInteraction(0);
		}
		else
		{
			TriggerInteraction();
		}
	}
}

void ABoxTrigger::TriggerInteraction()
{
	USoundBase* Sound = TargetObject.Sound;
	USoundConcurrency* SoundConcurrency;

	if (TargetObject.bIsVoiceLine)
	{
		SoundConcurrency = VictorSoundConcurrency;
	}
	else
	{
		SoundConcurrency = TriggerSoundConcurrency;
	}
	
	if (TargetObject.bJustSound)
	{
		if (Sound)
		{
			UGameplayStatics::PlaySoundAtLocation(GetWorld(), Sound, GetActorLocation(), 1.0f, 1.0f, 0.0f, SoundAttenuation, TriggerSoundConcurrency);
		}
	}
	else
	{
		if (TargetObject.bHaveActionWait)
		{
			const float SoundDuration = Sound->GetDuration();

			if (Sound)
			{
				UGameplayStatics::PlaySoundAtLocation(GetWorld(), Sound, GetActorLocation(), 1.0f, 1.0f, 0.0f, SoundAttenuation, TriggerSoundConcurrency);
			}

			FTimerHandle InteractionTimer;
			FTimerDelegate InteractionDel;
			InteractionDel.BindUFunction(this, FName("Interaction"), TargetObject.ObjectID, TargetObject.bInteractCall);
			GetWorldTimerManager().SetTimer(InteractionTimer, InteractionDel, SoundDuration, false);
		}
		else
		{
			if (Sound)
			{
				UGameplayStatics::PlaySoundAtLocation(GetWorld(), Sound, GetActorLocation(), 1.0f, 1.0f, 0.0f, SoundAttenuation, SoundConcurrency);
			}
			Interaction(TargetObject.ObjectID, TargetObject.bInteractCall);
		}
	}

	if (bTriggerOnce)
	{
		Destroy();
	}
}

void ABoxTrigger::TriggerInteraction(int InteractionIndex)
{
	if (TargetObjects.Num() <= InteractionIndex)
	{
		if (bTriggerOnce)
		{
			Destroy();
		}
		return;
	}
	
	int ObjectID = TargetObjects[InteractionIndex].ObjectID;
	bool bInteractCall = TargetObjects[InteractionIndex].bInteractCall;
	USoundBase* Sound = TargetObjects[InteractionIndex].Sound;

	USoundConcurrency* SoundConcurrency;

	if (TargetObject.bIsVoiceLine)
	{
		SoundConcurrency = VictorSoundConcurrency;
	}
	else
	{
		SoundConcurrency = TriggerSoundConcurrency;
	}

	if (TargetObjects[InteractionIndex].bJustSound)
	{
		const float SoundDuration = Sound->GetDuration();
		
		if (Sound)
		{
			UGameplayStatics::PlaySoundAtLocation(GetWorld(), Sound, GetActorLocation(), 1.0f, 1.0f, 0.0f, SoundAttenuation, SoundConcurrency);
		}

		FTimerHandle NextFunctionCallTimer;
		FTimerDelegate NextFunctionCallDel;
		NextFunctionCallDel.BindUFunction(this, FName("TriggerInteraction"), InteractionIndex + 1);

		GetWorldTimerManager().SetTimer(NextFunctionCallTimer, NextFunctionCallDel, SoundDuration, false);	
	}
	else
	{
		if (TargetObjects[InteractionIndex].bHaveActionWait)
		{
			const float SoundDuration = Sound->GetDuration();

			if (Sound)
			{
				UGameplayStatics::SpawnSoundAtLocation(GetWorld(), Sound, GetActorLocation(), FRotator(), 1.0f, 1.0f, 0.0f, SoundAttenuation, SoundConcurrency);
			}

			FTimerHandle InteractionTimer, NextFunctionCallTimer;
		
			FTimerDelegate ActionTimerDel;
			ActionTimerDel.BindUFunction(this, FName("Interaction"), ObjectID, bInteractCall);
		
			GetWorldTimerManager().SetTimer(InteractionTimer, ActionTimerDel, SoundDuration, false);

			FTimerDelegate NextFunctionCallDel;
			NextFunctionCallDel.BindUFunction(this, FName("TriggerInteraction"), InteractionIndex + 1);

			GetWorldTimerManager().SetTimer(NextFunctionCallTimer, NextFunctionCallDel, SoundDuration + 0.1f, false);
		}
		else
		{
			const float SoundDuration = Sound->GetDuration();

			if (Sound)
			{
				UGameplayStatics::PlaySoundAtLocation(GetWorld(), Sound, GetActorLocation(), 1.0f, 1.0f, 0.0f, SoundAttenuation, TriggerSoundConcurrency);
			}

			Interaction(ObjectID, bInteractCall);

			FTimerHandle NextFunctionCallTimer;
			FTimerDelegate NextFunctionCallDel;

			NextFunctionCallDel.BindUFunction(this, FName("TriggerInteraction"), InteractionIndex + 1);
			GetWorldTimerManager().SetTimer(NextFunctionCallTimer, NextFunctionCallDel, SoundDuration, false);
		}
	}
}

void ABoxTrigger::Interaction(const int InteractionID, const bool bInteractCall)
{
	//Gets array of every actor that has the InteractableInterface
	TArray<AActor*> InteractableActors;
	UGameplayStatics::GetAllActorsWithInterface(GetWorld(), UInteractableInterface::StaticClass(), InteractableActors);

	//Iterates through each actor and determines if it shares the same IDs that are supposed to be interacted with
	for (AActor* Actor : InteractableActors)
	{
			if (InteractionID == IInteractableInterface::Execute_GetObjectID(Actor))
			{
				IInteractableInterface::Execute_Interact(Actor, bInteractCall);
			}
	}
}

