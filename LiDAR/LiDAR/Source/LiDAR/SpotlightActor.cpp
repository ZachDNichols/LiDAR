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

	MeshLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("Mesh Light"));
	MeshLight->SetupAttachment(Mesh);
}

// Called when the game starts or when spawned
void ASpotlightActor::BeginPlay()
{
	Super::BeginPlay();
	Spotlight->SetIntensity(Intensity);
}

// Called every frame
void ASpotlightActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

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
		MeshLight->SetIntensity(1.f);
	}
	else if (!bInteracting)
	{
		Spotlight->SetIntensity(0.0f);
		MeshLight->SetIntensity(0.f);
	}
}

