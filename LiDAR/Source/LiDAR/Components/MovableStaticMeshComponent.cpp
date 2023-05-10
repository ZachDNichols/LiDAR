// Fill out your copyright notice in the Description page of Project Settings.


#include "MovableStaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"

UMovableStaticMeshComponent::UMovableStaticMeshComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void UMovableStaticMeshComponent::BeginPlay()
{
	Super::BeginPlay();

	//If there is a move curve, it gets set up
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

// Called every frame
void UMovableStaticMeshComponent::TickComponent(float DeltaTime, ELevelTick Tick, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, Tick, ThisTickFunction);

	//If object is moving, the timeline will be updated to move the object
	if (bIsMoving)
	{
		MoveTimeline.TickTimeline(DeltaTime);
	}
}

//Controls moving the object and playing sound
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

//Adjust curves when moving
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

//Updates the rotation depending which one is selected
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


//Updates location based on location axis selected
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