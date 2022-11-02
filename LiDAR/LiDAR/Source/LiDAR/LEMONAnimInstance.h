// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "FirstPersonCharacter.h"
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

	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

	UFUNCTION(BlueprintCallable, Category = "Animation")
	virtual void UpdateAnimProperties();

private:
	AFirstPersonCharacter* Character;
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadonly, Category = "Animation Property")
		bool isShooting;

	UPROPERTY(VisibleAnywhere, BlueprintReadonly, Category = "Animation Property")
		float speed;

	UFUNCTION()
	void AssignCharacter(AFirstPersonCharacter* TargetCharacter);

	UFUNCTION()
		void Shoot();

	UFUNCTION()
		void EndShoot();
};
