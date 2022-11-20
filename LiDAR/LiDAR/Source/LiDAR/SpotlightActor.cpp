// Fill out your copyright notice in the Description page of Project Settings.


#include "SpotlightActor.h"


// Sets default values
ASpotlightActor::ASpotlightActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	SetRootComponent(Mesh);

	Spotlight = CreateDefaultSubobject<USpotLightComponent>(TEXT("Light"));
	Spotlight->SetupAttachment(Mesh);
}

// Called when the game starts or when spawned
void ASpotlightActor::BeginPlay()
{
	Super::BeginPlay();
	Spotlight->SetIntensity(Intensity);
}

int ASpotlightActor::GetObjectID_Implementation()
{
	return ObjectID;
}

void ASpotlightActor::Interact_Implementation(bool bInteracting)
{
	if (bInteracting)
	{
		Spotlight->SetIntensity(Intensity);
		Mesh->SetMaterial(MaterialIndex, Material1);
	}
	else if (!bInteracting)
	{
		Spotlight->SetIntensity(0.0f);
		Mesh->SetMaterial(MaterialIndex, Material2);
	}
}

