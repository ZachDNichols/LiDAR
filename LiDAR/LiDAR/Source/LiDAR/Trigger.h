// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Sound/SoundBase.h"
#include "Trigger.generated.h"

UCLASS()
class LIDAR_API ATrigger : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATrigger();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Trigger")
		TArray<int> TargetIDs;
	
	UPROPERTY(EditAnywhere, Category = "Trigger")
		UBoxComponent* TriggerBox;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Trigger")
		bool TriggerCall;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Trigger")
		bool bIsDisabled;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Trigger")
		TArray<FName> TargetTags;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Audio")
		USoundBase* Sound;


	UFUNCTION()
		void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	bool isTriggered;

	void Interact(bool isInteracting);

};
