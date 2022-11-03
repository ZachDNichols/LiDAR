// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LiDAR/MovingStaticMeshActor.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMovingStaticMeshActor() {}
// Cross Module References
	LIDAR_API UEnum* Z_Construct_UEnum_LiDAR_EActorRotationAxis();
	UPackage* Z_Construct_UPackage__Script_LiDAR();
	LIDAR_API UEnum* Z_Construct_UEnum_LiDAR_EActorLocationAxis();
	LIDAR_API UEnum* Z_Construct_UEnum_LiDAR_EActorMovementType();
	LIDAR_API UClass* Z_Construct_UClass_AMovingStaticMeshActor_NoRegister();
	LIDAR_API UClass* Z_Construct_UClass_AMovingStaticMeshActor();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	ENGINE_API UClass* Z_Construct_UClass_UCurveFloat_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	LIDAR_API UClass* Z_Construct_UClass_UInteractableInterface_NoRegister();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EActorRotationAxis;
	static UEnum* EActorRotationAxis_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EActorRotationAxis.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EActorRotationAxis.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_LiDAR_EActorRotationAxis, Z_Construct_UPackage__Script_LiDAR(), TEXT("EActorRotationAxis"));
		}
		return Z_Registration_Info_UEnum_EActorRotationAxis.OuterSingleton;
	}
	template<> LIDAR_API UEnum* StaticEnum<EActorRotationAxis>()
	{
		return EActorRotationAxis_StaticEnum();
	}
	struct Z_Construct_UEnum_LiDAR_EActorRotationAxis_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_LiDAR_EActorRotationAxis_Statics::Enumerators[] = {
		{ "EActorRotationAxis::Yaw", (int64)EActorRotationAxis::Yaw },
		{ "EActorRotationAxis::Pitch", (int64)EActorRotationAxis::Pitch },
		{ "EActorRotationAxis::Roll", (int64)EActorRotationAxis::Roll },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_LiDAR_EActorRotationAxis_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "MovingStaticMeshActor.h" },
		{ "Pitch.Name", "EActorRotationAxis::Pitch" },
		{ "Roll.Name", "EActorRotationAxis::Roll" },
		{ "Yaw.Name", "EActorRotationAxis::Yaw" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_LiDAR_EActorRotationAxis_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_LiDAR,
		nullptr,
		"EActorRotationAxis",
		"EActorRotationAxis",
		Z_Construct_UEnum_LiDAR_EActorRotationAxis_Statics::Enumerators,
		UE_ARRAY_COUNT(Z_Construct_UEnum_LiDAR_EActorRotationAxis_Statics::Enumerators),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(Z_Construct_UEnum_LiDAR_EActorRotationAxis_Statics::Enum_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UEnum_LiDAR_EActorRotationAxis_Statics::Enum_MetaDataParams))
	};
	UEnum* Z_Construct_UEnum_LiDAR_EActorRotationAxis()
	{
		if (!Z_Registration_Info_UEnum_EActorRotationAxis.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EActorRotationAxis.InnerSingleton, Z_Construct_UEnum_LiDAR_EActorRotationAxis_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EActorRotationAxis.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EActorLocationAxis;
	static UEnum* EActorLocationAxis_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EActorLocationAxis.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EActorLocationAxis.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_LiDAR_EActorLocationAxis, Z_Construct_UPackage__Script_LiDAR(), TEXT("EActorLocationAxis"));
		}
		return Z_Registration_Info_UEnum_EActorLocationAxis.OuterSingleton;
	}
	template<> LIDAR_API UEnum* StaticEnum<EActorLocationAxis>()
	{
		return EActorLocationAxis_StaticEnum();
	}
	struct Z_Construct_UEnum_LiDAR_EActorLocationAxis_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_LiDAR_EActorLocationAxis_Statics::Enumerators[] = {
		{ "EActorLocationAxis::X", (int64)EActorLocationAxis::X },
		{ "EActorLocationAxis::Y", (int64)EActorLocationAxis::Y },
		{ "EActorLocationAxis::Z", (int64)EActorLocationAxis::Z },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_LiDAR_EActorLocationAxis_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "MovingStaticMeshActor.h" },
		{ "X.Name", "EActorLocationAxis::X" },
		{ "Y.Name", "EActorLocationAxis::Y" },
		{ "Z.Name", "EActorLocationAxis::Z" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_LiDAR_EActorLocationAxis_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_LiDAR,
		nullptr,
		"EActorLocationAxis",
		"EActorLocationAxis",
		Z_Construct_UEnum_LiDAR_EActorLocationAxis_Statics::Enumerators,
		UE_ARRAY_COUNT(Z_Construct_UEnum_LiDAR_EActorLocationAxis_Statics::Enumerators),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(Z_Construct_UEnum_LiDAR_EActorLocationAxis_Statics::Enum_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UEnum_LiDAR_EActorLocationAxis_Statics::Enum_MetaDataParams))
	};
	UEnum* Z_Construct_UEnum_LiDAR_EActorLocationAxis()
	{
		if (!Z_Registration_Info_UEnum_EActorLocationAxis.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EActorLocationAxis.InnerSingleton, Z_Construct_UEnum_LiDAR_EActorLocationAxis_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EActorLocationAxis.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EActorMovementType;
	static UEnum* EActorMovementType_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EActorMovementType.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EActorMovementType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_LiDAR_EActorMovementType, Z_Construct_UPackage__Script_LiDAR(), TEXT("EActorMovementType"));
		}
		return Z_Registration_Info_UEnum_EActorMovementType.OuterSingleton;
	}
	template<> LIDAR_API UEnum* StaticEnum<EActorMovementType>()
	{
		return EActorMovementType_StaticEnum();
	}
	struct Z_Construct_UEnum_LiDAR_EActorMovementType_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_LiDAR_EActorMovementType_Statics::Enumerators[] = {
		{ "EActorMovementType::Location", (int64)EActorMovementType::Location },
		{ "EActorMovementType::Rotation", (int64)EActorMovementType::Rotation },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_LiDAR_EActorMovementType_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Location.Name", "EActorMovementType::Location" },
		{ "ModuleRelativePath", "MovingStaticMeshActor.h" },
		{ "Rotation.Name", "EActorMovementType::Rotation" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_LiDAR_EActorMovementType_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_LiDAR,
		nullptr,
		"EActorMovementType",
		"EActorMovementType",
		Z_Construct_UEnum_LiDAR_EActorMovementType_Statics::Enumerators,
		UE_ARRAY_COUNT(Z_Construct_UEnum_LiDAR_EActorMovementType_Statics::Enumerators),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(Z_Construct_UEnum_LiDAR_EActorMovementType_Statics::Enum_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UEnum_LiDAR_EActorMovementType_Statics::Enum_MetaDataParams))
	};
	UEnum* Z_Construct_UEnum_LiDAR_EActorMovementType()
	{
		if (!Z_Registration_Info_UEnum_EActorMovementType.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EActorMovementType.InnerSingleton, Z_Construct_UEnum_LiDAR_EActorMovementType_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EActorMovementType.InnerSingleton;
	}
	DEFINE_FUNCTION(AMovingStaticMeshActor::execMove)
	{
		P_GET_UBOOL(Z_Param_bTriggered);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Move(Z_Param_bTriggered);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AMovingStaticMeshActor::execOnMoveFinished)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnMoveFinished();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AMovingStaticMeshActor::execOnMove)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnMove();
		P_NATIVE_END;
	}
	void AMovingStaticMeshActor::StaticRegisterNativesAMovingStaticMeshActor()
	{
		UClass* Class = AMovingStaticMeshActor::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "Move", &AMovingStaticMeshActor::execMove },
			{ "OnMove", &AMovingStaticMeshActor::execOnMove },
			{ "OnMoveFinished", &AMovingStaticMeshActor::execOnMoveFinished },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AMovingStaticMeshActor_Move_Statics
	{
		struct MovingStaticMeshActor_eventMove_Parms
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
	void Z_Construct_UFunction_AMovingStaticMeshActor_Move_Statics::NewProp_bTriggered_SetBit(void* Obj)
	{
		((MovingStaticMeshActor_eventMove_Parms*)Obj)->bTriggered = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AMovingStaticMeshActor_Move_Statics::NewProp_bTriggered = { "bTriggered", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(MovingStaticMeshActor_eventMove_Parms), &Z_Construct_UFunction_AMovingStaticMeshActor_Move_Statics::NewProp_bTriggered_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMovingStaticMeshActor_Move_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMovingStaticMeshActor_Move_Statics::NewProp_bTriggered,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMovingStaticMeshActor_Move_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MovingStaticMeshActor.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMovingStaticMeshActor_Move_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMovingStaticMeshActor, nullptr, "Move", nullptr, nullptr, sizeof(Z_Construct_UFunction_AMovingStaticMeshActor_Move_Statics::MovingStaticMeshActor_eventMove_Parms), Z_Construct_UFunction_AMovingStaticMeshActor_Move_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMovingStaticMeshActor_Move_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMovingStaticMeshActor_Move_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AMovingStaticMeshActor_Move_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMovingStaticMeshActor_Move()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMovingStaticMeshActor_Move_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMovingStaticMeshActor_OnMove_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMovingStaticMeshActor_OnMove_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MovingStaticMeshActor.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMovingStaticMeshActor_OnMove_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMovingStaticMeshActor, nullptr, "OnMove", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMovingStaticMeshActor_OnMove_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AMovingStaticMeshActor_OnMove_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMovingStaticMeshActor_OnMove()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMovingStaticMeshActor_OnMove_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMovingStaticMeshActor_OnMoveFinished_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMovingStaticMeshActor_OnMoveFinished_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MovingStaticMeshActor.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMovingStaticMeshActor_OnMoveFinished_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMovingStaticMeshActor, nullptr, "OnMoveFinished", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMovingStaticMeshActor_OnMoveFinished_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AMovingStaticMeshActor_OnMoveFinished_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMovingStaticMeshActor_OnMoveFinished()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMovingStaticMeshActor_OnMoveFinished_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AMovingStaticMeshActor);
	UClass* Z_Construct_UClass_AMovingStaticMeshActor_NoRegister()
	{
		return AMovingStaticMeshActor::StaticClass();
	}
	struct Z_Construct_UClass_AMovingStaticMeshActor_Statics
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
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Mesh_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Mesh;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ObjectID_MetaData[];
#endif
		static const UECodeGen_Private::FUnsizedIntPropertyParams NewProp_ObjectID;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bIsDisabled_MetaData[];
#endif
		static void NewProp_bIsDisabled_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsDisabled;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMovingStaticMeshActor_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_LiDAR,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AMovingStaticMeshActor_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AMovingStaticMeshActor_Move, "Move" }, // 2573080190
		{ &Z_Construct_UFunction_AMovingStaticMeshActor_OnMove, "OnMove" }, // 4159703682
		{ &Z_Construct_UFunction_AMovingStaticMeshActor_OnMoveFinished, "OnMoveFinished" }, // 198867073
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMovingStaticMeshActor_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "MovingStaticMeshActor.h" },
		{ "ModuleRelativePath", "MovingStaticMeshActor.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMovingStaticMeshActor_Statics::NewProp_MoveCurve_MetaData[] = {
		{ "Category", "Movement" },
		{ "ModuleRelativePath", "MovingStaticMeshActor.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMovingStaticMeshActor_Statics::NewProp_MoveCurve = { "MoveCurve", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMovingStaticMeshActor, MoveCurve), Z_Construct_UClass_UCurveFloat_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMovingStaticMeshActor_Statics::NewProp_MoveCurve_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMovingStaticMeshActor_Statics::NewProp_MoveCurve_MetaData)) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_AMovingStaticMeshActor_Statics::NewProp_MovementType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMovingStaticMeshActor_Statics::NewProp_MovementType_MetaData[] = {
		{ "Category", "Movement" },
		{ "ModuleRelativePath", "MovingStaticMeshActor.h" },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_AMovingStaticMeshActor_Statics::NewProp_MovementType = { "MovementType", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMovingStaticMeshActor, MovementType), Z_Construct_UEnum_LiDAR_EActorMovementType, METADATA_PARAMS(Z_Construct_UClass_AMovingStaticMeshActor_Statics::NewProp_MovementType_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMovingStaticMeshActor_Statics::NewProp_MovementType_MetaData)) }; // 2126290303
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_AMovingStaticMeshActor_Statics::NewProp_RotateAxis_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMovingStaticMeshActor_Statics::NewProp_RotateAxis_MetaData[] = {
		{ "Category", "Movement" },
		{ "EditCondition", "MovementType == EActorMovementType::Rotation" },
		{ "ModuleRelativePath", "MovingStaticMeshActor.h" },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_AMovingStaticMeshActor_Statics::NewProp_RotateAxis = { "RotateAxis", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMovingStaticMeshActor, RotateAxis), Z_Construct_UEnum_LiDAR_EActorRotationAxis, METADATA_PARAMS(Z_Construct_UClass_AMovingStaticMeshActor_Statics::NewProp_RotateAxis_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMovingStaticMeshActor_Statics::NewProp_RotateAxis_MetaData)) }; // 3767617239
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_AMovingStaticMeshActor_Statics::NewProp_LocationAxis_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMovingStaticMeshActor_Statics::NewProp_LocationAxis_MetaData[] = {
		{ "Category", "Movement" },
		{ "EditCondition", "MovementType == EActorMovementType::Location" },
		{ "ModuleRelativePath", "MovingStaticMeshActor.h" },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_AMovingStaticMeshActor_Statics::NewProp_LocationAxis = { "LocationAxis", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMovingStaticMeshActor, LocationAxis), Z_Construct_UEnum_LiDAR_EActorLocationAxis, METADATA_PARAMS(Z_Construct_UClass_AMovingStaticMeshActor_Statics::NewProp_LocationAxis_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMovingStaticMeshActor_Statics::NewProp_LocationAxis_MetaData)) }; // 1722645987
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMovingStaticMeshActor_Statics::NewProp_bIsReversed_MetaData[] = {
		{ "Category", "Movement" },
		{ "ModuleRelativePath", "MovingStaticMeshActor.h" },
	};
