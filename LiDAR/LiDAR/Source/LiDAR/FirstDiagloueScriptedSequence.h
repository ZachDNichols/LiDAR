// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Sound/SoundAttenuation.h"
#include "FirstDiagloueScriptedSequence.generated.h"

UCLASS()
class LIDAR_API AFirstDiagloueScriptedSequence : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFirstDiagloueScriptedSequence();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	//Uses similar code to Trigger or PressurePlate to create an opening scripted sequence
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Audio")
		USoundBase* VoiceLine;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Trigger")
		bool bIsDisabled;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Trigger")
		TArray<int> TargetIDs;

	UFUNCTION(BlueprintCallable, Category = "Voice Function")
		void Interact();

	UFUNCTION(BlueprintCallable, Category = "Voice Function")
		void PlayVoiceLine();

	UPROPERTY(EditDefaultsOnly, BlueprintReadonly, Category = "Audio")
		USoundAttenuation* SoundAttenuation;


private:

	class AFirstPersonCharacter* Character;
	bool bIsTriggered;
	FTimerHandle VoiceLineTimer;
};
