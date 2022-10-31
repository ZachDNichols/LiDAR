// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LEMON.generated.h"

class AFirstPersonCharacter;
class TimerManager;
class UCameraComponent;

UCLASS(Blueprintable, BlueprintType, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class LIDAR_API ULEMON : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	ULEMON();

	UFUNCTION(BlueprintCallable, Category = "Weapon")
		void AttachWeapon(AFirstPersonCharacter* TargetCharacter);

	UFUNCTION(BlueprintCallable, Category = "Weapon")
		void Fire();

	UFUNCTION(BlueprintCallable, Category = "Weapon")
		void EndFire();

	UFUNCTION(BlueprintCallable, Category = "Weapon")
		void ChangeRadius();

	UPROPERTY(EditAnywhere)
		TSubclassOf<class ALaser> LaserBP;

	UPROPERTY()
		class ALaser* LaserBeam;

	UPROPERTY(EditAnywhere)
		TSubclassOf<class ADot> DotBP;

	UPROPERTY()
		class ADot* Dot;

private:
	AFirstPersonCharacter* Character;
	FTimerHandle LaserTimer;
	float currentRadius;
	UCameraComponent* Camera;

protected:
	/** Ends gameplay for this component. */
	UFUNCTION()
		virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
};

