// Copyright 2023 Zach Nichols, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interaction/InteractableInterface.h"
#include "ChangingMeshActor.generated.h"

//TODO: Implement fucntionalities for other types of material parameters

UENUM (BlueprintType)
enum class EMeshMaterialParameterType : uint8
{
	Scalar, Texture, Vector, Font, RuntimeVirtualTexture
};

USTRUCT(BlueprintType)
struct FMeshProperties
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Material")
		EMeshMaterialParameterType MaterialParameter;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Material", meta = (EditCondition = "MaterialParameter == EMeshMaterialParameterType::Scalar"))
    	float OnScalar = 100.f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Material", meta = (EditCondition = "MaterialParameter == EMeshMaterialParameterType::Scalar"))
    	float OffScalar = 0.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Material")
		FName ParameterName;
};

UCLASS()
class LIDAR_API AChangingMeshActor : public AActor, public IInteractableInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AChangingMeshActor();

	void BeginPlay() override;

	//Used for interaction
	virtual int GetObjectID_Implementation();
	virtual void Interact_Implementation(bool bInteracting) override;

	//Unique ID used for interaction
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Innteraction")
		int ObjectID;

	//Index of the material to be adjusted
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Material")
		int MaterialIndex;

	//Mesh that will have the material changed
	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Material")
		TArray<FMeshProperties> MeshProperties;

private:
	UMaterialInstanceDynamic* DynamicMaterial;
	
};
