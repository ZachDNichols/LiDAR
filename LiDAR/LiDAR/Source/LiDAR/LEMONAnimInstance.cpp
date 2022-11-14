// Fill out your copyright notice in the Description page of Project Settings.


#include "LEMONAnimInstance.h"
#include "Kismet/GameplayStatics.h"
#include "WeaponPickupComponent.h"
#include "LEMON.h"

void ULEMONAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	TArray<AActor*> Guns;

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ALEMON::StaticClass(), Guns);
	if (Guns.Num() > 0)
	{
		if (Cast<UWeaponPickupComponent>(Guns[0]->GetComponentByClass(UWeaponPickupComponent::StaticClass())))
		{
			UWeaponPickupComponent* WeaponPickup = Cast<UWeaponPickupComponent>(Guns[0]->GetComponentByClass(UWeaponPickupComponent::StaticClass()));

			WeaponPickup->OnPickUp.AddUniqueDynamic(this, &ULEMONAnimInstance::AssignCharacter);
		}
	}
}

void ULEMONAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	if (Character)
	{
		UpdateAnimProperties();
	}
	else 
	{
		TArray<AActor*> Guns;

		UGameplayStatics::GetAllActorsOfClass(GetWorld(), ALEMON::StaticClass(), Guns);
		if (Guns.Num() > 0)
		{
			if (Cast<UWeaponPickupComponent>(Guns[0]->GetComponentByClass(UWeaponPickupComponent::StaticClass())))
			{
				UWeaponPickupComponent* WeaponPickup = Cast<UWeaponPickupComponent>(Guns[0]->GetComponentByClass(UWeaponPickupComponent::StaticClass()));

				WeaponPickup->OnPickUp.AddUniqueDynamic(this, &ULEMONAnimInstance::AssignCharacter);
			}
		}
	}
}
void ULEMONAnimInstance::UpdateAnimProperties()
{
	speed = Character->GetVelocity().Size();
}


void ULEMONAnimInstance::AssignCharacter(AFirstPersonCharacter* TargetCharacter)
{ 
	Character = TargetCharacter;
	Character->OnUseItem.AddDynamic(this, &ThisClass::Shoot);
	Character->EndUseItem.AddDynamic(this, &ThisClass::EndShoot);
}

void ULEMONAnimInstance::Shoot()
{
	isShooting = true;
}

void ULEMONAnimInstance::EndShoot()
{
	isShooting = false;
}