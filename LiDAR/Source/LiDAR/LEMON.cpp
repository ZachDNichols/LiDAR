// Copyright 2023 Zach Nichols, All Rights Reserved


#include "LEMON.h"
#include "FirstPersonCharacter.h"
#include "GameFramework/Actor.h"
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Components/WeaponPickupComponent.h"
#include "Components/DecalComponent.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"
#include "LEMONAnimInstance.h"

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
	
	for (int i = 0; i < Mesh->GetMaterials().Num(); i++)
	{
		UMaterialInstanceDynamic* DynamicMaterial = UMaterialInstanceDynamic::Create(Mesh->GetMaterial(i), this);
		Mesh->SetMaterial(i, DynamicMaterial);
		InstancedDynamicMaterials.Add(DynamicMaterial);
	}

	for (UMaterialInstanceDynamic* DynamicMaterial : InstancedDynamicMaterials)
	{
		DynamicMaterial->SetScalarParameterValue("Emissive", 0.f);
		DynamicMaterial->SetScalarParameterValue("DepthScale", 1.f);
	}
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
	if (timeFromFire > 0.f || !bIsFiring)
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
	
	FVector Start = Mesh->GetComponentLocation() + (Mesh->GetForwardVector() * 34.f);
	
	Character->GetController()->GetPlayerViewPoint(Start, Rot);
	
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

		if (Hit.Distance < 5.f)
		{
			return;
		}

		FRotator HitRotation = Hit.ImpactNormal.Rotation();

		if (Laser)
		{
			UNiagaraComponent* NiagaraLaser = UNiagaraFunctionLibrary::SpawnSystemAttached(
				Laser, Mesh, FName(),
				FVector(34.f, 0.f + FMath::RandRange(-5.f, 5.f), 0.f + FMath::RandRange(3.f, 8.f)), HitRotation,
				EAttachLocation::KeepRelativeOffset, true);
			NiagaraLaser->SetVariableLinearColor(FName("Color"), LaserColor);
			NiagaraLaser->SetVariableVec3(FName("LaserEnd"), Hit.Location);
		}

		if (Decal)
		{
			UDecalComponent* Dot = UGameplayStatics::SpawnDecalAttached(Decal, DecalSize, Hit.GetComponent(), NAME_None, Hit.ImpactPoint, HitRotation, EAttachLocation::KeepWorldPosition, 0.f);
			Dot->SetFadeScreenSize(0);
		}
	}
	else
	{
		if (Laser)
		{
			UNiagaraComponent* NiagaraLaser = UNiagaraFunctionLibrary::SpawnSystemAttached(
				Laser, Mesh, FName(),
				FVector(34.f, 0.f + FMath::RandRange(-5.f, 5.f),
				        0.f + FMath::RandRange(3.f, 8.f)), Rot,
				EAttachLocation::KeepRelativeOffset, true);
			NiagaraLaser->SetVariableLinearColor(FName("Color"), LaserColor);
			NiagaraLaser->SetVariableVec3(FName("LaserEnd"), End);
		}
	}

	UGameplayStatics::PlaySoundAtLocation(GetWorld(), FireSound, GetActorLocation(), 1.f, FMath::RandRange(0.0f, 1.0f), 0.f, nullptr, SoundConcurrency);
}

void ALEMON::IncreaseRadius()
{
	if (currentRadius + increment <= maxRadius && EmissiveMaterialIndexes.Num() > 0)
	{
		currentRadius += increment;
		for (UMaterialInstanceDynamic* DynamicMaterial : InstancedDynamicMaterials)
		{
			DynamicMaterial->SetScalarParameterValue("Emissive", currentRadius);
		}
	}
}

void ALEMON::DecreaseRadius()
{
	if (currentRadius - increment >= minRadius && EmissiveMaterialIndexes.Num() > 0)
	{
		currentRadius -= increment;
		for (UMaterialInstanceDynamic* DynamicMaterial : InstancedDynamicMaterials)
		{
			DynamicMaterial->SetScalarParameterValue("Emissive", currentRadius);
		}
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

		for (UMaterialInstanceDynamic* DynamicMaterial : InstancedDynamicMaterials)
		{
			DynamicMaterial->SetScalarParameterValue("Emissive", currentRadius);
			DynamicMaterial->SetScalarParameterValue("DepthScale", .3f);
		}
	}
}

