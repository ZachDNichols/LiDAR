// Fill out your copyright notice in the Description page of Project Settings.


#include "LEMON.h"
#include "FirstPersonCharacter.h"
#include "GameFramework/Actor.h"
#include "TimerManager.h"
#include "Components/WidgetComponent.h"
#include "Camera/CameraComponent.h"
#include "Laser.h"
#include "Dot.h"
#include "Blueprint/UserWidget.h"
#include "WeaponPickupComponent.h"
#include "Components/AudioComponent.h"

// Sets default values for this component's properties
ALEMON::ALEMON()
{
	PickUp = CreateDefaultSubobject<UWeaponPickupComponent>(TEXT("Pickup"));
	SetRootComponent(PickUp);

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(PickUp);

	AudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("Audio"));
	AudioComponent->SetupAttachment(Mesh);
}

void ALEMON::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	if (Character != nullptr)
	{
		// Unregister from the OnUseItem Event
		Character->OnUseItem.RemoveDynamic(this, &ALEMON::Fire);
		Character->EndUseItem.RemoveDynamic(this, &ALEMON::EndFire);		
		Character->EndUseItem.RemoveDynamic(this, &ALEMON::EndFire);
		Character->Scroll.RemoveDynamic(this, &ALEMON::ChangeRadius);
	}
}

void ALEMON::Fire()
{
	GetWorld()->GetTimerManager().SetTimer(LaserTimer, this, &ALEMON::Fire, 0.0001f, true, 0.0001f);

	//Generates random numbers to add variance to where the dots land
	float x = FMath::RandRange(currentRadius * -1, currentRadius);
	float y = FMath::RandRange(currentRadius * -1, currentRadius);
	float z = FMath::RandRange(currentRadius * -1, currentRadius);

	FHitResult Hit;
	FRotator Rot;
	FVector Loc;

	//Sets the location and rotation based on what the player sees
	Character->GetController()->GetPlayerViewPoint(Loc, Rot);

	//Sets the location to look more like it is coming out of the barrel of the player gun
	Loc = Loc + (((Camera->GetForwardVector() * 60.f) + (Camera->GetRightVector() * 20.f) - (Camera->GetUpVector() * 22.f)));

	//Sets the vector where the line trace should start
	FVector Start = Loc;
	//Sets the vector where it shoud end. Random numbers added to create offsets.
	FVector End = Start + (Rot.Vector() * 50000);
	End = FVector(End.X + x, End.Y + y, End.Z + z);
	//Parameters for what should be ignored. We ignore the player collision.
	FCollisionQueryParams TraceParams;
	TraceParams.AddIgnoredActor(Character);
	TraceParams.AddIgnoredActor(this->GetOwner());
	//FRotator for getting the rotation of the line
	FRotator HitRotation;

	if (GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Visibility, TraceParams))
	{
		//Draws debug lines for the traces
		//DrawDebugLine(GetWorld(), Start, End, FColor::Red, false, .2f);
		//Draws debug boxes where the collision impact occure
		//DrawDebugBox(GetWorld(), Hit.ImpactPoint, FVector(5, 5, 5), FColor::Orange, false, .2f);

		//Finds the hit rotation, then rotates it to align correctly
		HitRotation = (((Start - End) * -1).Rotation());
		HitRotation.Pitch -= 90.f;

		//
		FTransform SpawnTransform;
		SpawnTransform.SetLocation(Start);

		FActorSpawnParameters SpawnParams;

		LaserBeam = GetWorld()->SpawnActor<ALaser>(LaserBP, SpawnTransform, SpawnParams);

		float fDistance = Hit.Distance;

		LaserBeam->SetEnd(Hit.ImpactPoint);

		SpawnTransform.SetLocation(Hit.ImpactPoint);

		Dot = GetWorld()->SpawnActor<ADot>(DotBP, SpawnTransform, SpawnParams);

		Dot->AttachToComponent(Hit.GetActor()->GetRootComponent(), FAttachmentTransformRules::KeepWorldTransform, NAME_None);
	}
}

void ALEMON::FireSound()
{
	AudioComponent->Play();
	GetWorld()->GetTimerManager().SetTimer(LaserSFXTimer, this, &ALEMON::FireSound, 11.f, false);
}

void ALEMON::EndFire()
{
	GetWorld()->GetTimerManager().ClearTimer(LaserTimer);
	GetWorld()->GetTimerManager().ClearTimer(LaserSFXTimer);
	AudioComponent->Stop();
}

void ALEMON::ChangeRadius()
{
	currentRadius = Character->GetRadius();
}

void ALEMON::AttachWeapon(AFirstPersonCharacter* TargetCharacter)
{
	Character = TargetCharacter;
	if (Character != nullptr)
	{
		FAttachmentTransformRules AttachmentRules(EAttachmentRule::SnapToTarget, true);
		AttachToComponent(Character->GetMesh(), AttachmentRules, FName(TEXT("GripPoint")));
		Camera = Character->GetFirstPersonCameraComponent();

		// Register so that Fire is called every time the character tries to use the item being held
		Character->OnUseItem.AddDynamic(this, &ALEMON::Fire);
		Character->OnUseItem.AddDynamic(this, &ALEMON::FireSound);
		Character->EndUseItem.AddDynamic(this, &ALEMON::EndFire);
		Character->Scroll.AddDynamic(this, &ALEMON::ChangeRadius);
	}
}

