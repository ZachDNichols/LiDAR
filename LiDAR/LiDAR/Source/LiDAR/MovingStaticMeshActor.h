// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "InteractableInterface.h"
#include "Components/StaticMeshComponent.h"
#include "Components/TimelineComponent.h"
#include "Sound/SoundAttenuation.h"
#include "Sound/SoundBase.h"
#include "MovingStaticMeshActor.generated.h"

UENUM(BlueprintType)
enum class EActorRotationAxis : uint8
{
	Yaw, Pitch, Roll
};

UENUM(BlueprintType)
enum class EActorLocationAxis : uint8
{
	X, Y, Z
};

UENUM(BlueprintType)
enum class EActorMovementType : uint8
{
	Location, Rotation
};

UCLASS()
class LIDAR_API AMovingStaticMeshActor : public AActor, public IInteractableInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMovingStaticMeshActor();

	virtual int GetObjectID_Implementation();
	virtual void Interact_Implementation(bool bInteracting) override;

	bool IsDisabled() const { return bIsDisabled; }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Movement")
		UCurveFloat* MoveCurve;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Movement")
		EActorMovementType MovementType;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Movement", meta = (EditCondition = "MovementType == EActorMovementType::Rotation"))
		EActorRotationAxis RotateAxis;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Movement", meta = (EditCondition = "MovementType == EActorMovementType::Location"))
		EActorLocationAxis LocationAxis;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Movement")
		bool bIsReversed;

	UFUNCTION()
		void OnMove();

	UFUNCTION()
		void OnMoveFinished();

	UFUNCTION(BlueprintCallable)
		void Move(bool bTriggered);

	void PlaySoundEffect();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category = "Moving")
		UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Moving")
		int ObjectID;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Moving")
		bool bIsDisabled;

	UPROPERTY(EditDefaultsOnly, BlueprintReadonly, Category = "Audio")
		USoundAttenuation* SoundAttenuation;

	UPROPERTY(EditDefaultsOnly, BlueprintReadonly, Category = "Audio")
		USoundBase* SoundEffect;

private:
	void UpdateRotation(float CurveValue);
	void UpdateLocation(float CurveValue);
	bool bIsMoving;
	FTimeline MoveTimeline;
	bool bIsTriggered;
	bool soundPlayed;
	float PreviousTimelineValue;
};

