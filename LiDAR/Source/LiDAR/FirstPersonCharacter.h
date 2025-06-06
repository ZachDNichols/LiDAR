// Copyright 2023 Zach Nichols, All Rights Reserved

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
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FScrollUp);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FScrollDown);

UCLASS()
class LIDAR_API AFirstPersonCharacter : public ACharacter
{
    GENERATED_BODY()

    //First person camera
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
        UCameraComponent* FirstPersonCamera;

    //Mesh for the first person (i.e. the gun used by the player
    UPROPERTY(VisibleAnywhere, Category = Mesh)
        USkeletalMeshComponent* PlayerMesh;

    UPROPERTY(VisibleAnywhere)
        UPhysicsHandleComponent* PhysicsHandle;

public:
    // Sets default values for this character's properties
    AFirstPersonCharacter();

    UPROPERTY(BlueprintAssignable, Category = "Interaction")
        FOnUseItem OnUseItem;

    UPROPERTY(BlueprintAssignable, Category = "Interaction")
        FOnEndUseItem OnEndUseItem;
    
    UPROPERTY(BlueprintAssignable, Category = "Interaction")
        FScrollUp ScrollUp;

    UPROPERTY(BlueprintAssignable, Category = "Interaction")
        FScrollDown ScrollDown;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "UI")
        UUserWidget* PauseMenu;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Crouch)
        FVector CrouchEyeOffset;

protected:
    //Handles moving forward and backwards
    void Move(const struct FInputActionValue& ActionValue);

    void Look(const struct FInputActionValue& ActionValue);

    //Handles the player crouching and un-crouching
    void StartCrouch();

    void EndCrouch();

    //Handles the player firing
    void UseItem();

    void EndUseItem();

    //Handles increasing the radius
    void IncreaseRadius();

    //Handles decreasing the radius
    void DecreaseRadius();

    void PickupPhysicsObject();

    void PauseGame();

    void GrabObject(const struct FInputActionValue& ActionValue);

    void StartSprint();

    void EndSprint();

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    // Called to bind functionality to input
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    USkeletalMeshComponent* GetPlayerMesh() const { return PlayerMesh; };

    //Returns the camera component sub object
    UCameraComponent* GetFirstPersonCameraComponent() const { return FirstPersonCamera; };

    //Used for different footsteps per material, if there were more than one sound
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SFX")
        TArray<class USoundCue*> FootStepSounds;

    //Function to play footstep sounds
    UFUNCTION(BlueprintCallable, Category = "SFX")
        void PlayFootStepSound();

    //Resets if the player is stepping
    UFUNCTION(BlueprintCallable, Category = "SFX")
        void ResetStep() { bStep = false; };

    UPROPERTY(EditDefaultsOnly)
        float GrabDistance = 250.f;

    UPROPERTY(EditDefaultsOnly)
        float ThrowForce = 500.f;

    UPROPERTY(EditDefaultsOnly)
        float RegularWalkSpeed = 600.f;

    UPROPERTY(EditDefaultsOnly)
        float SprintSpeed = 800.f;

    UPROPERTY(EditDefaultsOnly)
        float CrouchSpeed = 300.f;

private:
    void ReleaseObject(bool bThrow);
    void UpdateGrabbedObject();
    void UpdateCrouch(float DeltaTime);
    bool bStep = false;
    bool bHasGun = false;
    bool bHoldingObject = false;
    bool bCrouchState;
    bool bIsCrouching;
    float FootStepRate = .32f;
    UPROPERTY()
    UPrimitiveComponent* HeldObject;
    FTimerHandle FootStepTimer;
};
