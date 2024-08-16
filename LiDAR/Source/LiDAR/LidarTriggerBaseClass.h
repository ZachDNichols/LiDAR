// Copyright 2023 Zach Nichols, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "LidarTriggerBaseClass.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FBaseTriggerStruct
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
    
    	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Triggered Audio")
    	USoundAttenuation* SoundAttenuation;
    
    	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Triggered Audio")
    	USoundConcurrency* SoundConcurrency;
};

class LIDAR_API LidarTriggerBaseClass
{
public:
	LidarTriggerBaseClass();
	~LidarTriggerBaseClass();
};
