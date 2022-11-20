// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SpotLightComponent.h"
#include "Components/PointLightComponent.h"
#include "Materials/MaterialInstance.h"
#include "InteractableInterface.h"
#include "SpotlightActor.generated.h"



UCLASS()
class LIDAR_API ASpotlightActor : public AActor, public IInteractableInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpotlightActor();

	UPROPERTY(VisibleAnywhere, Category = "Lighting")
		USpotLightComponent* Spotlight;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Material")
		UMaterialInstance* Material1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Material")
		UMaterialInstance* Material2;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Material")
		int MaterialIndex;

	UPROPERTY(VisibleAnywhere, Category = mesh)
		UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Interaction")
		int ObjectID;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Lighting")
		float Intensity;

	virtual int GetObjectID_Implementation();
	virtual void Interact_Implementation(bool bInteracting) override;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:


};
