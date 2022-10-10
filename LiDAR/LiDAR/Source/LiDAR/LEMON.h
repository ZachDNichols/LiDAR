// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LEMON.generated.h"

class AFirstPersonCharacter;

UCLASS(Blueprintable, BlueprintType, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class LIDAR_API ULEMON : public UActorComponent
{
	GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere)
    TSubclassOf<class ALaser> LaserBP;
    
    UPROPERTY()
    class ALaser* LaserBeam;

    UPROPERTY(EditAnywhere)
    TSubclassOf<class ADot> DotBP;

    UPROPERTY()
    class ADot* Dot;
    
	// Sets default values for this component's properties
	ULEMON();
    
    UFUNCTION(BlueprintCallable, Category = "Weapon")
    void AttachWeapon(AFirstPersonCharacter* TargetCharacter)
    
    UFUNCTION(BlueprintCallable, Category = "Weapon")
    void Fire();
    
    UFUNCTION(BlueprintCallable, Category = "Weapon")
    void HaltFire();


protected:
	// Called when the game starts
	virtual void BeginPlay() override;
    
    virtual void EndPlay(cost EEndPlayReason::Type EndPlayReason) override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
    AFirstPersonCharacter* Character;
    bool firing = false;
};
