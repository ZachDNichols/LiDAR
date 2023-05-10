// Copyright 2023 Zach Nichols, All Rights Reserved


#include "FirstPersonPlayerController.h"
#include "InputAction.h"
#include "InputMappingContext.h"
#include "InputModifiers.h"

static void MapKey(UInputMappingContext* InputMappingContext, UInputAction* InputAction, FKey Key, bool bNegate = false, bool bSwizzle = false, EInputAxisSwizzle SwizzleOrder = EInputAxisSwizzle::YXZ)
{
	FEnhancedActionKeyMapping& Mapping = InputMappingContext->MapKey(InputAction, Key);
	UObject* Outer = InputMappingContext->GetOuter();

	if (bNegate)
	{
		UInputModifierNegate* Negate = NewObject<UInputModifierNegate>(Outer);
		Mapping.Modifiers.Add(Negate);
	}

	if (bSwizzle)
	{
		UInputModifierSwizzleAxis* Swizzle = NewObject<UInputModifierSwizzleAxis>(Outer);
		Swizzle->Order = SwizzleOrder;
		Mapping.Modifiers.Add(Swizzle);
	}
}

static void PressedKey(UInputMappingContext* MappingContext, UInputAction* InputAction, FKey Key)
{
    FEnhancedActionKeyMapping& Mapping = MappingContext->MapKey(InputAction, Key);
    UObject* Outer = MappingContext->GetOuter();
    UInputTriggerPressed* Pressed = NewObject<UInputTriggerPressed>(Outer);
    Mapping.Triggers.Add(Pressed);
}

void AFirstPersonPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	MappingContext = NewObject<UInputMappingContext>(this);

	//Sets up moving with WASD
	MoveAction = NewObject<UInputAction>(this);
	MoveAction->ValueType = EInputActionValueType::Axis3D;
	MapKey(MappingContext, MoveAction, EKeys::W);
	MapKey(MappingContext, MoveAction, EKeys::S, true);
	MapKey(MappingContext, MoveAction, EKeys::A, true, true);
	MapKey(MappingContext, MoveAction, EKeys::D, false, true);

	//Sets up jumping action
	JumpAction = NewObject<UInputAction>(this);
	JumpAction->ValueType = EInputActionValueType::Boolean;
    PressedKey(MappingContext, JumpAction, EKeys::SpaceBar);

	//Sets up looking
	LookAction = NewObject<UInputAction>(this);
	LookAction->ValueType = EInputActionValueType::Axis2D;
	MappingContext->MapKey(LookAction, EKeys::Mouse2D);

	CrouchAction = NewObject<UInputAction>(this);
	CrouchAction->ValueType = EInputActionValueType::Boolean;
	MappingContext->MapKey(CrouchAction, EKeys::LeftControl);

	ShootAction = NewObject<UInputAction>(this);
	ShootAction->ValueType = EInputActionValueType::Boolean;
	MappingContext->MapKey(ShootAction, EKeys::LeftMouseButton);

	IncreaseScrollAction = NewObject<UInputAction>(this);
	IncreaseScrollAction->ValueType = EInputActionValueType::Boolean;
	MappingContext->MapKey(IncreaseScrollAction, EKeys::MouseScrollUp);

	DecreaseScrollAction = NewObject<UInputAction>(this);
	DecreaseScrollAction->ValueType = EInputActionValueType::Boolean;
	MappingContext->MapKey(DecreaseScrollAction, EKeys::MouseScrollDown);
    
	GrabObjectAction = NewObject<UInputAction>(this);
    GrabObjectAction->ValueType = EInputActionValueType::Boolean;
    PressedKey(MappingContext, GrabObjectAction, EKeys::E);
    
    PauseGameAction = NewObject<UInputAction>(this);
    PauseGameAction->ValueType = EInputActionValueType::Boolean;
    PressedKey(MappingContext, PauseGameAction, EKeys::Escape);

	SprintAction = NewObject<UInputAction>(this);
	SprintAction->ValueType = EInputActionValueType::Boolean;
	MapKey(MappingContext, SprintAction, EKeys::LeftShift);
}
