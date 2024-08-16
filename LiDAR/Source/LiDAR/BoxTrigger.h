// Copyright 2023 Zach Nichols, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "LidarTriggerBaseClass.h"
#include "BoxTrigger.generated.h"


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
		TArray<FBaseTriggerStruct> TargetObjects;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Trigger Properties", meta = (EditCondition = "!bMultipleIDs"))
		FBaseTriggerStruct TargetObject;

	//Boolean that controls if the trigger is disabled
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Trigger")
		bool bIsDisabled;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Trigger Properties")
		bool bTriggerOnce = true;

	//Function for the overlap
	UFUNCTION()
		void OnBeginOverlap(AActor* OverlappedActor, AActor* OtherActor);
private:
	UFUNCTION()
		void BoxTriggerInteraction();
	UFUNCTION()
		void BoxTriggerInteractions(const int InteractionIndex);
	UFUNCTION()
		void BoxTriggerInteract(const int InteractionID, const bool bInteractCall);
};

