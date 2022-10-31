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


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnUseItem);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnEndUseItem);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FScroll);


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
	UPROPERTY(VisibleAnywhere, Category = Mesh)
		USkeletalMeshComponent* PlayerMesh;

	UPROPERTY(VisibleAnywhere, Category = "Holding")
		USceneComponent* HoldLocation;

	UPROPERTY(EditAnywhere)
		TSubclassOf<class ULiDARHUD> PlayerHUDClass;

	UPROPERTY()
		class ULiDARHUD* PlayerHUD;



public:
	// Sets default values for this character's properties
	AFirstPersonCharacter();

	UPROPERTY(BlueprintAssignable, Category = "Interaction")
		FOnUseItem OnUseItem;

	UPROPERTY(BlueprintAssignable, Category = "Interaction")
		FOnEndUseItem EndUseItem;

	UPROPERTY(BlueprintAssignable, Category = "Interaction")
		FScroll Scroll;

	UPROPERTY(BlueprintReadOnly)
		float currentRadius = 1000.f;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

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

	float GetRadius() const { return currentRadius; };

private:
	bool hasGun = false;
	bool holdingObject = false;
	AActor* heldObject;
	float increment = 500.f;
	float minRadius = 1000.f;
	float maxRadius = 15000.f;
};
