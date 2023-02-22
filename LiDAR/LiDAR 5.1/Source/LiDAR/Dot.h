// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Dot.generated.h"

UCLASS()
class LIDAR_API ADot : public AActor
{
	GENERATED_BODY()

		UPROPERTY(VisibleAnywhere, Category = mesh)
		UStaticMeshComponent* DotMesh;

public:
	// Sets default values for this actor's properties
	ADot();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
