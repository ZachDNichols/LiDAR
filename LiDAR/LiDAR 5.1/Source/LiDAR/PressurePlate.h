//Copyright 2023 Zach Nichols, All Rights Reserved

#pragma once
//TODO: Upgrade this with the functionality of BoxTrigger

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "Components/MovableStaticMeshComponent.h"
#include "PressurePlate.generated.h"

USTRUCT(BlueprintType)
struct FPlateObject
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Object")
	bool bJustSound = false;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Object", meta = (EditCondition = "!bJustSound"))
	int ObjectID;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Triggered Audio")
	USoundBase* Sound;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Triggered Audio", meta = (EditCondition = "!bJustSound"))
	bool bHaveActionWait = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Triggered Audio")
	bool bIsVoiceLine = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Triggered Audio")
	bool bTriggerOnce;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Triggered Audio")
	USoundAttenuation* SoundAttenuation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Triggered Audio")
	USoundConcurrency* SoundConcurrency;
};

UCLASS()
class LIDAR_API APressurePlate : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APressurePlate();
	
	//Called when overlap begins
	UFUNCTION()
		void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	//Called when overlap ends
	UFUNCTION()
		void OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	
	//Nonmoving base mesh
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Trigger")
	UStaticMeshComponent* BaseMesh;

	//The mesh that moves when the object is interacted with
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Trigger")
	UMovableStaticMeshComponent* MoveableMesh;

	//The component used for overlap, might be better to check for OnCollisionEnter with the MoveingStaticMesh component instead
	UPROPERTY(EditAnywhere, Category = "Trigger")
	UBoxComponent* TriggerBox;

	//Determines if trigger is disabled
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Trigger")
	bool bIsDisabled;

	//Determines if OnEndOverlap the object should reverse
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Trigger")
	bool bResetTrigger;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Trigger")
	bool bMultipleIDs = false;

	//Array used to determine which objects to interact with
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Trigger", meta = (EditCondition = "bMultipleIDs"))
	TArray<FPlateObject> TargetObjects;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Trigger", meta = (EditCondition = "!bMultipleIDs"))
	FPlateObject TargetObject;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Audio")
	USoundBase* PressurePlateSound;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Audio")
	USoundAttenuation* PressurePlateAttenuation;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Audio")
	USoundConcurrency* PressurePlateConcurrency;

	
private:
	bool bIsTriggered;
	UFUNCTION()
		void PlateTriggerInteraction(const bool bInteractCall);
	UFUNCTION()
		void PlateTriggerInteractions(const bool bInteractCall, const int InteractionIndex);
	UFUNCTION()
		void PlateTriggerInteract(const bool bInteractCall, const int ObjectID);
	
	void PlaySound(USoundBase* Sound, USoundAttenuation* SoundAttenuation, USoundConcurrency* SoundConcurrency);

};
