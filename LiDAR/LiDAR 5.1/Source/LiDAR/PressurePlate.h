// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "Components/MovableStaticMeshComponent.h"
#include "PressurePlate.generated.h"

UCLASS()
class LIDAR_API APressurePlate : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APressurePlate();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	//Called when overlap begins
	UFUNCTION()
		void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	//Called when overlap ends
	UFUNCTION()
		void OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

private:
	//Calls each object with matching IDs to Interact
	void Interact(bool bIsInteracting);

public:
	//Nonmoving base mesh
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Trigger")
		UStaticMeshComponent* BaseMesh;

	//The mesh that moves when the object is interacted with
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Trigger")
		UMovableStaticMeshComponent* MoveableMesh;

	//The component used for overlap, might be better to check for OnCollisionEnter with the MoveingStaticMesh component instead
	UPROPERTY(EditAnywhere, Category = "Trigger")
		UBoxComponent* TriggerBox;

	//Determines if trigger is disabled
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Trigger")
		bool bIsDisabled;

	//Determines if OnEndOverlap the object should reverse
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Trigger")
		bool bResetTrigger;

	//Array used to determine which objects to interact with
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Trigger")
		TArray<int> TargetIDs;

	//Sound played when interacting with object
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Audio")
		USoundBase* Sound;

private:
	bool bIsTriggered;
	bool playedSound = false;
};