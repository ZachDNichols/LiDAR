// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LiDAR/LEMON.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLEMON() {}
// Cross Module References
	LIDAR_API UClass* Z_Construct_UClass_ALEMON_NoRegister();
	LIDAR_API UClass* Z_Construct_UClass_ALEMON();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_LiDAR();
	LIDAR_API UClass* Z_Construct_UClass_AFirstPersonCharacter_NoRegister();
	ENGINE_API UEnum* Z_Construct_UEnum_Engine_EEndPlayReason();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	LIDAR_API UClass* Z_Construct_UClass_ALaser_NoRegister();
	LIDAR_API UClass* Z_Construct_UClass_ADot_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UWidgetComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USkeletalMeshComponent_NoRegister();
	LIDAR_API UClass* Z_Construct_UClass_UWeaponPickupComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USoundBase_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(ALEMON::execEndPlay)
	{
		P_GET_PROPERTY(FByteProperty,Z_Param_EndPlayReason);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->EndPlay(EEndPlayReason::Type(Z_Param_EndPlayReason));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ALEMON::execChangeRadius)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ChangeRadius();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ALEMON::execEndFire)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->EndFire();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ALEMON::execFire)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Fire();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ALEMON::execAttachWeapon)
	{
		P_GET_OBJECT(AFirstPersonCharacter,Z_Param_TargetCharacter);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->AttachWeapon(Z_Param_TargetCharacter);
		P_NATIVE_END;
	}
	void ALEMON::StaticRegisterNativesALEMON()
	{
		UClass* Class = ALEMON::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "AttachWeapon", &ALEMON::execAttachWeapon },
			{ "ChangeRadius", &ALEMON::execChangeRadius },
			{ "EndFire", &ALEMON::execEndFire },
			{ "EndPlay", &ALEMON::execEndPlay },
			{ "Fire", &ALEMON::execFire },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ALEMON_AttachWeapon_Statics
	{
		struct LEMON_eventAttachWeapon_Parms
		{
			AFirstPersonCharacter* TargetCharacter;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_TargetCharacter;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ALEMON_AttachWeapon_Statics::NewProp_TargetCharacter = { "TargetCharacter", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(LEMON_eventAttachWeapon_Parms, TargetCharacter), Z_Construct_UClass_AFirstPersonCharacter_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ALEMON_AttachWeapon_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ALEMON_AttachWeapon_Statics::NewProp_TargetCharacter,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ALEMON_AttachWeapon_Statics::Function_MetaDataParams[] = {
		{ "Category", "Weapon" },
		{ "ModuleRelativePath", "LEMON.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ALEMON_AttachWeapon_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ALEMON, nullptr, "AttachWeapon", nullptr, nullptr, sizeof(Z_Construct_UFunction_ALEMON_AttachWeapon_Statics::LEMON_eventAttachWeapon_Parms), Z_Construct_UFunction_ALEMON_AttachWeapon_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ALEMON_AttachWeapon_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ALEMON_AttachWeapon_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ALEMON_AttachWeapon_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ALEMON_AttachWeapon()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ALEMON_AttachWeapon_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ALEMON_ChangeRadius_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ALEMON_ChangeRadius_Statics::Function_MetaDataParams[] = {
		{ "Category", "Weapon" },
		{ "ModuleRelativePath", "LEMON.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ALEMON_ChangeRadius_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ALEMON, nullptr, "ChangeRadius", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ALEMON_ChangeRadius_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ALEMON_ChangeRadius_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ALEMON_ChangeRadius()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ALEMON_ChangeRadius_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ALEMON_EndFire_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ALEMON_EndFire_Statics::Function_MetaDataParams[] = {
		{ "Category", "Weapon" },
		{ "ModuleRelativePath", "LEMON.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ALEMON_EndFire_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ALEMON, nullptr, "EndFire", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ALEMON_EndFire_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ALEMON_EndFire_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ALEMON_EndFire()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ALEMON_EndFire_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ALEMON_EndPlay_Statics
	{
		struct LEMON_eventEndPlay_Parms
		{
			TEnumAsByte<EEndPlayReason::Type> EndPlayReason;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_EndPlayReason_MetaData[];
#endif
		static const UECodeGen_Private::FBytePropertyParams NewProp_EndPlayReason;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ALEMON_EndPlay_Statics::NewProp_EndPlayReason_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_ALEMON_EndPlay_Statics::NewProp_EndPlayReason = { "EndPlayReason", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(LEMON_eventEndPlay_Parms, EndPlayReason), Z_Construct_UEnum_Engine_EEndPlayReason, METADATA_PARAMS(Z_Construct_UFunction_ALEMON_EndPlay_Statics::NewProp_EndPlayReason_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ALEMON_EndPlay_Statics::NewProp_EndPlayReason_MetaData)) }; // 2713016423
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ALEMON_EndPlay_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ALEMON_EndPlay_Statics::NewProp_EndPlayReason,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ALEMON_EndPlay_Statics::Function_MetaDataParams[] = {
		{ "Comment", "/** Ends gameplay for this component. */" },
		{ "ModuleRelativePath", "LEMON.h" },
		{ "ToolTip", "Ends gameplay for this component." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ALEMON_EndPlay_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ALEMON, nullptr, "EndPlay", nullptr, nullptr, sizeof(Z_Construct_UFunction_ALEMON_EndPlay_Statics::LEMON_eventEndPlay_Parms), Z_Construct_UFunction_ALEMON_EndPlay_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ALEMON_EndPlay_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020400, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ALEMON_EndPlay_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ALEMON_EndPlay_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ALEMON_EndPlay()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ALEMON_EndPlay_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ALEMON_Fire_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ALEMON_Fire_Statics::Function_MetaDataParams[] = {
		{ "Category", "Weapon" },
		{ "ModuleRelativePath", "LEMON.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ALEMON_Fire_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ALEMON, nullptr, "Fire", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ALEMON_Fire_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ALEMON_Fire_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ALEMON_Fire()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ALEMON_Fire_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ALEMON);
	UClass* Z_Construct_UClass_ALEMON_NoRegister()
	{
		return ALEMON::StaticClass();
	}
	struct Z_Construct_UClass_ALEMON_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LaserBP_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_LaserBP;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LaserBeam_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_LaserBeam;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DotBP_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_DotBP;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Dot_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Dot;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_WidgetComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WidgetComponent;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Mesh_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Mesh;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PickUp_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_PickUp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Sound_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Sound;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ALEMON_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_LiDAR,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ALEMON_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ALEMON_AttachWeapon, "AttachWeapon" }, // 3156075526
		{ &Z_Construct_UFunction_ALEMON_ChangeRadius, "ChangeRadius" }, // 2795810034
		{ &Z_Construct_UFunction_ALEMON_EndFire, "EndFire" }, // 1610577081
		{ &Z_Construct_UFunction_ALEMON_EndPlay, "EndPlay" }, // 3277934735
		{ &Z_Construct_UFunction_ALEMON_Fire, "Fire" }, // 3958647029
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ALEMON_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "BlueprintType", "true" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "LEMON.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "LEMON.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ALEMON_Statics::NewProp_LaserBP_MetaData[] = {
		{ "Category", "LEMON" },
		{ "ModuleRelativePath", "LEMON.h" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_ALEMON_Statics::NewProp_LaserBP = { "LaserBP", nullptr, (EPropertyFlags)0x0014000000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ALEMON, LaserBP), Z_Construct_UClass_ALaser_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_ALEMON_Statics::NewProp_LaserBP_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ALEMON_Statics::NewProp_LaserBP_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ALEMON_Statics::NewProp_LaserBeam_MetaData[] = {
		{ "ModuleRelativePath", "LEMON.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ALEMON_Statics::NewProp_LaserBeam = { "LaserBeam", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ALEMON, LaserBeam), Z_Construct_UClass_ALaser_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ALEMON_Statics::NewProp_LaserBeam_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ALEMON_Statics::NewProp_LaserBeam_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ALEMON_Statics::NewProp_DotBP_MetaData[] = {
		{ "Category", "LEMON" },
		{ "ModuleRelativePath", "LEMON.h" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_ALEMON_Statics::NewProp_DotBP = { "DotBP", nullptr, (EPropertyFlags)0x0014000000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ALEMON, DotBP), Z_Construct_UClass_ADot_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_ALEMON_Statics::NewProp_DotBP_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ALEMON_Statics::NewProp_DotBP_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ALEMON_Statics::NewProp_Dot_MetaData[] = {
		{ "ModuleRelativePath", "LEMON.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ALEMON_Statics::NewProp_Dot = { "Dot", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ALEMON, Dot), Z_Construct_UClass_ADot_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ALEMON_Statics::NewProp_Dot_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ALEMON_Statics::NewProp_Dot_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ALEMON_Statics::NewProp_WidgetComponent_MetaData[] = {
		{ "Category", "LEMON" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "LEMON.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ALEMON_Statics::NewProp_WidgetComponent = { "WidgetComponent", nullptr, (EPropertyFlags)0x0010000000080009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ALEMON, WidgetComponent), Z_Construct_UClass_UWidgetComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ALEMON_Statics::NewProp_WidgetComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ALEMON_Statics::NewProp_WidgetComponent_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ALEMON_Statics::NewProp_Mesh_MetaData[] = {
		{ "Category", "Mesh" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "LEMON.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ALEMON_Statics::NewProp_Mesh = { "Mesh", nullptr, (EPropertyFlags)0x00100000000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ALEMON, Mesh), Z_Construct_UClass_USkeletalMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ALEMON_Statics::NewProp_Mesh_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ALEMON_Statics::NewProp_Mesh_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ALEMON_Statics::NewProp_PickUp_MetaData[] = {
		{ "Category", "PickUp" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "LEMON.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ALEMON_Statics::NewProp_PickUp = { "PickUp", nullptr, (EPropertyFlags)0x00100000000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ALEMON, PickUp), Z_Construct_UClass_UWeaponPickupComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ALEMON_Statics::NewProp_PickUp_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ALEMON_Statics::NewProp_PickUp_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ALEMON_Statics::NewProp_Sound_MetaData[] = {
		{ "Category", "SFX" },
		{ "ModuleRelativePath", "LEMON.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ALEMON_Statics::NewProp_Sound = { "Sound", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ALEMON, Sound), Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ALEMON_Statics::NewProp_Sound_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ALEMON_Statics::NewProp_Sound_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ALEMON_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ALEMON_Statics::NewProp_LaserBP,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ALEMON_Statics::NewProp_LaserBeam,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ALEMON_Statics::NewProp_DotBP,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ALEMON_Statics::NewProp_Dot,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ALEMON_Statics::NewProp_WidgetComponent,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ALEMON_Statics::NewProp_Mesh,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ALEMON_Statics::NewProp_PickUp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ALEMON_Statics::NewProp_Sound,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ALEMON_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ALEMON>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ALEMON_Statics::ClassParams = {
		&ALEMON::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ALEMON_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ALEMON_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ALEMON_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ALEMON_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ALEMON()
	{
		if (!Z_Registration_Info_UClass_ALEMON.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ALEMON.OuterSingleton, Z_Construct_UClass_ALEMON_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ALEMON.OuterSingleton;
	}
	template<> LIDAR_API UClass* StaticClass<ALEMON>()
	{
		return ALEMON::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ALEMON);
	struct Z_CompiledInDeferFile_FID_LiDAR_Source_LiDAR_LEMON_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_LiDAR_Source_LiDAR_LEMON_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ALEMON, ALEMON::StaticClass, TEXT("ALEMON"), &Z_Registration_Info_UClass_ALEMON, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ALEMON), 2534496944U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_LiDAR_Source_LiDAR_LEMON_h_1309792586(TEXT("/Script/LiDAR"),
		Z_CompiledInDeferFile_FID_LiDAR_Source_LiDAR_LEMON_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_LiDAR_Source_LiDAR_LEMON_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
