// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LEMON.generated.h"

class AFirstPersonCharacter;


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class LIDAR_API ULEMON : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	ULEMON();

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	void AttachWeapon(AFirstPersonCharacter* TargetCharacter);


private:

	AFirstPersonCharacter* Character;
		
};
