// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "Components/TimelineComponent.h"
#include "MovableStaticMeshComponent.generated.h"

//Used to dertmine which axis of rotation should be affected
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

//Used to determine which axis of location should be affected
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

	// Sets default values for this actor's properties
	UMovableStaticMeshComponent();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//Used to move
	UFUNCTION(BlueprintCallable)
		void Move(bool bTriggered);

	//Function to use when beginning moving
	UFUNCTION()
		void OnMove();

	//Called when move is finished
	UFUNCTION()
		void OnMoveFinished();

	bool IsMoving() const { return bIsMoving; }
	bool IsTriggered() const { return bIsTriggered; }

public:
	//Curve for how face to move/rotate
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Movement")
		UCurveFloat* MoveCurve;

	//Used to determine which kind of movement to do: rotation or location
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Movement")
		EMovementType MovementType;

	//The Axis of Rotation used
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Movement", meta = (EditCondition = "MovementType == EMovementType::Rotation"))
		ERotationAxis RotateAxis;

	//The axis of Location used
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Movement", meta = (EditCondition = "MovementType == EMovementType::Location"))
		ELocationAxis LocationAxis;

	//If to be reversed
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