//Copyright 2023 Zach Nichols, All Rights Reserved


#include "ChangingMeshActor.h"

// Sets default values
AChangingMeshActor::AChangingMeshActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	SetRootComponent(Mesh);
}

void AChangingMeshActor::BeginPlay()
{
	Super::BeginPlay();
	DynamicMaterial = UMaterialInstanceDynamic::Create(Mesh->GetMaterial(MaterialIndex), this);
	Mesh->SetMaterial(MaterialIndex, DynamicMaterial);
}

int AChangingMeshActor::GetObjectID_Implementation()
{
	return ObjectID;
}

//If true, object will turn "on", if not object will turn off
void AChangingMeshActor::Interact_Implementation(bool bIsInteracting)
{
	//TODO: Implement fucntionalities for other types of material parameters
	for (const FMeshProperties MeshProperty : MeshProperties)
	{
		//On state
		if (bIsInteracting)
		{
			switch (MeshProperty.MaterialParameter)
			{
			case EMeshMaterialParameterType::Scalar :
				DynamicMaterial->SetScalarParameterValue(MeshProperty.ParameterName, MeshProperty.OnScalar);
				break;
			default:
				return;
			}
		}
		//Off state
		else
		{
			switch (MeshProperty.MaterialParameter)
			{
			case EMeshMaterialParameterType::Scalar :
				DynamicMaterial->SetScalarParameterValue(MeshProperty.ParameterName, MeshProperty.OffScalar);
				break;
			default:
				return;
			}
		}
	}
}

