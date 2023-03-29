// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FlickeringLight.generated.h"

UENUM(BlueprintType)
enum class ELightType: uint8
{
	SpotLight, PointLight, RectLight
};

UCLASS()
class LIDAR_API AFlickeringLight : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFlickeringLight();

	UPROPERTY(EditDefaultsOnly)
		ELightType LightType;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Light")
		UStaticMeshComponent* LightMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Light", meta = (EditCondition = "LightType == ELightType::SpotLight"))
		class USpotLightComponent* SpotLight;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Light", meta = (EditCondition = "LightType == ELightType::PointLight"))
		class UPointLightComponent* PointLight;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Light", meta = (EditCondition = "LightType == ELightType::RectLight"))
		class URectLightComponent* RectLight;

	UPROPERTY(EditDefaultsOnly)
		float Intensity = 20000.f;

	UPROPERTY(EditDefaultsOnly)
		float FlickerTime = .01f;

	UPROPERTY(EditDefaultsOnly)
		float NoFlickerChance = .99f;

	UPROPERTY(EditDefaultsOnly)
		int MaterialIndex = 0;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	float TimeFlickering;
	UMaterialInstanceDynamic* DynamicMaterial;
	
	void FlickerOn();
	void FlickerOff();
};
