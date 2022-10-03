// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LiDARHUD.generated.h"

class UTextBlock;

/**
 * 
 */
UCLASS()
class LIDAR_API ULiDARHUD : public UUserWidget
{
	GENERATED_BODY()
    
public:
    void SetRadius(float CurrentRadius, float MaxRadius);

    UPROPERTY(EditAnywhere, meta = (BindWidget))
    UTextBlock* RadiusText;
	
};
