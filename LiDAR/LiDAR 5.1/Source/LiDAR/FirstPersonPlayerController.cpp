// Fill out your copyright notice in the Description page of Project Settings.


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
	MappingContext->MapKey(JumpAction, EKeys::SpaceBar);

	//Sets up looking
	LookAction = NewObject<UInputAction>(this);
	LookAction->ValueType = EInputActionValueType::Axis2D;
	MappingContext->MapKey(LookAction, EKeys::Mouse2D);

	CrouchAction = NewObject<UInputAction>(this);
	CrouchAction->ValueType = EInputActionValueType::Boolean;
	MappingContext->MapKey(CrouchAction, EKeys::LeftControl);
}
