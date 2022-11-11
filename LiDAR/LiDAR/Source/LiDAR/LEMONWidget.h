// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/ProgressBar.h"
#include "LEMONWidget.generated.h"

/**
 * 
 */
UCLASS()
class LIDAR_API ULEMONWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, meta = (BindWidget))
		UProgressBar* RadiusBar;

	void SetRadius(float currentRadius, float maxRadius);

	
};
