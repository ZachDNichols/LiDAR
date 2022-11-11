// Fill out your copyright notice in the Description page of Project Settings.


#include "LEMONWidget.h"

void ULEMONWidget::SetRadius(float currentRadius, float maxRadius)
{
	RadiusBar->SetPercent(currentRadius / maxRadius);
}