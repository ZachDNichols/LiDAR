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
		void IncreaseRadius();

	UFUNCTION(BlueprintCallable, Category = "Weapon")
		void DecreaseRadius();

	UPROPERTY(EditAnywhere)
		class ULiDARHUD* LEMONHUD;

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
	float increment = 100.f;
	float currentRadius = 1000.f;
	float minRadius = 5000.f;
	float maxRadius = 15000.f;
	UCameraComponent* Camera;

protected:
	/** Ends gameplay for this component. */
	UFUNCTION()
		virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
};

