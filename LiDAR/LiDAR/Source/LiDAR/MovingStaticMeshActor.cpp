// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingStaticMeshActor.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
AMovingStaticMeshActor::AMovingStaticMeshActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(GetRootComponent());
	SetRootComponent(Mesh);
}

// Called when the game starts or when spawned
void AMovingStaticMeshActor::BeginPlay()
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

// Called every frame
void AMovingStaticMeshActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bIsMoving)
	{
		MoveTimeline.TickTimeline(DeltaTime);
	}
}

int AMovingStaticMeshActor::GetObjectID_Implementation()
{
	return ObjectID;
}

void AMovingStaticMeshActor::Interact_Implementation(bool bInteracting)
{
	if (!bIsDisabled)
	{
		Move(bInteracting);
	}
}

void AMovingStaticMeshActor::Move(bool bTriggered)
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
		if (!soundPlayed)
		{
			soundPlayed = true;
			PlaySoundEffect();
		}
	}
	else
	{
		MoveTimeline.Reverse();

		if (soundPlayed)
		{
			soundPlayed = false;
			PlaySoundEffect();
		}
	}

	bIsMoving = true;
}

void AMovingStaticMeshActor::PlaySoundEffect()
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

void AMovingStaticMeshActor::OnMove()
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

void AMovingStaticMeshActor::OnMoveFinished()
{
	bIsMoving = false;
}

void AMovingStaticMeshActor::UpdateRotation(float CurveValue)
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


void AMovingStaticMeshActor::UpdateLocation(float CurveValue)
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