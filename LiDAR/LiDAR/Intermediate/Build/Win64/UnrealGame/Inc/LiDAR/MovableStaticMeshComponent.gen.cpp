// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LiDAR/MovableStaticMeshComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMovableStaticMeshComponent() {}
// Cross Module References
	LIDAR_API UEnum* Z_Construct_UEnum_LiDAR_ERotationAxis();
	UPackage* Z_Construct_UPackage__Script_LiDAR();
	LIDAR_API UEnum* Z_Construct_UEnum_LiDAR_ELocationAxis();
	LIDAR_API UEnum* Z_Construct_UEnum_LiDAR_EMovementType();
	LIDAR_API UClass* Z_Construct_UClass_UMovableStaticMeshComponent_NoRegister();
	LIDAR_API UClass* Z_Construct_UClass_UMovableStaticMeshComponent();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent();
	ENGINE_API UClass* Z_Construct_UClass_UCurveFloat_NoRegister();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_ERotationAxis;
	static UEnum* ERotationAxis_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_ERotationAxis.OuterSingleton)
		{
			Z_Registration_Info_UEnum_ERotationAxis.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_LiDAR_ERotationAxis, Z_Construct_UPackage__Script_LiDAR(), TEXT("ERotationAxis"));
		}
		return Z_Registration_Info_UEnum_ERotationAxis.OuterSingleton;
	}
	template<> LIDAR_API UEnum* StaticEnum<ERotationAxis>()
	{
		return ERotationAxis_StaticEnum();
	}
	struct Z_Construct_UEnum_LiDAR_ERotationAxis_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_LiDAR_ERotationAxis_Statics::Enumerators[] = {
		{ "ERotationAxis::Yaw", (int64)ERotationAxis::Yaw },
		{ "ERotationAxis::Pitch", (int64)ERotationAxis::Pitch },
		{ "ERotationAxis::Roll", (int64)ERotationAxis::Roll },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_LiDAR_ERotationAxis_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "MovableStaticMeshComponent.h" },
		{ "Pitch.Name", "ERotationAxis::Pitch" },
		{ "Roll.Name", "ERotationAxis::Roll" },
		{ "Yaw.Name", "ERotationAxis::Yaw" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_LiDAR_ERotationAxis_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_LiDAR,
		nullptr,
		"ERotationAxis",
		"ERotationAxis",
		Z_Construct_UEnum_LiDAR_ERotationAxis_Statics::Enumerators,
		UE_ARRAY_COUNT(Z_Construct_UEnum_LiDAR_ERotationAxis_Statics::Enumerators),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(Z_Construct_UEnum_LiDAR_ERotationAxis_Statics::Enum_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UEnum_LiDAR_ERotationAxis_Statics::Enum_MetaDataParams))
	};
	UEnum* Z_Construct_UEnum_LiDAR_ERotationAxis()
	{
		if (!Z_Registration_Info_UEnum_ERotationAxis.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ERotationAxis.InnerSingleton, Z_Construct_UEnum_LiDAR_ERotationAxis_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_ERotationAxis.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_ELocationAxis;
	static UEnum* ELocationAxis_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_ELocationAxis.OuterSingleton)
		{
			Z_Registration_Info_UEnum_ELocationAxis.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_LiDAR_ELocationAxis, Z_Construct_UPackage__Script_LiDAR(), TEXT("ELocationAxis"));
		}
		return Z_Registration_Info_UEnum_ELocationAxis.OuterSingleton;
	}
	template<> LIDAR_API UEnum* StaticEnum<ELocationAxis>()
	{
		return ELocationAxis_StaticEnum();
	}
	struct Z_Construct_UEnum_LiDAR_ELocationAxis_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_LiDAR_ELocationAxis_Statics::Enumerators[] = {
		{ "ELocationAxis::X", (int64)ELocationAxis::X },
		{ "ELocationAxis::Y", (int64)ELocationAxis::Y },
		{ "ELocationAxis::Z", (int64)ELocationAxis::Z },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_LiDAR_ELocationAxis_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "MovableStaticMeshComponent.h" },
		{ "X.Name", "ELocationAxis::X" },
		{ "Y.Name", "ELocationAxis::Y" },
		{ "Z.Name", "ELocationAxis::Z" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_LiDAR_ELocationAxis_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_LiDAR,
		nullptr,
		"ELocationAxis",
		"ELocationAxis",
		Z_Construct_UEnum_LiDAR_ELocationAxis_Statics::Enumerators,
		UE_ARRAY_COUNT(Z_Construct_UEnum_LiDAR_ELocationAxis_Statics::Enumerators),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(Z_Construct_UEnum_LiDAR_ELocationAxis_Statics::Enum_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UEnum_LiDAR_ELocationAxis_Statics::Enum_MetaDataParams))
	};
	UEnum* Z_Construct_UEnum_LiDAR_ELocationAxis()
	{
		if (!Z_Registration_Info_UEnum_ELocationAxis.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ELocationAxis.InnerSingleton, Z_Construct_UEnum_LiDAR_ELocationAxis_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_ELocationAxis.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EMovementType;
	static UEnum* EMovementType_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EMovementType.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EMovementType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_LiDAR_EMovementType, Z_Construct_UPackage__Script_LiDAR(), TEXT("EMovementType"));
		}
		return Z_Registration_Info_UEnum_EMovementType.OuterSingleton;
	}
	template<> LIDAR_API UEnum* StaticEnum<EMovementType>()
	{
		return EMovementType_StaticEnum();
	}
	struct Z_Construct_UEnum_LiDAR_EMovementType_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_LiDAR_EMovementType_Statics::Enumerators[] = {
		{ "EMovementType::Location", (int64)EMovementType::Location },
		{ "EMovementType::Rotation", (int64)EMovementType::Rotation },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_LiDAR_EMovementType_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Location.Name", "EMovementType::Location" },
		{ "ModuleRelativePath", "MovableStaticMeshComponent.h" },
		{ "Rotation.Name", "EMovementType::Rotation" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_LiDAR_EMovementType_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_LiDAR,
		nullptr,
		"EMovementType",
		"EMovementType",
		Z_Construct_UEnum_LiDAR_EMovementType_Statics::Enumerators,
		UE_ARRAY_COUNT(Z_Construct_UEnum_LiDAR_EMovementType_Statics::Enumerators),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(Z_Construct_UEnum_LiDAR_EMovementType_Statics::Enum_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UEnum_LiDAR_EMovementType_Statics::Enum_MetaDataParams))
	};
	UEnum* Z_Construct_UEnum_LiDAR_EMovementType()
	{
		if (!Z_Registration_Info_UEnum_EMovementType.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EMovementType.InnerSingleton, Z_Construct_UEnum_LiDAR_EMovementType_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EMovementType.InnerSingleton;
	}
	DEFINE_FUNCTION(UMovableStaticMeshComponent::execOnMoveFinished)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnMoveFinished();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UMovableStaticMeshComponent::execOnMove)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnMove();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UMovableStaticMeshComponent::execMove)
	{
		P_GET_UBOOL(Z_Param_bTriggered);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Move(Z_Param_bTriggered);
		P_NATIVE_END;
	}
	void UMovableStaticMeshComponent::StaticRegisterNativesUMovableStaticMeshComponent()
	{
		UClass* Class = UMovableStaticMeshComponent::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "Move", &UMovableStaticMeshComponent::execMove },
			{ "OnMove", &UMovableStaticMeshComponent::execOnMove },
			{ "OnMoveFinished", &UMovableStaticMeshComponent::execOnMoveFinished },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UMovableStaticMeshComponent_Move_Statics
	{
		struct MovableStaticMeshComponent_eventMove_Parms
		{
			bool bTriggered;
		};
		static void NewProp_bTriggered_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bTriggered;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UMovableStaticMeshComponent_Move_Statics::NewProp_bTriggered_SetBit(void* Obj)
	{
		((MovableStaticMeshComponent_eventMove_Parms*)Obj)->bTriggered = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UMovableStaticMeshComponent_Move_Statics::NewProp_bTriggered = { "bTriggered", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(MovableStaticMeshComponent_eventMove_Parms), &Z_Construct_UFunction_UMovableStaticMeshComponent_Move_Statics::NewProp_bTriggered_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMovableStaticMeshComponent_Move_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMovableStaticMeshComponent_Move_Statics::NewProp_bTriggered,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMovableStaticMeshComponent_Move_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MovableStaticMeshComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMovableStaticMeshComponent_Move_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMovableStaticMeshComponent, nullptr, "Move", nullptr, nullptr, sizeof(Z_Construct_UFunction_UMovableStaticMeshComponent_Move_Statics::MovableStaticMeshComponent_eventMove_Parms), Z_Construct_UFunction_UMovableStaticMeshComponent_Move_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMovableStaticMeshComponent_Move_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMovableStaticMeshComponent_Move_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMovableStaticMeshComponent_Move_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMovableStaticMeshComponent_Move()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMovableStaticMeshComponent_Move_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMovableStaticMeshComponent_OnMove_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMovableStaticMeshComponent_OnMove_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MovableStaticMeshComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMovableStaticMeshComponent_OnMove_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMovableStaticMeshComponent, nullptr, "OnMove", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMovableStaticMeshComponent_OnMove_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMovableStaticMeshComponent_OnMove_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMovableStaticMeshComponent_OnMove()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMovableStaticMeshComponent_OnMove_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMovableStaticMeshComponent_OnMoveFinished_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMovableStaticMeshComponent_OnMoveFinished_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MovableStaticMeshComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMovableStaticMeshComponent_OnMoveFinished_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMovableStaticMeshComponent, nullptr, "OnMoveFinished", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMovableStaticMeshComponent_OnMoveFinished_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMovableStaticMeshComponent_OnMoveFinished_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMovableStaticMeshComponent_OnMoveFinished()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMovableStaticMeshComponent_OnMoveFinished_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UMovableStaticMeshComponent);
	UClass* Z_Construct_UClass_UMovableStaticMeshComponent_NoRegister()
	{
		return UMovableStaticMeshComponent::StaticClass();
	}
	struct Z_Construct_UClass_UMovableStaticMeshComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MoveCurve_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_MoveCurve;
		static const UECodeGen_Private::FBytePropertyParams NewProp_MovementType_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MovementType_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_MovementType;
		static const UECodeGen_Private::FBytePropertyParams NewProp_RotateAxis_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RotateAxis_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_RotateAxis;
		static const UECodeGen_Private::FBytePropertyParams NewProp_LocationAxis_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LocationAxis_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_LocationAxis;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bIsReversed_MetaData[];
#endif
		static void NewProp_bIsReversed_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsReversed;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UMovableStaticMeshComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UStaticMeshComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_LiDAR,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UMovableStaticMeshComponent_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UMovableStaticMeshComponent_Move, "Move" }, // 1308328273
		{ &Z_Construct_UFunction_UMovableStaticMeshComponent_OnMove, "OnMove" }, // 2296118642
		{ &Z_Construct_UFunction_UMovableStaticMeshComponent_OnMoveFinished, "OnMoveFinished" }, // 1223839201
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMovableStaticMeshComponent_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n *\n */" },
		{ "HideCategories", "Object Activation Components|Activation Trigger" },
		{ "IncludePath", "MovableStaticMeshComponent.h" },
		{ "ModuleRelativePath", "MovableStaticMeshComponent.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMovableStaticMeshComponent_Statics::NewProp_MoveCurve_MetaData[] = {
		{ "Category", "Movement" },
		{ "ModuleRelativePath", "MovableStaticMeshComponent.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UMovableStaticMeshComponent_Statics::NewProp_MoveCurve = { "MoveCurve", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UMovableStaticMeshComponent, MoveCurve), Z_Construct_UClass_UCurveFloat_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UMovableStaticMeshComponent_Statics::NewProp_MoveCurve_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UMovableStaticMeshComponent_Statics::NewProp_MoveCurve_MetaData)) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UMovableStaticMeshComponent_Statics::NewProp_MovementType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMovableStaticMeshComponent_Statics::NewProp_MovementType_MetaData[] = {
		{ "Category", "Movement" },
		{ "ModuleRelativePath", "MovableStaticMeshComponent.h" },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UMovableStaticMeshComponent_Statics::NewProp_MovementType = { "MovementType", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UMovableStaticMeshComponent, MovementType), Z_Construct_UEnum_LiDAR_EMovementType, METADATA_PARAMS(Z_Construct_UClass_UMovableStaticMeshComponent_Statics::NewProp_MovementType_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UMovableStaticMeshComponent_Statics::NewProp_MovementType_MetaData)) }; // 397086101
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UMovableStaticMeshComponent_Statics::NewProp_RotateAxis_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMovableStaticMeshComponent_Statics::NewProp_RotateAxis_MetaData[] = {
		{ "Category", "Movement" },
		{ "EditCondition", "MovementType == EMovementType::Rotation" },
		{ "ModuleRelativePath", "MovableStaticMeshComponent.h" },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UMovableStaticMeshComponent_Statics::NewProp_RotateAxis = { "RotateAxis", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UMovableStaticMeshComponent, RotateAxis), Z_Construct_UEnum_LiDAR_ERotationAxis, METADATA_PARAMS(Z_Construct_UClass_UMovableStaticMeshComponent_Statics::NewProp_RotateAxis_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UMovableStaticMeshComponent_Statics::NewProp_RotateAxis_MetaData)) }; // 1123813309
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UMovableStaticMeshComponent_Statics::NewProp_LocationAxis_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMovableStaticMeshComponent_Statics::NewProp_LocationAxis_MetaData[] = {
		{ "Category", "Movement" },
		{ "EditCondition", "MovementType == EMovementType::Location" },
		{ "ModuleRelativePath", "MovableStaticMeshComponent.h" },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UMovableStaticMeshComponent_Statics::NewProp_LocationAxis = { "LocationAxis", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UMovableStaticMeshComponent, LocationAxis), Z_Construct_UEnum_LiDAR_ELocationAxis, METADATA_PARAMS(Z_Construct_UClass_UMovableStaticMeshComponent_Statics::NewProp_LocationAxis_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UMovableStaticMeshComponent_Statics::NewProp_LocationAxis_MetaData)) }; // 1554268762
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMovableStaticMeshComponent_Statics::NewProp_bIsReversed_MetaData[] = {
		{ "Category", "Movement" },
		{ "ModuleRelativePath", "MovableStaticMeshComponent.h" },
	};
