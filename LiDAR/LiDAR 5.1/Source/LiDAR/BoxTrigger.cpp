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
			BoxTriggerInteractions(0);
		}
		else
		{
			BoxTriggerInteraction();
		}
	}
}

void ABoxTrigger::BoxTriggerInteraction()
{
	USoundBase* Sound = TargetObject.Sound;
	
	if (TargetObject.bJustSound)
	{
		if (Sound)
		{
			UGameplayStatics::PlaySoundAtLocation(GetWorld(), Sound, GetActorLocation(), 1.0f, 1.0f, 0.0f, TargetObject.SoundAttenuation, TargetObject.SoundConcurrency);
		}
	}
	else
	{
		if (TargetObject.bHaveActionWait)
		{
			const float SoundDuration = Sound->GetDuration();

			if (Sound)
			{
				UGameplayStatics::PlaySoundAtLocation(GetWorld(), Sound, GetActorLocation(), 1.0f, 1.0f, 0.0f, TargetObject.SoundAttenuation, TargetObject.SoundConcurrency);
			}

			FTimerHandle InteractionTimer;
			FTimerDelegate InteractionDel;
			InteractionDel.BindUFunction(this, FName("BoxTriggerInteract"), TargetObject.ObjectID, TargetObject.bInteractCall);
			GetWorldTimerManager().SetTimer(InteractionTimer, InteractionDel, SoundDuration, false);
		}
		else
		{
			if (Sound)
			{
				UGameplayStatics::PlaySoundAtLocation(GetWorld(), Sound, GetActorLocation(), 1.0f, 1.0f, 0.0f, TargetObject.SoundAttenuation, TargetObject.SoundConcurrency);
			}
			BoxTriggerInteract(TargetObject.ObjectID, TargetObject.bInteractCall);
		}
	}

	if (bTriggerOnce)
	{
		Destroy();
	}
}

void ABoxTrigger::BoxTriggerInteractions(int InteractionIndex)
{
	UE_LOG(LogTemp, Warning, TEXT("Interaction Index: %d"), InteractionIndex);
	
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

	if (TargetObjects[InteractionIndex].bJustSound)
	{
		float SoundDuration = 0.01f;

		if (Sound)
		{
			UGameplayStatics::PlaySoundAtLocation(GetWorld(), Sound, GetActorLocation(), 1.0f, 1.0f, 0.0f, TargetObjects[InteractionIndex].SoundAttenuation, TargetObjects[InteractionIndex].SoundConcurrency);
			SoundDuration = Sound->GetDuration();
		}

		FTimerHandle NextFunctionCallTimer;
		FTimerDelegate NextFunctionCallDel;
		NextFunctionCallDel.BindUFunction(this, FName("BoxTriggerInteractions"), InteractionIndex + 1);

		GetWorldTimerManager().SetTimer(NextFunctionCallTimer, NextFunctionCallDel, SoundDuration, false);
	}
	else
	{
		if (TargetObjects[InteractionIndex].bHaveActionWait)
		{
			float SoundDuration = 0.01f;

			if (Sound)
			{
				UGameplayStatics::PlaySoundAtLocation(GetWorld(), Sound, GetActorLocation(), 1.0f, 1.0f, 0.0f, TargetObjects[InteractionIndex].SoundAttenuation, TargetObjects[InteractionIndex].SoundConcurrency);
				SoundDuration = Sound->GetDuration();
			}

			FTimerHandle InteractionTimer, NextFunctionCallTimer;
		
			FTimerDelegate ActionTimerDel;
			ActionTimerDel.BindUFunction(this, FName("BoxTriggerInteract"), ObjectID, bInteractCall);
		
			GetWorldTimerManager().SetTimer(InteractionTimer, ActionTimerDel, SoundDuration, false);

			FTimerDelegate NextFunctionCallDel;
			NextFunctionCallDel.BindUFunction(this, FName("BoxTriggerInteractions"), InteractionIndex + 1);

			GetWorldTimerManager().SetTimer(NextFunctionCallTimer, NextFunctionCallDel, SoundDuration + 0.1f, false);
		}
		else
		{
			float SoundDuration = 0.01f;

			if (Sound)
			{
				UGameplayStatics::PlaySoundAtLocation(GetWorld(), Sound, GetActorLocation(), 1.0f, 1.0f, 0.0f, TargetObjects[InteractionIndex].SoundAttenuation, TargetObjects[InteractionIndex].SoundConcurrency);
				SoundDuration = Sound->GetDuration();
			}

			BoxTriggerInteract(ObjectID, bInteractCall);

			FTimerHandle NextFunctionCallTimer;
			FTimerDelegate NextFunctionCallDel;
			NextFunctionCallDel.BindUFunction(this, FName("BoxTriggerInteractions"), InteractionIndex + 1);
			GetWorldTimerManager().SetTimer(NextFunctionCallTimer, NextFunctionCallDel, SoundDuration, false);
		}
	}
}

void ABoxTrigger::BoxTriggerInteract(const int InteractionID, const bool bInteractCall)
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

