// Copyright 2023 Zach Nichols, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interaction/InteractableInterface.h"
#include "MovingStaticMeshActor.generated.h"

UCLASS()
class LIDAR_API AMovingStaticMeshActor : public AActor, public IInteractableInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingStaticMeshActor();

	//Implementations for how to get ObjectID and how to interact
	virtual int GetObjectID_Implementation() { return ObjectID; };
	virtual void Interact_Implementation(bool bInteracting) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Mesh")
		UStaticMeshComponent* BaseMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Mesh")
		class UMovableStaticMeshComponent* MovingMesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Moving")
		bool bIsDisabled = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Moving")
		int ObjectID = 0;

	//SoundAttenuation used for sound effects played, to allow for 3D sounding audio
	UPROPERTY(EditDefaultsOnly, BlueprintReadonly, Category = "Audio")
		USoundAttenuation* SoundAttenuation;

	//Sound effect that could be played
	UPROPERTY(EditDefaultsOnly, BlueprintReadonly, Category = "Audio")
		USoundBase* SoundEffect;

private:
	void PlaySoundEffect();
	bool bSoundPlayed = false;
};
