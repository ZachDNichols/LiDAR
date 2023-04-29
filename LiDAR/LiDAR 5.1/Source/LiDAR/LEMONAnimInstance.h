// Copyright 2023 Zach Nichols, All Rights Reserved

#pragma once

#include "FirstPersonCharacter.h"
#include "LEMON.h"
#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "LEMONAnimInstance.generated.h"


/**
 *
 */
UCLASS()
class LIDAR_API ULEMONAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

protected:

	//Overrides for animation blueprints
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

	UFUNCTION(BlueprintCallable, Category = "Animation")
		virtual void UpdateAnimProperties();

private:
	//Pointers to Character and LEMON
	AFirstPersonCharacter* Character;
	ALEMON* Gun;
	
public:

	//If the gun is shooting
	UPROPERTY(VisibleAnywhere, BlueprintReadonly, Category = "Animation Property")
		bool isShooting;

	//Speed of player
	UPROPERTY(VisibleAnywhere, BlueprintReadonly, Category = "Animation Property")
		float Speed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Animation Property")
		float CrouchPlayRate = .8f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Animation Property")
		float SprintPlayRate = 1.5f;

	//First person character
	UFUNCTION()
		void AssignCharacter(AFirstPersonCharacter* TargetCharacter);

	//Change animation state if shooting
	UFUNCTION()
		void Shoot();

	UFUNCTION()
		void EndShoot();
};
