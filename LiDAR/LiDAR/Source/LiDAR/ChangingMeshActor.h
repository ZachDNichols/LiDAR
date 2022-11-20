// Copyright Zach Nichols

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InteractableInterface.h"
#include "Materials/MaterialInstance.h"
#include "ChangingMeshActor.generated.h"

UCLASS()
class LIDAR_API AChangingMeshActor : public AActor, public IInteractableInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AChangingMeshActor();

	virtual int GetObjectID_Implementation();
	virtual void Interact_Implementation(bool bInteracting) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Innteraction")
		int ObjectID;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Material")
		int MaterialIndex;

	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* Mesh;

	UPROPERTY(EditDefaultsOnly)
		UMaterialInstance* Material1;

	UPROPERTY(EditDefaultsOnly)
		UMaterialInstance* Material2;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
