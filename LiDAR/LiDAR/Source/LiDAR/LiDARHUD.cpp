// Fill out your copyright notice in the Description page of Project Settings.
#include "LiDARHUD.h"


void ULiDARHUD::SetRadius(float CurrentRadius, float MaxRadius)
{
   /*
    if (RadiusText)
    {
        if (RadiusText->Visibility == ESlateVisibility::Hidden)
        {
            RadiusText->SetVisibility(ESlateVisibility::Visible);
        }
        RadiusText->SetText(FText::FromString("Radius: " + FString::SanitizeFloat(CurrentRadius) + "/" + FString::SanitizeFloat(MaxRadius)));
    }
    */

    float min = CurrentRadius - 500.f;
    float max = MaxRadius - 500.f;

    RadiusProgress->SetPercent( min / max );

}

