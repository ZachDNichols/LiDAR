// Copyright Zach Nichols


#include "ChangingMeshActor.h"

// Sets default values
AChangingMeshActor::AChangingMeshActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	SetRootComponent(Mesh);
}

// Called when the game starts or when spawned
void AChangingMeshActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AChangingMeshActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

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
		Mesh->SetMaterial(MaterialIndex, Material1);
	}
	else if (!bIsInteracting)
	{
		Mesh->SetMaterial(MaterialIndex, Material2);
	}
}

