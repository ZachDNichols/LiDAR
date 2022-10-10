// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "FirstPersonCharacter.h"
#include "WeaponPickupComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPickUp, AFirstPersonCharacter*, PickUpCharacter);

UCLASS(Blueprintable, BlueprintType, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class LIDAR_API UWeaponPickupComponent : public USphereComponent
{
	GENERATED_BODY()

public:
    UPROPERTY(BlueprintAssignable, Category = "Interaction")
    FOnPickUp OnPickUp;
    
	// Sets default values for this component's properties
	UWeaponPickupComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
    
    UFUNCTION()
    void OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
