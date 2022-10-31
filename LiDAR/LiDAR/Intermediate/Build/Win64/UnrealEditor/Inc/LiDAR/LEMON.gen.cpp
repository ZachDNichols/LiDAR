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
	LIDAR_API UClass* Z_Construct_UClass_ULEMON_NoRegister();
	LIDAR_API UClass* Z_Construct_UClass_ULEMON();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	UPackage* Z_Construct_UPackage__Script_LiDAR();
	LIDAR_API UClass* Z_Construct_UClass_AFirstPersonCharacter_NoRegister();
	ENGINE_API UEnum* Z_Construct_UEnum_Engine_EEndPlayReason();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	LIDAR_API UClass* Z_Construct_UClass_ALaser_NoRegister();
	LIDAR_API UClass* Z_Construct_UClass_ADot_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(ULEMON::execEndPlay)
	{
		P_GET_PROPERTY(FByteProperty,Z_Param_EndPlayReason);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->EndPlay(EEndPlayReason::Type(Z_Param_EndPlayReason));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ULEMON::execChangeRadius)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ChangeRadius();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ULEMON::execEndFire)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->EndFire();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ULEMON::execFire)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Fire();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ULEMON::execAttachWeapon)
	{
		P_GET_OBJECT(AFirstPersonCharacter,Z_Param_TargetCharacter);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->AttachWeapon(Z_Param_TargetCharacter);
		P_NATIVE_END;
	}
	void ULEMON::StaticRegisterNativesULEMON()
	{
		UClass* Class = ULEMON::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "AttachWeapon", &ULEMON::execAttachWeapon },
			{ "ChangeRadius", &ULEMON::execChangeRadius },
			{ "EndFire", &ULEMON::execEndFire },
			{ "EndPlay", &ULEMON::execEndPlay },
			{ "Fire", &ULEMON::execFire },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ULEMON_AttachWeapon_Statics
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
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ULEMON_AttachWeapon_Statics::NewProp_TargetCharacter = { "TargetCharacter", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(LEMON_eventAttachWeapon_Parms, TargetCharacter), Z_Construct_UClass_AFirstPersonCharacter_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULEMON_AttachWeapon_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULEMON_AttachWeapon_Statics::NewProp_TargetCharacter,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULEMON_AttachWeapon_Statics::Function_MetaDataParams[] = {
		{ "Category", "Weapon" },
		{ "ModuleRelativePath", "LEMON.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULEMON_AttachWeapon_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULEMON, nullptr, "AttachWeapon", nullptr, nullptr, sizeof(Z_Construct_UFunction_ULEMON_AttachWeapon_Statics::LEMON_eventAttachWeapon_Parms), Z_Construct_UFunction_ULEMON_AttachWeapon_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULEMON_AttachWeapon_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULEMON_AttachWeapon_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ULEMON_AttachWeapon_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULEMON_AttachWeapon()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULEMON_AttachWeapon_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULEMON_ChangeRadius_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULEMON_ChangeRadius_Statics::Function_MetaDataParams[] = {
		{ "Category", "Weapon" },
		{ "ModuleRelativePath", "LEMON.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULEMON_ChangeRadius_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULEMON, nullptr, "ChangeRadius", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULEMON_ChangeRadius_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ULEMON_ChangeRadius_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULEMON_ChangeRadius()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULEMON_ChangeRadius_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULEMON_EndFire_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULEMON_EndFire_Statics::Function_MetaDataParams[] = {
		{ "Category", "Weapon" },
		{ "ModuleRelativePath", "LEMON.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULEMON_EndFire_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULEMON, nullptr, "EndFire", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULEMON_EndFire_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ULEMON_EndFire_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULEMON_EndFire()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULEMON_EndFire_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULEMON_EndPlay_Statics
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
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULEMON_EndPlay_Statics::NewProp_EndPlayReason_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_ULEMON_EndPlay_Statics::NewProp_EndPlayReason = { "EndPlayReason", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(LEMON_eventEndPlay_Parms, EndPlayReason), Z_Construct_UEnum_Engine_EEndPlayReason, METADATA_PARAMS(Z_Construct_UFunction_ULEMON_EndPlay_Statics::NewProp_EndPlayReason_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ULEMON_EndPlay_Statics::NewProp_EndPlayReason_MetaData)) }; // 2713016423
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULEMON_EndPlay_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULEMON_EndPlay_Statics::NewProp_EndPlayReason,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULEMON_EndPlay_Statics::Function_MetaDataParams[] = {
		{ "Comment", "/** Ends gameplay for this component. */" },
		{ "ModuleRelativePath", "LEMON.h" },
		{ "ToolTip", "Ends gameplay for this component." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULEMON_EndPlay_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULEMON, nullptr, "EndPlay", nullptr, nullptr, sizeof(Z_Construct_UFunction_ULEMON_EndPlay_Statics::LEMON_eventEndPlay_Parms), Z_Construct_UFunction_ULEMON_EndPlay_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULEMON_EndPlay_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080400, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULEMON_EndPlay_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ULEMON_EndPlay_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULEMON_EndPlay()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULEMON_EndPlay_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULEMON_Fire_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULEMON_Fire_Statics::Function_MetaDataParams[] = {
		{ "Category", "Weapon" },
		{ "ModuleRelativePath", "LEMON.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULEMON_Fire_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULEMON, nullptr, "Fire", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULEMON_Fire_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ULEMON_Fire_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULEMON_Fire()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULEMON_Fire_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ULEMON);
	UClass* Z_Construct_UClass_ULEMON_NoRegister()
	{
		return ULEMON::StaticClass();
	}
	struct Z_Construct_UClass_ULEMON_Statics
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
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ULEMON_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_LiDAR,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ULEMON_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ULEMON_AttachWeapon, "AttachWeapon" }, // 1268239351
		{ &Z_Construct_UFunction_ULEMON_ChangeRadius, "ChangeRadius" }, // 352788382
		{ &Z_Construct_UFunction_ULEMON_EndFire, "EndFire" }, // 3375551512
		{ &Z_Construct_UFunction_ULEMON_EndPlay, "EndPlay" }, // 432683696
		{ &Z_Construct_UFunction_ULEMON_Fire, "Fire" }, // 3732462489
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULEMON_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "BlueprintType", "true" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "LEMON.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "LEMON.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULEMON_Statics::NewProp_LaserBP_MetaData[] = {
		{ "Category", "LEMON" },
		{ "ModuleRelativePath", "LEMON.h" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_ULEMON_Statics::NewProp_LaserBP = { "LaserBP", nullptr, (EPropertyFlags)0x0014000000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ULEMON, LaserBP), Z_Construct_UClass_ALaser_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_ULEMON_Statics::NewProp_LaserBP_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ULEMON_Statics::NewProp_LaserBP_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULEMON_Statics::NewProp_LaserBeam_MetaData[] = {
		{ "ModuleRelativePath", "LEMON.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ULEMON_Statics::NewProp_LaserBeam = { "LaserBeam", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ULEMON, LaserBeam), Z_Construct_UClass_ALaser_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ULEMON_Statics::NewProp_LaserBeam_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ULEMON_Statics::NewProp_LaserBeam_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULEMON_Statics::NewProp_DotBP_MetaData[] = {
		{ "Category", "LEMON" },
		{ "ModuleRelativePath", "LEMON.h" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_ULEMON_Statics::NewProp_DotBP = { "DotBP", nullptr, (EPropertyFlags)0x0014000000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ULEMON, DotBP), Z_Construct_UClass_ADot_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_ULEMON_Statics::NewProp_DotBP_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ULEMON_Statics::NewProp_DotBP_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULEMON_Statics::NewProp_Dot_MetaData[] = {
		{ "ModuleRelativePath", "LEMON.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ULEMON_Statics::NewProp_Dot = { "Dot", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ULEMON, Dot), Z_Construct_UClass_ADot_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ULEMON_Statics::NewProp_Dot_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ULEMON_Statics::NewProp_Dot_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ULEMON_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULEMON_Statics::NewProp_LaserBP,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULEMON_Statics::NewProp_LaserBeam,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULEMON_Statics::NewProp_DotBP,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULEMON_Statics::NewProp_Dot,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ULEMON_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ULEMON>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ULEMON_Statics::ClassParams = {
		&ULEMON::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ULEMON_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ULEMON_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ULEMON_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ULEMON_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ULEMON()
	{
		if (!Z_Registration_Info_UClass_ULEMON.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ULEMON.OuterSingleton, Z_Construct_UClass_ULEMON_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ULEMON.OuterSingleton;
	}
	template<> LIDAR_API UClass* StaticClass<ULEMON>()
	{
		return ULEMON::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ULEMON);
	struct Z_CompiledInDeferFile_FID_LiDAR_Source_LiDAR_LEMON_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_LiDAR_Source_LiDAR_LEMON_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ULEMON, ULEMON::StaticClass, TEXT("ULEMON"), &Z_Registration_Info_UClass_ULEMON, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ULEMON), 2299303340U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_LiDAR_Source_LiDAR_LEMON_h_214618784(TEXT("/Script/LiDAR"),
		Z_CompiledInDeferFile_FID_LiDAR_Source_LiDAR_LEMON_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_LiDAR_Source_LiDAR_LEMON_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
