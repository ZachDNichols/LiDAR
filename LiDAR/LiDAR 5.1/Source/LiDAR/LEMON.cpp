// Fill out your copyright notice in the Description page of Project Settings.


#include "LEMON.h"
#include "FirstPersonCharacter.h"
#include "GameFramework/Actor.h"
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Components/WeaponPickupComponent.h"
#include "Components/WidgetComponent.h"
#include "Components/DecalComponent.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"

// Sets default values for this component's properties
ALEMON::ALEMON()
{
	PrimaryActorTick.bCanEverTick = false;
	
	PickUp = CreateDefaultSubobject<UWeaponPickupComponent>(TEXT("Pickup"));
	SetRootComponent(PickUp);

	Mesh = CreateDefaultSubobject <USkeletalMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(PickUp);
}

void ALEMON::BeginPlay()
{
	Super::BeginPlay();
	PickUp->OnPickUp.AddDynamic(this, &ALEMON::AttachWeapon);

	DynamicMaterial = UMaterialInstanceDynamic::Create(Mesh->GetMaterial(0), this);
	Mesh->SetMaterial(0, DynamicMaterial);
	DynamicMaterial->SetScalarParameterValue(TEXT("Emissive"), 0.f);
}

void ALEMON::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	if (Character)
	{
		// Unregister from the OnUseItem Event
		Character->OnUseItem.RemoveDynamic(this, &ALEMON::Fire);
		Character->ScrollUp.RemoveDynamic(this, &ALEMON::IncreaseRadius);
		Character->ScrollDown.RemoveDynamic(this, &ALEMON::DecreaseRadius);
	}

	Super::EndPlay(EndPlayReason);
}

void ALEMON::Fire()
{
	//Prevents the gun from firing too fast
	timeFromFire -= GetWorld()->UWorld::GetDeltaSeconds();
	if (timeFromFire > 0.f)
	{
		return;
	}
	
	timeFromFire = FireTime;
	
	//Generates random numbers to add variance to where the dots land
	float x = FMath::RandRange(currentRadius * -1, currentRadius);
	float y = FMath::RandRange(currentRadius * -1, currentRadius);
	float z = FMath::RandRange(currentRadius * -1, currentRadius);

	FHitResult Hit;
	FRotator Rot;
	FVector Start;
	
	Character->GetController()->GetPlayerViewPoint(Start, Rot);

	//Sets the location to look more like it is coming out of the barrel of the player gun
	Start = Start + (((Camera->GetForwardVector() * forwardLaserOffset) + (Camera->GetRightVector() * rightLaserOffset) - (Camera->GetUpVector() * upLaserOffset)));
	
	FVector End = Start + (Rot.Vector() * 2000);
	End = FVector(End.X + x, End.Y + y, End.Z + z);
	
	FCollisionQueryParams TraceParams;
	TraceParams.AddIgnoredActor(Character);
	TraceParams.AddIgnoredActor(this->GetOwner());
	TraceParams.AddIgnoredActor(this);


	if (GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Visibility, TraceParams))
	{
		//Draws debug lines for the traces
		//DrawDebugLine(GetWorld(), Start, End, FColor::Red, false, .2f);
		//Draws debug boxes where the collision impact occur
		//DrawDebugBox(GetWorld(), Hit.ImpactPoint, FVector(5, 5, 5), FColor::Orange, false, .2f);

		FRotator HitRotation = Hit.ImpactNormal.Rotation();

		if (Laser)
		{
			UNiagaraComponent* NiagaraLaser = UNiagaraFunctionLibrary::SpawnSystemAttached(Laser, Mesh, FName(), FVector(0.f, 2.f, 0.f), HitRotation, EAttachLocation::KeepRelativeOffset, true);
			NiagaraLaser->SetNiagaraVariableLinearColor(FString("Color"), LaserColor);
			NiagaraLaser->SetNiagaraVariableVec3(FString("LaserEnd"), Hit.Location);
		}

		if (Decal)
		{
			UDecalComponent* Dot = UGameplayStatics::SpawnDecalAttached(Decal, DecalSize, Hit.GetComponent(), NAME_None, Hit.ImpactPoint, HitRotation, EAttachLocation::KeepWorldPosition, 0.f);
			Dot->SetFadeScreenSize(0);
		}
		
	    UGameplayStatics::PlaySoundAtLocation(GetWorld(), FireSound, GetActorLocation(), 1.f, FMath::RandRange(0.0f, 1.0f), 0.f);
	}
	else
	{
		if (Laser)
		{
			UNiagaraComponent* NiagaraLaser = UNiagaraFunctionLibrary::SpawnSystemAttached(Laser, Mesh, FName(), FVector(0.f, 2.f, 0.f), Rot, EAttachLocation::KeepRelativeOffset, true);
			NiagaraLaser->SetNiagaraVariableLinearColor(FString("Color"), LaserColor);
			NiagaraLaser->SetNiagaraVariableVec3(FString("LaserEnd"), End);
		}

		UGameplayStatics::PlaySoundAtLocation(GetWorld(), FireSound, GetActorLocation(), 1.f, FMath::RandRange(0.0f, 1.0f), 0.f);
	}
}

void ALEMON::IncreaseRadius()
{
	if (currentRadius + increment <= maxRadius && DynamicMaterial)
	{
		currentRadius += increment;
		DynamicMaterial->SetScalarParameterValue(TEXT("Emissive"), currentRadius);
	}
}

void ALEMON::DecreaseRadius()
{
	if (currentRadius - increment >= minRadius && DynamicMaterial)
	{
		currentRadius -= increment;
		DynamicMaterial->SetScalarParameterValue(TEXT("Emissive"), currentRadius);
	}
}

void ALEMON::AttachWeapon(AFirstPersonCharacter* TargetCharacter)
{
	Character = TargetCharacter;
	if (Character != nullptr)
	{
		const FAttachmentTransformRules AttachmentRules(EAttachmentRule::SnapToTarget, true);
		AttachToComponent(Character->GetPlayerMesh(), AttachmentRules, FName(TEXT("GripPoint")));
		Camera = Character->GetFirstPersonCameraComponent();

		// Register so that Fire is called every time the character tries to use the item being held
		Character->OnUseItem.AddDynamic(this, &ALEMON::Fire);
		Character->ScrollUp.AddDynamic(this, &ALEMON::IncreaseRadius);
		Character->ScrollDown.AddDynamic(this, &ALEMON::DecreaseRadius);

		DynamicMaterial->SetScalarParameterValue(TEXT("Emissive"), currentRadius);
	}
}

