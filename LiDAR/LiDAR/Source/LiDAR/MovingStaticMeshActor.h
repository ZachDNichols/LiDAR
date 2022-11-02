// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovableStaticMeshComponent.h"

#include "InteractableInterface.h"

#include "MovingStaticMeshActor.generated.h"

UCLASS()
class LIDAR_API AMovingStaticMeshActor : public AActor, public IInteractableInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMovingStaticMeshActor();

	virtual int GetObjectID_Implementation();
	virtual void Interact_Implementation(bool bInteracting) override;

	bool IsDisabled() const { return bIsDisabled; }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;


public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category = "Moving")
		UStaticMeshComponent* BaseMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category = "Moving")
		UMovableStaticMeshComponent* MovableMesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Moving")
		int ObjectID;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Moving")
		bool bIsDisabled;
};