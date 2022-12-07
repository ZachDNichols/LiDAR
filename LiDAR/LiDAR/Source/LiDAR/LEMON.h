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

	//Function for attaching LEMON to player
	UFUNCTION(BlueprintCallable)
		void AttachWeapon(AFirstPersonCharacter* TargetCharacter);

	//Function called when firing
	UFUNCTION(BlueprintCallable, Category = "Weapon")
		void Fire();

	//Function called for not firing
	UFUNCTION(BlueprintCallable, Category = "Weapon")
		void EndFire();

	//Function used to increase the radius
	UFUNCTION()
		void IncreaseRadius();

	//Function used to decrease the radius
	UFUNCTION()
		void DecreaseRadius();

	//Laser class
	UPROPERTY(EditAnywhere)
		TSubclassOf<class ALaser> LaserBP;

	//Laser that will be created
	UPROPERTY()
		class ALaser* LaserBeam;

	//Dot class
	UPROPERTY(EditAnywhere)
		TSubclassOf<class ADot> DotBP;

	//Dot that will be created
	UPROPERTY()
		class ADot* Dot;

	//LemonWidget class
	UPROPERTY(EditAnywhere, Category = "Widget")
		TSubclassOf<class ULEMONWidget> LemonWidget_BP;

	//Pointer for widget that will be created
	UPROPERTY()
		ULEMONWidget* LemonWidget;

	//Component for LEMON to sit in
	UPROPERTY(VisibleAnywhere)
		UWidgetComponent* WidgetComponent;

	//Mesh of LEMON
	UPROPERTY(VisibleAnywhere, Category = Mesh)
		class USkeletalMeshComponent* Mesh;

	//Sphere used for pickup
	UPROPERTY(VisibleAnywhere, Category = "PickUp")
		class UWeaponPickupComponent* PickUp;


	/** Ends gameplay for this component. */
	UFUNCTION(BlueprintCallable)
		virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
private:
	AFirstPersonCharacter* Character;
	FTimerHandle LaserTimer;
	FTimerHandle LaserSFXTimer;
	float currentRadius = 50.f;
	float increment = 50.f;
	float minRadius = 50.f;
	float maxRadius = 700.f;
	UCameraComponent* Camera;
};

