// Copyright 2023 Zach Nichols, All Rights Reserved


#include "MovingActor.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
AMovingActor::AMovingActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(GetRootComponent());
	SetRootComponent(Mesh);
}

// Called when the game starts or when spawned
void AMovingActor::BeginPlay()
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
void AMovingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//If object is moving, the timeline will be updated to move the object
	if (bIsMoving)
	{
		MoveTimeline.TickTimeline(DeltaTime);
	}
}

//Returns object ID
int AMovingActor::GetObjectID_Implementation()
{
	return ObjectID;
}

void AMovingActor::Interact_Implementation(bool bInteracting)
{
	//If interaction is triggered and not disabled, moving will begin
	if (!bIsDisabled)
	{
		Move(bInteracting);
	}
}

//Controls moving the object and playing sound
void AMovingActor::Move(bool bTriggered)
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
		if (!bSoundPlayed)
		{
			bSoundPlayed = true;
			PlaySoundEffect();
		}
	}
	else
	{
		MoveTimeline.Reverse();

		if (bSoundPlayed)
		{
			bSoundPlayed = false;
			PlaySoundEffect();
		}
	}

	bIsMoving = true;
}

//Plays the sound effect
void AMovingActor::PlaySoundEffect()
{
	if (SoundEffect)
	{
		if (SoundAttenuation)
		{
			UGameplayStatics::PlaySoundAtLocation(GetWorld(), SoundEffect, GetActorLocation(), 1.f, 1.f, 0.f, SoundAttenuation);
		}
		else
		{
			UGameplayStatics::PlaySoundAtLocation(GetWorld(), SoundEffect, GetActorLocation(), 1.f, 1.f);
		}
	}
}

//Adjust curves when moving
void AMovingActor::OnMove()
{
	const float PlaybackPosition = MoveTimeline.GetPlaybackPosition();
	float CurveValue = MoveCurve->GetFloatValue(PlaybackPosition);

	if (bIsReversed)
	{
		CurveValue = -CurveValue;
	}

	const float AdjustedValue = CurveValue - PreviousTimelineValue;

	if (MovementType == EActorMovementType::Location)
	{
		UpdateLocation(AdjustedValue);
	}
	else if (MovementType == EActorMovementType::Rotation)
	{
		UpdateRotation(AdjustedValue);
	}

	PreviousTimelineValue = CurveValue;
}

void AMovingActor::OnMoveFinished()
{
	bIsMoving = false;
}

//Updates the rotation depending which one is selected
void AMovingActor::UpdateRotation(float CurveValue)
{
	FRotator NewRotation = GetActorRotation();

	switch (RotateAxis)
	{
	case EActorRotationAxis::Pitch:
		NewRotation.Pitch += CurveValue;
		break;
	case EActorRotationAxis::Roll:
		NewRotation.Roll += CurveValue;
		break;
	case EActorRotationAxis::Yaw:
		NewRotation.Yaw += CurveValue;
		break;
	default:
		break;
	}

	SetActorRotation(NewRotation);
}

//Updates location based on location axis selected
void AMovingActor::UpdateLocation(float CurveValue)
{
	FVector NewLocation = GetActorLocation();

	switch (LocationAxis)
	{
	case EActorLocationAxis::X:
		NewLocation.X += CurveValue;
		break;
	case EActorLocationAxis::Y:
		NewLocation.Y += CurveValue;
		break;
	case EActorLocationAxis::Z:
		NewLocation.Z += CurveValue;
		break;
	default:
		break;
	}

	SetActorLocation(NewLocation);
}