// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "FirstPersonCharacter.h"
#include "LiDARGameModeBase.generated.h"

/**
 * 
 */
//DEFAULT GAME TO BE MODE USED
UCLASS()
class LIDAR_API ALiDARGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	ALiDARGameModeBase();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Character")
		TSubclassOf<class AFirstPersonCharacter> Character;
};
