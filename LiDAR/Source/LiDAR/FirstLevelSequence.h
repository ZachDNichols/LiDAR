// Copyright 2023 Zach Nichols, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "LevelSequenceActor.h"
#include "FirstLevelSequence.generated.h"

/**
 * 
 */
UCLASS()
class LIDAR_API AFirstLevelSequence : public ALevelSequenceActor
{
	GENERATED_BODY()

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Audio")
		USoundConcurrency* VicSoundConcurrency;

private:
	class AFirstPersonCharacter* Character;
	bool bIsTriggered;
	FTimerHandle VoiceLineTimer;
};
