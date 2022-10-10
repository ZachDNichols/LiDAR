// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponPickupComponent.h"

// Sets default values for this component's properties
UWeaponPickupComponent::UWeaponPickupComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

    SphereRadius = 32.f;
}


// Called when the game starts
void UWeaponPickupComponent::BeginPlay()
{
	Super::BeginPlay();

    OnComponentBeginOverlap.AddDynamic(this, &UWeaponPickupComponent::OnSphereBeginOverlap);
}

void UWeaponPickupComponent::OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    AFirstPersonCharacter* Character = Cast<AFirstPersonCharacter>(OtherActor);
    if (Character != nullptr)
    {
        OnPickUp.Broadcast(Character);
        
        OnComponentBeginOverlap.RemoveAll(this);
    }
}


// Called every frame
void UWeaponPickupComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

