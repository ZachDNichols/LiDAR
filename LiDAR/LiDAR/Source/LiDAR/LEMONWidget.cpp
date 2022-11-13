// Fill out your copyright notice in the Description page of Project Settings.


#include "LEMONWidget.h"

void ULEMONWidget::SetRadius(float currentRadius, float maxRadius)
{
	currentRadius -= 50.f;
	maxRadius -= 50.f;
	RadiusBar->SetPercent(currentRadius / maxRadius);
}