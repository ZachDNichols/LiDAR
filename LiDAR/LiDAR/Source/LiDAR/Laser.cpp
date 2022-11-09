// Fill out your copyright notice in the Description page of Project Settings.

#include "Laser.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "Math/Vector.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ALaser::ALaser()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    
    LaserMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LaserMesh"));
    SetRootComponent(LaserMesh);
}

// Called when the game starts or when spawned
void ALaser::BeginPlay()
{
	Super::BeginPlay();

    startTime = FPlatformTime::Seconds();
    Character = GetWorld()->GetFirstPlayerController()->GetCharacter();
    Camera = Character->FindComponentByClass<UCameraComponent>();
}

// Called every frame
void ALaser::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
   if (FPlatformTime::Seconds() - startTime > .12f)
       Destroy();
    SetStart();
    SetRotation();
    SetSize();
}

void ALaser::SetStart()
{
    StartLoc = Camera->GetComponentLocation() + (Camera->GetForwardVector() * 60.f) + (Camera->GetRightVector() * 20.f) - (Camera->GetUpVector() * 22.f);
}

void ALaser::SetSize()
{
    SetDistance();
    LaserMesh->SetWorldScale3D(FVector(LaserMesh->GetComponentScale().X, LaserMesh->GetComponentScale().Y, length));
    SetActorLocation(StartLoc);
    SetActorRotation(Rotation);
}

void ALaser::SetRotation()
{
	Rotation = (((StartLoc - EndLoc) * -1).Rotation());
    Rotation.Pitch -= 90.f;
}

void ALaser::SetEnd(FVector EndLocation)
{
    EndLoc = EndLocation;
}

void ALaser::SetDistance()
{
    length = FVector::Dist(EndLoc, StartLoc);
}
