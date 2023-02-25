// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponPickupComponent.h"

// Sets default values for this component's properties
UWeaponPickupComponent::UWeaponPickupComponent()
{
    // Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
    // off to improve performance if you don't need them.

    SphereRadius = 32.f;
}


// Called when the game starts
void UWeaponPickupComponent::BeginPlay()
{
    Super::BeginPlay();

    //Tells the sphere component to start listening for an overlap
    OnComponentBeginOverlap.AddDynamic(this, &UWeaponPickupComponent::OnSphereBeginOverlap);
}

//When player overlaps with sphere, OnPickUp will broadcast to any Actors listening, which will result in the LEMON attaching to the player
void UWeaponPickupComponent::OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    UE_LOG(LogTemp, Warning, TEXT("Called"));
    AFirstPersonCharacter* Character = Cast<AFirstPersonCharacter>(OtherActor);
    if (Character != nullptr)
    {
        OnPickUp.Broadcast(Character);

        //Removes overlap listening after attaching to player
        OnComponentBeginOverlap.RemoveAll(this);
    }
}