#endif
	void Z_Construct_UClass_UMovableStaticMeshComponent_Statics::NewProp_bIsReversed_SetBit(void* Obj)
	{
		((UMovableStaticMeshComponent*)Obj)->bIsReversed = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UMovableStaticMeshComponent_Statics::NewProp_bIsReversed = { "bIsReversed", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UMovableStaticMeshComponent), &Z_Construct_UClass_UMovableStaticMeshComponent_Statics::NewProp_bIsReversed_SetBit, METADATA_PARAMS(Z_Construct_UClass_UMovableStaticMeshComponent_Statics::NewProp_bIsReversed_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UMovableStaticMeshComponent_Statics::NewProp_bIsReversed_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UMovableStaticMeshComponent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMovableStaticMeshComponent_Statics::NewProp_MoveCurve,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMovableStaticMeshComponent_Statics::NewProp_MovementType_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMovableStaticMeshComponent_Statics::NewProp_MovementType,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMovableStaticMeshComponent_Statics::NewProp_RotateAxis_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMovableStaticMeshComponent_Statics::NewProp_RotateAxis,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMovableStaticMeshComponent_Statics::NewProp_LocationAxis_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMovableStaticMeshComponent_Statics::NewProp_LocationAxis,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMovableStaticMeshComponent_Statics::NewProp_bIsReversed,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UMovableStaticMeshComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMovableStaticMeshComponent>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UMovableStaticMeshComponent_Statics::ClassParams = {
		&UMovableStaticMeshComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UMovableStaticMeshComponent_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UMovableStaticMeshComponent_Statics::PropPointers),
		0,
		0x00B010A4u,
		METADATA_PARAMS(Z_Construct_UClass_UMovableStaticMeshComponent_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UMovableStaticMeshComponent_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UMovableStaticMeshComponent()
	{
		if (!Z_Registration_Info_UClass_UMovableStaticMeshComponent.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMovableStaticMeshComponent.OuterSingleton, Z_Construct_UClass_UMovableStaticMeshComponent_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UMovableStaticMeshComponent.OuterSingleton;
	}
	template<> LIDAR_API UClass* StaticClass<UMovableStaticMeshComponent>()
	{
		return UMovableStaticMeshComponent::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UMovableStaticMeshComponent);
	struct Z_CompiledInDeferFile_FID_LiDAR_Source_LiDAR_MovableStaticMeshComponent_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_LiDAR_Source_LiDAR_MovableStaticMeshComponent_h_Statics::EnumInfo[] = {
		{ ERotationAxis_StaticEnum, TEXT("ERotationAxis"), &Z_Registration_Info_UEnum_ERotationAxis, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1123813309U) },
		{ ELocationAxis_StaticEnum, TEXT("ELocationAxis"), &Z_Registration_Info_UEnum_ELocationAxis, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1554268762U) },
		{ EMovementType_StaticEnum, TEXT("EMovementType"), &Z_Registration_Info_UEnum_EMovementType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 397086101U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_LiDAR_Source_LiDAR_MovableStaticMeshComponent_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UMovableStaticMeshComponent, UMovableStaticMeshComponent::StaticClass, TEXT("UMovableStaticMeshComponent"), &Z_Registration_Info_UClass_UMovableStaticMeshComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMovableStaticMeshComponent), 4023849575U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_LiDAR_Source_LiDAR_MovableStaticMeshComponent_h_1197760758(TEXT("/Script/LiDAR"),
		Z_CompiledInDeferFile_FID_LiDAR_Source_LiDAR_MovableStaticMeshComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_LiDAR_Source_LiDAR_MovableStaticMeshComponent_h_Statics::ClassInfo),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_LiDAR_Source_LiDAR_MovableStaticMeshComponent_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_LiDAR_Source_LiDAR_MovableStaticMeshComponent_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
