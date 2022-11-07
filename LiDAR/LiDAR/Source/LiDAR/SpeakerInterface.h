// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Sound/SoundBase.h"
#include "SpeakerInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class USpeakerInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class LIDAR_API ISpeakerInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interact")
		FName GetObjectTag();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interact")
		void PlaySound(class USoundBase* Sound);
};
