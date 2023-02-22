// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "PhysicalMaterials/PhysicalMaterial.h"
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Sound/SoundCue.h"
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
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FScrollUp);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FScrollDown);



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

public:
    // Sets default values for this character's properties
    AFirstPersonCharacter();

    UPROPERTY(BlueprintAssignable, Category = "Interaction")
        FOnUseItem OnUseItem;

    UPROPERTY(BlueprintAssignable, Category = "Interaction")
        FOnEndUseItem EndUseItem;

    UPROPERTY(BlueprintAssignable, Category = "Interaction")
        FScrollUp ScrollUp;

    UPROPERTY(BlueprintAssignable, Category = "Interaction")
        FScrollDown ScrollDown;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "UI")
        UUserWidget* PauseMenu;

    UPROPERTY(EditAnywhere)
        class UFloatingPawnMovement* Movement;

    UPROPERTY(EditAnywhere)
        float MoveScale;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Crouch)
        FVector CrouchEyeOffset;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Crouch)
        float CrouchSpeed;

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

    //Handles moving forward and backwards
    void Move(const struct FInputActionValue& ActionValue);

    void Look(const struct FInputActionValue& ActionValue);

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

    void PauseGame();

    void GrabObject(const struct FInputActionValue& ActionValue);

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    // Called to bind functionality to input
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    void OnStartCrouch(float HalfHeightAdjust, float ScaledHalfHeightAdjust) override;

    void OnEndCrouch(float HalfHeightAdjust, float ScaledHalfHeightAdjust) override;

    void CalcCamera(float DeltaTime, struct FMinimalViewInfo& OutResult) override;

    //Returns the camera component sub object
    UCameraComponent* GetFirstPersonCameraComponent() const { return FirstPersonCamera; };

    //Returns the mesh sub object
    USkeletalMeshComponent* GetMesh() const { return PlayerMesh; };

    //Used for different footsteps per material, if there were more than one sound
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SFX")
        TArray<USoundCue*> FootStepSounds;

    //Function to play footstep sounds
    UFUNCTION(BlueprintCallable, Category = "SFX")
        void PlayFootStepSound();

    //Resets if the player is stepping
    UFUNCTION(BlueprintCallable, Category = "SFX")
        void ResetStep() { step = false; };

private:
    void ReleaseObject();
    void SetGrabbedObject();
    FTimerHandle FootStepTimer;
    bool step;
    bool hasGun = false;
    bool holdingObject = false;
    AActor* heldObject;
};
