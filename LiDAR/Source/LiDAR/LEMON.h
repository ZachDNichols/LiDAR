// Copyright 2023 Zach Nichols, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
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

	float GetFireTime() { return FireTime; };

	//Function for attaching LEMON to player
	UFUNCTION(BlueprintCallable)
	void AttachWeapon(AFirstPersonCharacter* TargetCharacter);

	//Function called when firing
	UFUNCTION(BlueprintCallable, Category = "Weapon")
	void Fire();
	
	//Function used to increase the radius
	UFUNCTION()
	void IncreaseRadius();

	//Function used to decrease the radius
	UFUNCTION()
	void DecreaseRadius();

	UPROPERTY()
	bool bIsFiring = false;
	
	//Mesh of LEMON
	UPROPERTY(VisibleAnywhere, Category = Mesh)
	USkeletalMeshComponent* Mesh;

	//Sphere used for pickup
	UPROPERTY(VisibleAnywhere, Category = "PickUp")
	class UWeaponPickupComponent* PickUp;

	UPROPERTY(EditDefaultsOnly, Category = "Laser")
	USoundBase* FireSound;

	UPROPERTY(EditDefaultsOnly, Category = "Laser")
	TSubclassOf<AActor> ADot;

	UPROPERTY(EditDefaultsOnly, Category = "Laser")
	FVector DecalSize = FVector(1.f, 1.f, 1.f);

	UPROPERTY(EditDefaultsOnly, Category = "Laser")
	class UNiagaraSystem* Laser;

	UPROPERTY(EditDefaultsOnly, Category = "Laser")
	struct FLinearColor LaserColor = FLinearColor(188, 4, 4, 1.f);

	UPROPERTY(EditDefaultsOnly, Category = "Laser")
	float FireTime = 0.2f;

	UPROPERTY(EditDefaultsOnly, Category = "Laser")
	USoundConcurrency* SoundConcurrency;

	UPROPERTY(EditDefaultsOnly, Category = "Material")
		TArray<int> EmissiveMaterialIndexes = {1, 4};
	
private:
	UPROPERTY()
		TArray<UMaterialInstanceDynamic*> InstancedDynamicMaterials;
	UPROPERTY()
		class AFirstPersonCharacter* Character;
	UPROPERTY()
		class UCameraComponent* Camera;
	UPROPERTY()
	    TArray<AActor*> SpawnedDots;

	void SpawnLaser(const FHitResult& Hit, const FRotator& Rotation) const;

	void SpawnDot(const FHitResult& Hit);
	
	float currentRadius = 50.f;
	float increment = 50.f;
	float minRadius = 50.f;
	float maxRadius = 700.f;
	float timeFromFire;
};

