// Fill out your copyright notice in the Description page of Project Settings.
#include "LiDARHUD.h"


void ULiDARHUD::SetRadius(float CurrentRadius, float MaxRadius)
{


    float min = CurrentRadius - 5000.f;
    float max = MaxRadius - 5000.f;

    RadiusProgress->SetPercent( min / max );
}

