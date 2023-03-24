// Copyright Zach Nichols

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InteractableInterface.h"
#include "ChangingMeshActor.generated.h"

UCLASS()
class LIDAR_API AChangingMeshActor : public AActor, public IInteractableInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AChangingMeshActor();

	//Used for interaction
	virtual int GetObjectID_Implementation();
	virtual void Interact_Implementation(bool bInteracting) override;


	//Unique ID used for interaction
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Interaction")
		int ObjectID;

	//Index of the material to be adjusted
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Material")
		int MaterialIndex;

	//Mesh that will have the material changed
	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* Mesh;

	//First material to be used, should be the on material
	UPROPERTY(EditDefaultsOnly)
		UMaterialInstance* Material1;

	//Second material, should be the off one
	UPROPERTY(EditDefaultsOnly)
		UMaterialInstance* Material2;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
