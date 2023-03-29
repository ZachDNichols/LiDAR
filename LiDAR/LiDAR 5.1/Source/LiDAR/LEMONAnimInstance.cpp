// Copyright 2023 Zach Nichols, All Rights Reserved


#include "LEMONAnimInstance.h"
#include "Kismet/GameplayStatics.h"
#include "Components/WeaponPickupComponent.h"
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
			}
		}
	}
}

//Updates properties according to speed
void ULEMONAnimInstance::UpdateAnimProperties()
{
	speed = Character->GetVelocity().Size();
}

//Adds the event listeners for when shooting or not
void ULEMONAnimInstance::AssignCharacter(AFirstPersonCharacter* TargetCharacter)
{
	Character = TargetCharacter;
	Character->OnUseItem.AddDynamic(this, &ThisClass::Shoot);
	Character->OnEndUseItem.AddDynamic(this, &ThisClass::EndShoot);
}

void ULEMONAnimInstance::Shoot()
{
	isShooting = true;
}

void ULEMONAnimInstance::EndShoot()
{
	isShooting = false;
}