#endif
	void Z_Construct_UClass_AMovingStaticMeshActor_Statics::NewProp_bIsReversed_SetBit(void* Obj)
	{
		((AMovingStaticMeshActor*)Obj)->bIsReversed = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AMovingStaticMeshActor_Statics::NewProp_bIsReversed = { "bIsReversed", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AMovingStaticMeshActor), &Z_Construct_UClass_AMovingStaticMeshActor_Statics::NewProp_bIsReversed_SetBit, METADATA_PARAMS(Z_Construct_UClass_AMovingStaticMeshActor_Statics::NewProp_bIsReversed_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMovingStaticMeshActor_Statics::NewProp_bIsReversed_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMovingStaticMeshActor_Statics::NewProp_Mesh_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Moving" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "MovingStaticMeshActor.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMovingStaticMeshActor_Statics::NewProp_Mesh = { "Mesh", nullptr, (EPropertyFlags)0x00100000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMovingStaticMeshActor, Mesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMovingStaticMeshActor_Statics::NewProp_Mesh_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMovingStaticMeshActor_Statics::NewProp_Mesh_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMovingStaticMeshActor_Statics::NewProp_ObjectID_MetaData[] = {
		{ "Category", "Moving" },
		{ "ModuleRelativePath", "MovingStaticMeshActor.h" },
	};
#endif
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_AMovingStaticMeshActor_Statics::NewProp_ObjectID = { "ObjectID", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMovingStaticMeshActor, ObjectID), METADATA_PARAMS(Z_Construct_UClass_AMovingStaticMeshActor_Statics::NewProp_ObjectID_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMovingStaticMeshActor_Statics::NewProp_ObjectID_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMovingStaticMeshActor_Statics::NewProp_bIsDisabled_MetaData[] = {
		{ "Category", "Moving" },
		{ "ModuleRelativePath", "MovingStaticMeshActor.h" },
	};
#endif
	void Z_Construct_UClass_AMovingStaticMeshActor_Statics::NewProp_bIsDisabled_SetBit(void* Obj)
	{
		((AMovingStaticMeshActor*)Obj)->bIsDisabled = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AMovingStaticMeshActor_Statics::NewProp_bIsDisabled = { "bIsDisabled", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AMovingStaticMeshActor), &Z_Construct_UClass_AMovingStaticMeshActor_Statics::NewProp_bIsDisabled_SetBit, METADATA_PARAMS(Z_Construct_UClass_AMovingStaticMeshActor_Statics::NewProp_bIsDisabled_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMovingStaticMeshActor_Statics::NewProp_bIsDisabled_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AMovingStaticMeshActor_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMovingStaticMeshActor_Statics::NewProp_MoveCurve,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMovingStaticMeshActor_Statics::NewProp_MovementType_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMovingStaticMeshActor_Statics::NewProp_MovementType,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMovingStaticMeshActor_Statics::NewProp_RotateAxis_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMovingStaticMeshActor_Statics::NewProp_RotateAxis,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMovingStaticMeshActor_Statics::NewProp_LocationAxis_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMovingStaticMeshActor_Statics::NewProp_LocationAxis,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMovingStaticMeshActor_Statics::NewProp_bIsReversed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMovingStaticMeshActor_Statics::NewProp_Mesh,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMovingStaticMeshActor_Statics::NewProp_ObjectID,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMovingStaticMeshActor_Statics::NewProp_bIsDisabled,
	};
		const UECodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_AMovingStaticMeshActor_Statics::InterfaceParams[] = {
			{ Z_Construct_UClass_UInteractableInterface_NoRegister, (int32)VTABLE_OFFSET(AMovingStaticMeshActor, IInteractableInterface), false },  // 954022642
		};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMovingStaticMeshActor_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMovingStaticMeshActor>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AMovingStaticMeshActor_Statics::ClassParams = {
		&AMovingStaticMeshActor::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AMovingStaticMeshActor_Statics::PropPointers,
		InterfaceParams,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AMovingStaticMeshActor_Statics::PropPointers),
		UE_ARRAY_COUNT(InterfaceParams),
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AMovingStaticMeshActor_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AMovingStaticMeshActor_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AMovingStaticMeshActor()
	{
		if (!Z_Registration_Info_UClass_AMovingStaticMeshActor.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AMovingStaticMeshActor.OuterSingleton, Z_Construct_UClass_AMovingStaticMeshActor_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AMovingStaticMeshActor.OuterSingleton;
	}
	template<> LIDAR_API UClass* StaticClass<AMovingStaticMeshActor>()
	{
		return AMovingStaticMeshActor::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMovingStaticMeshActor);
	struct Z_CompiledInDeferFile_FID_LiDAR_Source_LiDAR_MovingStaticMeshActor_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_LiDAR_Source_LiDAR_MovingStaticMeshActor_h_Statics::EnumInfo[] = {
		{ EActorRotationAxis_StaticEnum, TEXT("EActorRotationAxis"), &Z_Registration_Info_UEnum_EActorRotationAxis, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3767617239U) },
		{ EActorLocationAxis_StaticEnum, TEXT("EActorLocationAxis"), &Z_Registration_Info_UEnum_EActorLocationAxis, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1722645987U) },
		{ EActorMovementType_StaticEnum, TEXT("EActorMovementType"), &Z_Registration_Info_UEnum_EActorMovementType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2126290303U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_LiDAR_Source_LiDAR_MovingStaticMeshActor_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AMovingStaticMeshActor, AMovingStaticMeshActor::StaticClass, TEXT("AMovingStaticMeshActor"), &Z_Registration_Info_UClass_AMovingStaticMeshActor, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AMovingStaticMeshActor), 2208435179U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_LiDAR_Source_LiDAR_MovingStaticMeshActor_h_3400606109(TEXT("/Script/LiDAR"),
		Z_CompiledInDeferFile_FID_LiDAR_Source_LiDAR_MovingStaticMeshActor_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_LiDAR_Source_LiDAR_MovingStaticMeshActor_h_Statics::ClassInfo),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_LiDAR_Source_LiDAR_MovingStaticMeshActor_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_LiDAR_Source_LiDAR_MovingStaticMeshActor_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
