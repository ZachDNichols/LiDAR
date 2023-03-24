// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "BoxTrigger.generated.h"

USTRUCT(BlueprintType)
struct FTargetObject
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Object")
		bool bJustSound = false;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Object", meta = (EditCondition = "!bJustSound"))
		int ObjectID;

	//Used for determining what the interaction will be called with
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Object", meta = (EditCondition = "!bJustSound"))
		bool bInteractCall = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Triggered Audio")
	USoundBase* Sound;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Triggered Audio", meta = (EditCondition = "!bJustSound"))
	bool bHaveActionWait = false;
};

UCLASS()
class LIDAR_API ABoxTrigger : public ATriggerBox
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABoxTrigger();

	//Properties for the trigger
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Trigger Properties")
		bool bMultipleIDs = false;
	
	//Target IDs that can be interacted with
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Trigger Properties", meta = (EditCondition = "bMultipleIDs"))
		TArray<FTargetObject> TargetObjects;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Trigger Properties", meta = (EditCondition = "!bMultipleIDs"))
		FTargetObject TargetObject;

	//Boolean that controls if the trigger is disabled
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Trigger")
		bool bIsDisabled;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Trigger Properties")
		USoundAttenuation* SoundAttenuation;

	//Function for the overlap
	UFUNCTION()
		void OnBeginOverlap(AActor* OverlappedActor, AActor* OtherActor);
private:
	//Boolean to be used if the object is triggered
	bool isTriggered;
	void TriggerInteraction();
	void TriggerInteraction(const int InteractionIndex);
	void Interaction(const int InteractionID, const bool bInteractCall);
};

