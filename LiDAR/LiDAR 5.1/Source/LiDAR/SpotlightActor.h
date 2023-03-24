// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SpotLightComponent.h"
#include "Interaction/InteractableInterface.h"
#include "SpotlightActor.generated.h"



UCLASS()
//Class inherits from AActor, as well as IInteractableInterface to allow things like Triggers or PressurePlates to interact
class LIDAR_API ASpotlightActor : public AActor, public IInteractableInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASpotlightActor();

	//Mesh used for the light
	UPROPERTY(VisibleAnywhere, Category = "Lighting")
		USpotLightComponent* Spotlight;

	//Default, emmissive material
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Material")
		UMaterialInstance* Material1;

	//Non emmsive, secondary material
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Material")
		UMaterialInstance* Material2;

	//Int used to determine which material index to change
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Material")
		int MaterialIndex;

	//Mesh used for the light
	UPROPERTY(VisibleAnywhere, Category = mesh)
		UStaticMeshComponent* Mesh;

	//Object ID used for interaction
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Interaction")
		int ObjectID;

	//Float for intensity of light
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Lighting")
		float Intensity;

	//Used to return to value of the object ID
	virtual int GetObjectID_Implementation();
	//Implementation of how *this* object interacts
	virtual void Interact_Implementation(bool bInteracting) override;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
