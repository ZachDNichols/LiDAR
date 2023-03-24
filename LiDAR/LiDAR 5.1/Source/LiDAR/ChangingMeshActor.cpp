// Copyright Zach Nichols


#include "ChangingMeshActor.h"

// Sets default values
AChangingMeshActor::AChangingMeshActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	SetRootComponent(Mesh);
}

int AChangingMeshActor::GetObjectID_Implementation()
{
	return ObjectID;
}

//If true, object will turn "on", if not object will turn off
void AChangingMeshActor::Interact_Implementation(bool bIsInteracting)
{
	if (bIsInteracting)
	{
		DynamicMaterial->SetScalarParameterValue(TEXT("Emissive"), 0.f);
	}
	else
	{
		DynamicMaterial->SetScalarParameterValue(TEXT("Emissive"), 5.f);
	}
}

void AChangingMeshActor::BeginPlay()
{
	Super::BeginPlay();

	DynamicMaterial = UMaterialInstanceDynamic::Create(Mesh->GetMaterial(MaterialIndex), this);
	Mesh->SetMaterial(MaterialIndex, DynamicMaterial);
	DynamicMaterial->SetScalarParameterValue(TEXT("Emissive"), 5.f);
}

