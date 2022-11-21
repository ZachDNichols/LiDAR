// Fill out your copyright notice in the Description page of Project Settings.


#include "LEMONWidget.h"

void ULEMONWidget::SetRadius(float currentRadius, float maxRadius)
{
	//Set the progress bar for the radius
	currentRadius -= 50.f;
	maxRadius -= 50.f;
	RadiusBar->SetPercent(currentRadius / maxRadius);
}