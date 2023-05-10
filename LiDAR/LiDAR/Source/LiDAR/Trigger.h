// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Sound/SoundBase.h"
#include "Trigger.generated.h"

UCLASS()
class LIDAR_API ATrigger : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ATrigger();

	//Array of Target IDs to be interacted with
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Trigger")
	TArray<int> TargetIDs;

	//Box used for overlap
	UPROPERTY(EditAnywhere, Category = "Trigger")
	UBoxComponent* TriggerBox;

	//Boolean that determines if the Interact() function should call with a true or false argument
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Trigger")
	bool TriggerCall;

	//Boolean that tells the trigger to wait for audio to play until after the voice line is finished
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Trigger")
	bool WaitForAudio;

	//Boolean that controls if the trigger is disabled
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Trigger")
	bool bIsDisabled;
	//The sound that can optionally be played by the trigger
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Audio")
	USoundBase* Sound;

	//Function for the overlap
	UFUNCTION()
		void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	//Boolean to be used if the object is triggered
	bool isTriggered;
	//Name of the timer if WaitForAudio is true
	FTimerHandle SoundTimer;
	void Interact();

};
