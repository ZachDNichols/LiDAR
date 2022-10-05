// Fill out your copyright notice in the Description page of Project Settings.


#include "Laser.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ALaser::ALaser()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    
    LaserMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LaserMesh"));
}

// Called when the game starts or when spawned
void ALaser::BeginPlay()
{
	Super::BeginPlay();
    startTime = FPlatformTime::Seconds();
}

// Called every frame
void ALaser::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    if (FPlatformTime::Seconds() - startTime > 0.12)
        Destroy();
}

void ALaser::SetLength(float Value)
{
    LaserMesh->SetWorldScale3D(FVector(LaserMesh->GetComponentScale().X, LaserMesh->GetComponentScale().Y, Value));
}

void ALaser::SetRotation(FRotator Rotation)
{
    FQuat LaserRotation = FQuat(Rotation);
    
    AddActorLocalRotation(LaserRotation, false, 0, ETeleportType::None);
}
