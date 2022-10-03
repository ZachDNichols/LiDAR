// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Runtime/UMG/Public/UMG.h"
#include "LiDARHUD.generated.h"

class UTextBlock;

/**
 * 
 */
UCLASS()
class LIDAR_API ULiDARHUD : public UUserWidget
{
public:
	GENERATED_BODY()
    
    void SetRadius(float CurrentRadius, float MaxRadius);

   /* UPROPERTY(EditAnywhere, meta = (BindWidget))
    UTextBlock* RadiusText; */

    UPROPERTY(EditAnywhere, meta = (BindWidget))
    UProgressBar* RadiusProgress;
	
};
