// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "Components/TimelineComponent.h"
#include "MovableStaticMeshComponent.generated.h"


UENUM(BlueprintType)
enum class ERotationAxis : uint8
{
	Yaw, Pitch, Roll
};

UENUM(BlueprintType)
enum class ELocationAxis : uint8
{
	X, Y, Z
};

UENUM(BlueprintType)
enum class EMovementType : uint8
{
	Location, Rotation
};

/**
 *
 */
UCLASS()
class LIDAR_API UMovableStaticMeshComponent : public UStaticMeshComponent
{
	GENERATED_BODY()

public:

	UMovableStaticMeshComponent();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
		void Move(bool bTriggered);

	UFUNCTION()
		void OnMove();

	UFUNCTION()
		void OnMoveFinished();

	bool IsMoving() const { return bIsMoving; }
	bool IsTriggered() const { return bIsTriggered; }

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Movement")
		UCurveFloat* MoveCurve;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Movement")
		EMovementType MovementType;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Movement", meta = (EditCondition = "MovementType == EMovementType::Rotation"))
		ERotationAxis RotateAxis;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Movement", meta = (EditCondition = "MovementType == EMovementType::Location"))
		ELocationAxis LocationAxis;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Movement")
		bool bIsReversed;

private:
	void UpdateRotation(float CurveValue);
	void UpdateLocation(float CurveValue);

private:
	bool bIsMoving;
	FTimeline MoveTimeline;

	bool bIsTriggered;
	float PreviousTimelineValue;
};