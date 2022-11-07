// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include "MovableStaticMeshComponent.h"
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
	UFUNCTION()
		void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
		void OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

private:
	void Interact(bool bIsInteracting);

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAcess = "true"), Category = "Trigger")
		UStaticMeshComponent* BaseMesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAcess = "true"), Category = "Trigger")
		UMovableStaticMeshComponent* MoveableMesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAcess = "true"), Category = "Trigger")
		USphereComponent* OverlapComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Trigger")
		bool bIsDisabled;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Trigger")
		bool bResetTrigger;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Trigger")
		TArray<int> TargetIDs;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Trigger")
		TArray<FName> TargetTags;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Audio")
		USoundBase* Sound;

private:
	bool bIsTriggered;
	bool playedSound = false;
};