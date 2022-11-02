// Fill out your copyright notice in the Description page of Project Settings.


#include "MovableStaticMeshComponent.h"

UMovableStaticMeshComponent::UMovableStaticMeshComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UMovableStaticMeshComponent::BeginPlay()
{
	Super::BeginPlay();

	if (MoveCurve)
	{
		FOnTimelineFloat TimelineCallback;
		FOnTimelineEventStatic TimelineFinishCallback;

		TimelineCallback.BindUFunction(this, FName("OnMove"));
		TimelineFinishCallback.BindUFunction(this, FName("OnMoveFinished"));

		MoveTimeline.AddInterpFloat(MoveCurve, TimelineCallback);
		MoveTimeline.SetTimelineFinishedFunc(TimelineFinishCallback);
	}
}

void UMovableStaticMeshComponent::TickComponent(float DeltaTime, ELevelTick Tick, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, Tick, ThisTickFunction);

	if (bIsMoving)
	{
		MoveTimeline.TickTimeline(DeltaTime);
	}
}

void UMovableStaticMeshComponent::Move(bool bTriggered)
{
	bIsTriggered = bTriggered;

	if (bTriggered)
	{
		if (MoveTimeline.IsReversing())
		{
			MoveTimeline.Play();
		}
		else
		{
			MoveTimeline.PlayFromStart();
		}
	}
	else
	{
		MoveTimeline.Reverse();
	}

	bIsMoving = true;
}

void UMovableStaticMeshComponent::OnMove()
{
	const float PlaybackPosition = MoveTimeline.GetPlaybackPosition();
	float CurveValue = MoveCurve->GetFloatValue(PlaybackPosition);

	if (bIsReversed)
	{
		CurveValue = -CurveValue;
	}

	const float AdjustedValue = CurveValue - PreviousTimelineValue;

	if (MovementType == EMovementType::Location)
	{
		UpdateLocation(AdjustedValue);
	}
	else if (MovementType == EMovementType::Rotation)
	{
		UpdateRotation(AdjustedValue);
	}

	PreviousTimelineValue = CurveValue;
}

void UMovableStaticMeshComponent::OnMoveFinished()
{
	bIsMoving = false;
}

void UMovableStaticMeshComponent::UpdateRotation(float CurveValue)
{
	FRotator NewRotation = GetRelativeRotation();

	switch (RotateAxis)
	{
	case ERotationAxis::Pitch:
		NewRotation.Pitch += CurveValue;
		break;
	case ERotationAxis::Roll:
		NewRotation.Roll += CurveValue;
		break;
	case ERotationAxis::Yaw:
		NewRotation.Yaw += CurveValue;
		break;
	default:
		break;
	}

	SetRelativeRotation(NewRotation);
}


void UMovableStaticMeshComponent::UpdateLocation(float CurveValue)
{
	FVector NewLocation = GetRelativeLocation();

	switch (LocationAxis)
	{
	case ELocationAxis::X:
		NewLocation.X += CurveValue;
		break;
	case ELocationAxis::Y:
		NewLocation.Y += CurveValue;
		break;
	case ELocationAxis::Z:
		NewLocation.Z += CurveValue;
		break;
	default:
		break;
	}

	SetRelativeLocation(NewLocation);
}