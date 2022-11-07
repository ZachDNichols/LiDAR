// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Sound/SoundBase.h"
#include "SpeakerInterface.h"
#include "Components/AudioComponent.h"
#include "Speaker.generated.h"

UCLASS()
class LIDAR_API ASpeaker : public AActor, public ISpeakerInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpeaker();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Interaction")
		FName SpeakerName = "Speaker";

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Audio")
		UAudioComponent* AudioComponent;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Mesh")
		UStaticMeshComponent* Mesh;

	virtual FName GetObjectTag_Implementation();
	virtual void PlaySound_Implementation(USoundBase* Sound) override;
		

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
