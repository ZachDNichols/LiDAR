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
	//Progress bar used to determine the Radius
	UPROPERTY(EditAnywhere, meta = (BindWidget))
		UProgressBar* RadiusBar;

	//Function that will set the radius
	void SetRadius(float currentRadius, float maxRadius);


};
