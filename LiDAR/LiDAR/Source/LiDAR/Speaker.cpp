// Fill out your copyright notice in the Description page of Project Settings.


#include "Speaker.h"
#include "SpeakerInterface.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ASpeaker::ASpeaker()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	SetRootComponent(Mesh);

	AudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("Audio"));
	AudioComponent->SetupAttachment(Mesh);

}

// Called when the game starts or when spawned
void ASpeaker::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpeaker::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

FName ASpeaker::GetObjectTag_Implementation()
{
	return SpeakerName;
}

void ASpeaker::PlaySound_Implementation(USoundBase* Sound)
{
	if (Sound)
	{
		AudioComponent->SetSound(Sound);
		AudioComponent->Play();
	}
}

