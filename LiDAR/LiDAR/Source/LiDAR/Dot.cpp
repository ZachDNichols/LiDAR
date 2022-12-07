// Fill out your copyright notice in the Description page of Project Settings.


#include "Dot.h"
#include "Components/StaticMeshComponent.h"


// Sets default values
ADot::ADot()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	DotMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DotMesh"));
	SetRootComponent(DotMesh);
}

// Called when the game starts or when spawned
void ADot::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADot::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

