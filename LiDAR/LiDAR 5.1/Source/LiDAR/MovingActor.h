// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interaction/InteractableInterface.h"
#include "Components/TimelineComponent.h"
#include "Sound/SoundAttenuation.h"
#include "MovingActor.generated.h"

//Used to dertmine which axis of rotation should be affected
UENUM(BlueprintType)
enum class EActorRotationAxis : uint8
{
	Yaw, Pitch, Roll
};

//Used to determine which axis of location should be affected
UENUM(BlueprintType)
enum class EActorLocationAxis : uint8
{
	X, Y, Z
};

//Used to determine of object should move on rotation and location
UENUM(BlueprintType)
enum class EActorMovementType : uint8
{
	Location, Rotation
};

UCLASS()
class LIDAR_API AMovingActor : public AActor, public IInteractableInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMovingActor();

	//Implementations for how to get ObjectID and how to interact
	virtual int GetObjectID_Implementation();
	virtual void Interact_Implementation(bool bInteracting) override;

	bool IsDisabled() const { return bIsDisabled; }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Curve for how face to move/rotate
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Movement")
		UCurveFloat* MoveCurve;

	//Used to determine which kind of movement to do: rotation or location
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Movement")
		EActorMovementType MovementType;

	//The Axis of Rotation used
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Movement", meta = (EditCondition = "MovementType == EActorMovementType::Rotation"))
		EActorRotationAxis RotateAxis;

	//The axis of Location used
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Movement", meta = (EditCondition = "MovementType == EActorMovementType::Location"))
		EActorLocationAxis LocationAxis;

	//If to be reversed
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Movement")
		bool bIsReversed;

	//Function to use when beginning moving
	UFUNCTION()
		void OnMove();

	//Called when move is finished
	UFUNCTION()
		void OnMoveFinished();

	//Used to move
	UFUNCTION(BlueprintCallable)
		void Move(bool bTriggered);

	//Used to play sound effect when moving
	void PlaySoundEffect();

	//Mesh that will move
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category = "Moving")
		UStaticMeshComponent* Mesh;

	//Object ID to be used for interaction
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Moving")
		int ObjectID;

	//Determines if object is disabled
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Moving")
		bool bIsDisabled;

	//SoundAttenuation used for sound effects played, to allow for 3D sounding audio
	UPROPERTY(EditDefaultsOnly, BlueprintReadonly, Category = "Audio")
		USoundAttenuation* SoundAttenuation;

	//Sound effect that could be played
	UPROPERTY(EditDefaultsOnly, BlueprintReadonly, Category = "Audio")
		USoundBase* SoundEffect;

private:
	//Functions used for updating the rotation/location
	void UpdateRotation(float CurveValue);
	void UpdateLocation(float CurveValue);
	//Used to determine if object is moving
	bool bIsMoving;
	FTimeline MoveTimeline;
	bool bIsTriggered;
	bool bSoundPlayed;
	float PreviousTimelineValue;
};

