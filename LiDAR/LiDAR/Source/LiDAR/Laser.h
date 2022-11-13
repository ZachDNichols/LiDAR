// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/AudioComponent.h"
#include "GameFramework/Actor.h"
#include "Laser.generated.h"

class UStaticMeshComponent;

UCLASS()
class LIDAR_API ALaser : public AActor
{
	GENERATED_BODY()
    
    UPROPERTY(VisibleAnywhere, Category = mesh)
    UStaticMeshComponent* LaserMesh;

    UPROPERTY(VisibleAnywhere, Category = "SFX")
        UAudioComponent* Audio;

    //UPROPERTY(EditAnywhere)
    //TSubclassOf<class AFirstPersonCharacter> CharacterBP;

    //UPROPERTY()
    //class AFirstPersonCharacter* Character;
    
	
public:	
	// Sets default values for this actor's properties
	ALaser();

    void SetStart();
    
    void SetSize();

    void SetRotation();

    void SetEnd(FVector EndLocation);

    void SetDistance();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
    
private:
    double startTime;
    float length;
    FVector EndLoc;
    FVector StartLoc;
    FRotator Rotation;

    class ACharacter* Character;
    class UCameraComponent* Camera;

};
