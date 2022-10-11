// Fill out your copyright notice in the Description page of Project Settings.


#include "LEMON.h"
#include "FirstPersonCharacter.h"
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
ULEMON::ULEMON()
{

}

void ULEMON::AttachWeapon(AFirstPersonCharacter* TargetCharacter)
{
	Character = TargetCharacter;
	Character->GetGun();
	GetOwner()->Destroy();
}

