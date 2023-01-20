// Fill out your copyright notice in the Description page of Project Settings.


#include "LEMON.h"
#include "FirstPersonCharacter.h"
#include "GameFramework/Actor.h"
#include "TimerManager.h"
#include "Camera/CameraComponent.h"
#include "Laser.h"
#include "Dot.h"
#include "Kismet/GameplayStatics.h"
#include "WeaponPickupComponent.h"
#include "Components/AudioComponent.h"

// Sets default values for this component's properties
ALEMON::ALEMON()
{
	PickUp = CreateDefaultSubobject<UWeaponPickupComponent>(TEXT("Pickup"));
	SetRootComponent(PickUp);

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(PickUp);

	WidgetComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("Radius"));
	WidgetComponent->SetupAttachment(Mesh, FName("WidgetSpot"));
}

void ALEMON::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	if (Character)
	{
		// Unregister from the OnUseItem Event
		Character->OnUseItem.RemoveDynamic(this, &ALEMON::Fire);
		Character->EndUseItem.RemoveDynamic(this, &ALEMON::EndFire);		
		Character->EndUseItem.RemoveDynamic(this, &ALEMON::EndFire);
		Character->ScrollUp.RemoveDynamic(this, &ALEMON::IncreaseRadius);
		Character->ScrollDown.RemoveDynamic(this, &ALEMON::DecreaseRadius);
	}

	//Kills the widget
	if (LemonWidget)
	{
		LemonWidget->RemoveFromParent();
		WidgetComponent->SetWidget(nullptr);
		LemonWidget = nullptr;
	}

	Super::EndPlay(EndPlayReason);
}

void ALEMON::Fire()
{

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
	FVector End = Start + (Rot.Vector() * 2000);
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

		if (LaserBP)
		{
			FTransform SpawnTransform;
			SpawnTransform.SetLocation(Start);

			FActorSpawnParameters SpawnParams;

			LaserBeam = GetWorld()->SpawnActor<ALaser>(LaserBP, SpawnTransform, SpawnParams);

			float fDistance = Hit.Distance;

			LaserBeam->SetEnd(Hit.ImpactPoint);

			if (DotBP)
			{
				SpawnTransform.SetLocation(Hit.ImpactPoint);

				Dot = GetWorld()->SpawnActor<ADot>(DotBP, SpawnTransform, SpawnParams);

				Dot->AttachToComponent(Hit.GetActor()->GetRootComponent(), FAttachmentTransformRules::KeepWorldTransform, NAME_None);
			}
		}
	}
	else
	{
		HitRotation = (((Start - End) * -1).Rotation());
		HitRotation.Pitch -= 90.f;

		if (LaserBP)
		{
			FTransform SpawnTransform;
			SpawnTransform.SetLocation(Start);

			FActorSpawnParameters SpawnParams;

			LaserBeam = GetWorld()->SpawnActor<ALaser>(LaserBP, SpawnTransform, SpawnParams);

			LaserBeam->SetEnd(End);
		}
	}

	UGameplayStatics::PlaySoundAtLocation(GetWorld(), FireSound, GetActorLocation(), 1.f, FMath::RandRange(0.0f, 1.0f), 0.f);
	GetWorld()->GetTimerManager().SetTimer(LaserTimer, this, &ALEMON::Fire, 0.01f, false);
}

//Stops firing
void ALEMON::EndFire()
{
	GetWorld()->GetTimerManager().ClearTimer(LaserTimer);
	GetWorld()->GetTimerManager().ClearTimer(LaserSFXTimer);
}

void ALEMON::IncreaseRadius()
{
	if (currentRadius + increment <= maxRadius)
	{
		currentRadius += increment;
		LemonWidget->SetRadius(currentRadius, maxRadius);
	}
}

void ALEMON::DecreaseRadius()
{
	if (currentRadius - increment >= minRadius)
	{
		currentRadius -= increment;
		LemonWidget->SetRadius(currentRadius, maxRadius);
	}
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
		Character->EndUseItem.AddDynamic(this, &ALEMON::EndFire);
		Character->ScrollUp.AddDynamic(this, &ALEMON::IncreaseRadius);
		Character->ScrollDown.AddDynamic(this, &ALEMON::DecreaseRadius);
		Mesh->bCastDynamicShadow = false;

		if (LemonWidget_BP)
		{
			LemonWidget = CreateWidget<ULEMONWidget>(GetWorld(), LemonWidget_BP);
			//WidgetComponent->SetWidgetClass(LemonWidget_BP);
			WidgetComponent->SetWidget(LemonWidget);
			LemonWidget->SetRadius(currentRadius, maxRadius);
		}
	}
}

