// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "FirstPersonPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class LIDAR_API AFirstPersonPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	virtual void SetupInputComponent() override;

	UPROPERTY()
		class UInputMappingContext* MappingContext;

	UPROPERTY()
		class UInputAction* MoveAction;

	UPROPERTY()
		class UInputAction* JumpAction;

	UPROPERTY()
		class UInputAction* LookAction;

	UPROPERTY()
		class UInputAction* CrouchAction;

	UPROPERTY()
		class UInputAction* ShootAction;

	UPROPERTY()
		class UInputAction* IncreaseScrollAction;

	UPROPERTY()
		class UInputAction* DecreaseScrollAction;

	UPROPERTY()
		class UInputAction* GrabObjectAction;
    
    UPROPERTY()
        class UInputAction* PauseGameAction;
};
