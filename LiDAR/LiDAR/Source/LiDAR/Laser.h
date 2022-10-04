// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Laser.generated.h"

class UStaticMeshComponent;

UCLASS()
class LIDAR_API ALaser : public AActor
{
	GENERATED_BODY()
    
    UPROPERTY(VisibleAnywhere, Category = mesh)
    UStaticMeshComponent* LaserMesh;
    
	
public:	
	// Sets default values for this actor's properties
	ALaser();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
