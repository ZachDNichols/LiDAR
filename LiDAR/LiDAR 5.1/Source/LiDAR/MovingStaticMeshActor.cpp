// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingStaticMeshActor.h"
#include "Components/MovableStaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AMovingStaticMeshActor::AMovingStaticMeshActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BaseMesh"));
	RootComponent = BaseMesh;

	MovingMesh = CreateDefaultSubobject<UMovableStaticMeshComponent>(TEXT("MovingMesh"));
	MovingMesh->SetupAttachment(RootComponent);
}

void AMovingStaticMeshActor::Interact_Implementation(bool bInteracting)
{
	if (!bIsDisabled)
	{
		MovingMesh->Move(bInteracting);
		PlaySoundEffect();
	}
}

void AMovingStaticMeshActor::PlaySoundEffect()
{
	if (SoundEffect)
	{
		if (SoundAttenuation)
		{
			UGameplayStatics::PlaySoundAtLocation(GetWorld(), SoundEffect, GetActorLocation(), 1.f, 1.f, 0.f, SoundAttenuation);
		}
		else
		{
			UGameplayStatics::PlaySoundAtLocation(GetWorld(), SoundEffect, GetActorLocation(), 1.f, 1.f);
		}
	}
}

