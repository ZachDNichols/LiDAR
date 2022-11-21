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

    Audio = CreateDefaultSubobject<UAudioComponent>(TEXT("Audio"));
    Audio->SetupAttachment(LaserMesh);
}

// Called when the game starts or when spawned
void ALaser::BeginPlay()
{
	Super::BeginPlay();

    startTime = FPlatformTime::Seconds();
    Character = GetWorld()->GetFirstPlayerController()->GetCharacter();
    Camera = Character->FindComponentByClass<UCameraComponent>();
    float Pitch = FMath::RandRange(-2.f, 2.f);
    Audio->SetPitchMultiplier(Pitch);
    Audio->Play();
}

// Called every frame
void ALaser::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    if (FPlatformTime::Seconds() - startTime > .12f)
    {
        Destroy();
    }
    SetStart();
    SetRotation();
    SetSize();
}

//Sets where the laser should start from
void ALaser::SetStart()
{
    StartLoc = Camera->GetComponentLocation() + (Camera->GetForwardVector() * 60.f) + (Camera->GetRightVector() * 20.f) - (Camera->GetUpVector() * 22.f);
}

//Sets the size of the laser, should not be more than 20,000 units
void ALaser::SetSize()
{
    SetDistance();
    LaserMesh->SetWorldScale3D(FVector(LaserMesh->GetComponentScale().X, LaserMesh->GetComponentScale().Y, length));
    SetActorLocation(StartLoc);
    SetActorRotation(Rotation);
}

//Sets the rotation of the laser
void ALaser::SetRotation()
{
	Rotation = (((StartLoc - EndLoc) * -1).Rotation());
    Rotation.Pitch -= 90.f;
}

//Sets where the laser should end
void ALaser::SetEnd(FVector EndLocation)
{
    EndLoc = EndLocation;
}

//Sets the distance of the laser
void ALaser::SetDistance()
{
    length = FVector::Dist(EndLoc, StartLoc);
}
