// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LEMONWidget.h"
#include "GameFramework/Actor.h"
#include "LEMON.generated.h"

UCLASS(Blueprintable, BlueprintType, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class LIDAR_API ALEMON : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	ALEMON();

	virtual void BeginPlay() override;
    virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

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
	//Function used to increase the radius
	UFUNCTION()
		void IncreaseRadius();

	//Function used to decrease the radius
	UFUNCTION()
		void DecreaseRadius();

	//Pointer for widget that will be created
	UPROPERTY()
		ULEMONWidget* LemonWidget;

	//Component for LEMON to sit in
	UPROPERTY(VisibleAnywhere)
		class UWidgetComponent* WidgetComponent;

	//Mesh of LEMON
	UPROPERTY(VisibleAnywhere, Category = Mesh)
		class USkeletalMeshComponent* Mesh;

	//Sphere used for pickup
	UPROPERTY(VisibleAnywhere, Category = "PickUp")
		class UWeaponPickupComponent* PickUp;

	UPROPERTY(EditDefaultsOnly, Category = "SFX")
		USoundBase* FireSound;

	UPROPERTY(EditAnywhere)
		UMaterial* Decal;

	UPROPERTY(EditDefaultsOnly)
		FVector DecalSize = FVector(1.f, 1.f, 1.f);

	UPROPERTY(EditDefaultsOnly)
		class UNiagaraSystem* Laser;

	UPROPERTY(EditDefaultsOnly)
		struct FLinearColor LaserColor = FLinearColor(188, 4, 4, 1.f);

	UPROPERTY(EditAnywhere, Category = "LaserOffset")
		float forwardLaserOffset = 80.f;

	UPROPERTY(EditAnywhere, Category = "LaserOffset")
		float rightLaserOffset = 40.f;

	UPROPERTY(EditAnywhere, Category = "LaserOffset")
		float upLaserOffset = 22.f;

private:
	class AFirstPersonCharacter* Character;
	struct FTimerHandle LaserTimer;
	struct FTimerHandle LaserSFXTimer;
	float currentRadius = 50.f;
	float increment = 50.f;
	float minRadius = 50.f;
	float maxRadius = 700.f;
	class UCameraComponent* Camera;
	FVector GetLocation();
};

