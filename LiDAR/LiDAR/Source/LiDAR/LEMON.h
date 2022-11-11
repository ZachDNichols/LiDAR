// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LEMONWidget.h"
#include "GameFramework/Actor.h"
#include "Components/WidgetComponent.h"
#include "Animation/AnimSequence.h"
#include "LEMON.generated.h"

class AFirstPersonCharacter;
class TimerManager;
class UCameraComponent;

UCLASS(Blueprintable, BlueprintType, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class LIDAR_API ALEMON : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	ALEMON();

	UFUNCTION(BlueprintCallable)
		void AttachWeapon(AFirstPersonCharacter* TargetCharacter);

	UFUNCTION(BlueprintCallable, Category = "Weapon")
		void Fire();

	UFUNCTION(BlueprintCallable, Category = "Weapon")
		void EndFire();

	UFUNCTION()
		void IncreaseRadius();

	UFUNCTION()
		void DecreaseRadius();

	UPROPERTY(EditAnywhere)
		TSubclassOf<class ALaser> LaserBP;

	UPROPERTY()
		class ALaser* LaserBeam;

	UPROPERTY(EditAnywhere)
		TSubclassOf<class ADot> DotBP;

	UPROPERTY()
		class ADot* Dot;

	UPROPERTY(EditAnywhere, Category = "Widget")
		TSubclassOf<class ULEMONWidget> LemonWidget_BP;

	UPROPERTY()
		ULEMONWidget* LemonWidget;

	UPROPERTY(VisibleAnywhere)
		UWidgetComponent* WidgetComponent;

	UPROPERTY(VisibleAnywhere, Category = Mesh)
		class USkeletalMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere, Category = "PickUp")
		class UWeaponPickupComponent* PickUp;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SFX")
		USoundBase* Sound;

	/** Ends gameplay for this component. */
	UFUNCTION(BlueprintCallable)
		virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
private:
	AFirstPersonCharacter* Character;
	FTimerHandle LaserTimer;
	FTimerHandle LaserSFXTimer;
	float currentRadius = 200.f;
	float increment = 200.f;
	float minRadius = 200.f;
	float maxRadius = 2000.f;
	UCameraComponent* Camera;
};

