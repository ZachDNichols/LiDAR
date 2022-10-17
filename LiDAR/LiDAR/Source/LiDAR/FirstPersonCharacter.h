// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FirstPersonCharacter.generated.h"

class UIComponent;
class USkeletalMesh;
class USceneComponent;
class UCameraComponent;
class UAnimMontage;
class USoundBase;
class UStaticMeshComponent;
class USceneComponent;
class UPhysicsHandleComponent;

UCLASS()
class LIDAR_API AFirstPersonCharacter : public ACharacter
{
	GENERATED_BODY()
    
    UPROPERTY(VisibleAnywhere, Category = "Holding")
    UPhysicsHandleComponent* PhysicsHandle;
	
	//First person camera
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FirstPersonCamera;

	//Mesh for the first person (i.e. the gun used by the player
	UPROPERTY(VisibleAnywhere, Category=Mesh)
	USkeletalMeshComponent* PlayerMesh;
    
    UPROPERTY(VisibleAnywhere, Category = "Holding")
    USceneComponent* HoldLocation;
    
    UPROPERTY(EditAnywhere)
    TSubclassOf<class ULiDARHUD> PlayerHUDClass;

	UPROPERTY()
	class ULiDARHUD* PlayerHUD;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class ALaser> LaserBP;
    
    UPROPERTY()
    class ALaser* LaserBeam;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class ADot> DotBP;

	UPROPERTY()
	class ADot* Dot;
	
public:
	// Sets default values for this character's properties
	AFirstPersonCharacter();

	void GetGun();
    
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
    virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	//Handles moving forward and backwards
	void MoveForward(float Value);

	//Handles moving the player left or right
	void MoveRight(float Value);

	//Handles the player crouching and un-crouching
	void StartCrouch();
	void EndCrouch();

	//Handles the player firing
	void BeginShoot();
    
    //Handles the player stop shooting
    void EndShoot();
    
    //Handles shooting the beam
    void ShootLaser();
    
    //Handles increasing the radius
    void IncreaseRadius();
    
    //Handles decreasing the radius
    void DecreaseRadius();
    
    void PickupPhysicsObject();


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//Returns the camera component sub object
	UCameraComponent* GetFirstPersonCameraComponent() const { return FirstPersonCamera; };

	//Returns the mesh sub object
	USkeletalMeshComponent* GetMesh() const { return PlayerMesh; };
    

	void SetGun() { hasGun = true; }

private:
    bool bIsShooting = false;
	bool hasGun = false;
    float fRadius = 1000.f;
    float fMaxRadius = 15000.f;
    float fMinRadius = 5000.f;
    bool holdingObject = false;
	
};
