// Copyright 2023 Zach Nichols, All Rights Reserved


#include "FlickeringLight.h"

#include "Components/RectLightComponent.h"
#include "Components/SpotLightComponent.h"

// Sets default values
AFlickeringLight::AFlickeringLight()
{
	LightMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	SetRootComponent(LightMesh);

	switch (LightType)
	{
	case ELightType::PointLight :
		{
			PointLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("Light"));
			PointLight->SetupAttachment(LightMesh);
			break;
		}
	case ELightType::RectLight :
		{
			RectLight = CreateDefaultSubobject<URectLightComponent>(TEXT("Light"));
			RectLight->SetupAttachment(LightMesh);
			break;
		}
	case ELightType::SpotLight :
		{
			SpotLight = CreateDefaultSubobject<USpotLightComponent>(TEXT("Light"));
			SpotLight->SetupAttachment(LightMesh);
			break;
		}
	}
}

// Called when the game starts or when spawned
void AFlickeringLight::BeginPlay()
{
	SpotLight->SetIntensity(Intensity);

	if (FMath::RandRange(0.f, 1.f) > .8f)
	{
		PrimaryActorTick.bCanEverTick = true;
		DynamicMaterial = UMaterialInstanceDynamic::Create(LightMesh->GetMaterial(MaterialIndex), this);
		LightMesh->SetMaterial(MaterialIndex, DynamicMaterial);
	}
	else
	{
		PrimaryActorTick.bCanEverTick = false;
	}
	
	Super::BeginPlay();
}

// Called every frame
void AFlickeringLight::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (TimeFlickering < FlickerTime * 4.5f)
	{
		TimeFlickering += DeltaTime;
		return;
	}
	if (FMath::RandRange(0.f, 1.f) > NoFlickerChance)
	{
		FTimerHandle Timer1;
		FTimerHandle Timer2;
		FTimerHandle Timer3;
		FTimerHandle Timer4;

		GetWorldTimerManager().SetTimer(Timer1, this, &AFlickeringLight::FlickerOff,
			FlickerTime * FMath::RandRange(0.f, 1.5f), false);
		GetWorldTimerManager().SetTimer(Timer2, this, &AFlickeringLight::FlickerOn,
			FlickerTime * FMath::RandRange(2.f, 2.5f), false);
		GetWorldTimerManager().SetTimer(Timer3, this, &AFlickeringLight::FlickerOff,
			FlickerTime * FMath::RandRange(3.f, 3.5f), false);
		GetWorldTimerManager().SetTimer(Timer4, this, &AFlickeringLight::FlickerOn,
			FlickerTime * FMath::RandRange(4.f, 4.5f), false);

		TimeFlickering = 0.f;
	}
}

void AFlickeringLight::FlickerOn()
{
	if (SpotLight)
	{
		SpotLight->SetIntensity(Intensity);
	}

	DynamicMaterial->SetScalarParameterValue(TEXT("Emissive"), 5.f);
}

void AFlickeringLight::FlickerOff()
{
	if (SpotLight)
	{
		SpotLight->SetIntensity(0.f);
	}
	
	DynamicMaterial->SetScalarParameterValue(TEXT("Emissive"), 0.f);
}

