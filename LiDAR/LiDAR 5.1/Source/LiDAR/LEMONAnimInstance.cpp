// Fill out your copyright notice in the Description page of Project Settings.


#include "LEMONAnimInstance.h"
#include "Kismet/GameplayStatics.h"
#include "WeaponPickupComponent.h"
#include "LEMON.h"

void ULEMONAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	TArray<AActor*> Guns;

	//Gets the LEMON/Character
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ALEMON::StaticClass(), Guns);
	if (Guns.Num() > 0)
	{
		if (Cast<UWeaponPickupComponent>(Guns[0]->GetComponentByClass(UWeaponPickupComponent::StaticClass())))
		{
			UWeaponPickupComponent* WeaponPickup = Cast<UWeaponPickupComponent>(Guns[0]->GetComponentByClass(UWeaponPickupComponent::StaticClass()));

			WeaponPickup->OnPickUp.AddUniqueDynamic(this, &ULEMONAnimInstance::AssignCharacter);
			
			if (ALEMON* Lemon = Cast<ALEMON>(Guns[0]))
			{
				FireTime = Lemon->GetFireTime();
				Lemon->NotFired.AddDynamic(this, &ULEMONAnimInstance::EndShoot);
			}
		}
	}
}

void ULEMONAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	//If there is a null pointer to Character, one will tried to be found every frame
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
				
				if (ALEMON* Lemon = Cast<ALEMON>(Guns[0]))
				{
					FireTime = Lemon->GetFireTime();
					Lemon->NotFired.AddDynamic(this, &ULEMONAnimInstance::EndShoot);
				}
			}
		}
	}
}

//Updates properties according to speed
void ULEMONAnimInstance::UpdateAnimProperties()
{
	speed = Character->GetVelocity().Size();
	
	timeFromFire -= GetWorld()->UWorld::GetDeltaSeconds();
	if (timeFromFire < 0.f)
	{
		EndShoot();
	}
}

//Adds the event listeners for when shooting or not
void ULEMONAnimInstance::AssignCharacter(AFirstPersonCharacter* TargetCharacter)
{
	Character = TargetCharacter;
	Character->OnUseItem.AddDynamic(this, &ThisClass::Shoot);
}

void ULEMONAnimInstance::Shoot()
{
	timeFromFire = FireTime;
	isShooting = true;
}

void ULEMONAnimInstance::EndShoot()
{
	timeFromFire = 0;
	isShooting = false;
}