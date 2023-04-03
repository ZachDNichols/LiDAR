//Copyright 2023 Zach Nichols, All Rights Reserved
//TODO: Upgrade this with the functionality of BoxTrigger

#include "PressurePlate.h"
#include "Kismet/GameplayStatics.h"
#include "Interaction/InteractableInterface.h"


// Sets default values
APressurePlate::APressurePlate()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	//Sets base mesh
	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
	SetRootComponent(BaseMesh);

	//Creates moving mesh
	MoveableMesh = CreateDefaultSubobject<UMovableStaticMeshComponent>(TEXT("Movable Mesh"));
	MoveableMesh->SetupAttachment(BaseMesh);

	//Adds the box component for use when overlap
	TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Overlap Area"));
	TriggerBox->SetupAttachment(BaseMesh);

	//Adds event listeners for beginning overlap and ending overlap
	TriggerBox->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OnBeginOverlap);
	TriggerBox->OnComponentEndOverlap.AddDynamic(this, &ThisClass::OnEndOverlap);
}

void APressurePlate::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (!bIsDisabled && !bIsTriggered)
	{
		MoveableMesh->Move(true);
		bIsTriggered = true;
		
		if (bMultipleIDs && TargetObjects.Num() > 0)
		{
			PlateTriggerInteractions(true, 0);
		}
		else
		{
			PlateTriggerInteraction(true);
		}
	}
}

void APressurePlate::OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (!bIsDisabled && bResetTrigger)
	{
		MoveableMesh->Move(false);
		bIsTriggered = false;
		
		if (bMultipleIDs && TargetObjects.Num() > 0)
		{
			PlateTriggerInteractions(false, 0);
		}
		else
		{
			PlateTriggerInteraction(false);
		}
	}
}

void APressurePlate::PlateTriggerInteraction(const bool bInteractCall)
{
	USoundBase* Sound = TargetObject.Sound;

	if (TargetObject.bJustSound)
	{
		PlaySound(Sound, TargetObject.SoundAttenuation, TargetObject.SoundConcurrency);
		return;
	}

	if (TargetObject.bHaveActionWait)
	{
		float SoundDuration = 0.01f;

		if (Sound)
		{
			SoundDuration = Sound->GetDuration();
		}
		
		PlaySound(Sound, TargetObject.SoundAttenuation, TargetObject.SoundConcurrency);

		FTimerHandle InteractionTimer;
		FTimerDelegate InteractionDel;
		InteractionDel.BindUFunction(this, FName("PlateTriggerInteract"), bInteractCall, TargetObject.ObjectID);
		GetWorldTimerManager().SetTimer(InteractionTimer, InteractionDel, SoundDuration, false);

	}
	else
	{
		PlaySound(Sound, TargetObject.SoundAttenuation, TargetObject.SoundConcurrency);
		PlateTriggerInteract(bInteractCall, TargetObject.ObjectID);
	}
}

void APressurePlate::PlateTriggerInteractions(const bool bInteractCall, const int InteractionIndex)
{
	if (TargetObjects.Num() <= InteractionIndex)
	{
		return;
	}

	USoundBase* Sound = TargetObjects[InteractionIndex].Sound;

	if (TargetObjects[InteractionIndex].bJustSound)
	{
		float SoundDuration = 0.01f;

		if (Sound)
		{
			PlaySound(Sound, TargetObjects[InteractionIndex].SoundAttenuation, TargetObjects[InteractionIndex].SoundConcurrency);
			SoundDuration = Sound->GetDuration();
		}

		FTimerHandle NextFunctionCallTimer;
		FTimerDelegate NextFunctionCallDel;
		NextFunctionCallDel.BindUFunction(this, FName("PlateTriggerInteractions"), bInteractCall, InteractionIndex + 1);
		return;
	}

	if (TargetObjects[InteractionIndex].bHaveActionWait)
	{
		float SoundDuration = 0.01f;

		if (Sound)
		{
			PlaySound(Sound, TargetObjects[InteractionIndex].SoundAttenuation, TargetObjects[InteractionIndex].SoundConcurrency);
			SoundDuration = Sound->GetDuration();
		}

		FTimerHandle InteractionTimer, NextFunctionCallTimer;
		FTimerDelegate InteractionDel, NextFunctionCallDel;

		InteractionDel.BindUFunction(this, FName("PlateTriggerInteract"), bInteractCall, TargetObjects[InteractionIndex].ObjectID);
		NextFunctionCallDel.BindUFunction(this, FName("PlateTriggerInteractions"), bInteractCall, InteractionIndex + 1);

		GetWorldTimerManager().SetTimer(InteractionTimer, InteractionDel, SoundDuration, false);
		GetWorldTimerManager().SetTimer(NextFunctionCallTimer, NextFunctionCallDel, SoundDuration + 0.1f, false);
	}
	else
	{
		float SoundDuration = 0.01f;

		if (Sound)
		{
			PlaySound(Sound, TargetObjects[InteractionIndex].SoundAttenuation, TargetObjects[InteractionIndex].SoundConcurrency);
			SoundDuration = Sound->GetDuration();
		}

		PlateTriggerInteract(bInteractCall, TargetObjects[InteractionIndex].ObjectID);

		FTimerHandle NextFunctionCallTimer;
		FTimerDelegate NextFunctionCallDel;
		NextFunctionCallDel.BindUFunction(this, FName("PlateTriggerInteractions"), bInteractCall, InteractionIndex + 1);
		GetWorldTimerManager().SetTimer(NextFunctionCallTimer, NextFunctionCallDel, SoundDuration, false);
	}
}

void APressurePlate::PlateTriggerInteract(const bool bInteractCall, const int ObjectID)
{
	TArray<AActor*> InteractableActors;
	UGameplayStatics::GetAllActorsWithInterface(GetWorld(), UInteractableInterface::StaticClass(), InteractableActors);

	for (AActor* Actor : InteractableActors)
	{
		if (ObjectID == IInteractableInterface::Execute_GetObjectID(Actor))
		{
			IInteractableInterface::Execute_Interact(Actor, bInteractCall);
		}
	}
}

void APressurePlate::PlaySound(USoundBase* Sound, USoundAttenuation* SoundAttenuation, USoundConcurrency* SoundConcurrency)
{
	if (Sound)
	{
		UGameplayStatics::SpawnSoundAtLocation(GetWorld(), Sound, GetActorLocation(), FRotator(), 1.f, 1.f, 0.f, SoundAttenuation, SoundConcurrency);
	}
}
