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
// End Cross Module References
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
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ULEMON_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_LiDAR,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ULEMON_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ULEMON_AttachWeapon, "AttachWeapon" }, // 1268239351
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULEMON_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "LEMON.h" },
		{ "ModuleRelativePath", "LEMON.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ULEMON_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ULEMON>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ULEMON_Statics::ClassParams = {
		&ULEMON::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
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
		{ Z_Construct_UClass_ULEMON, ULEMON::StaticClass, TEXT("ULEMON"), &Z_Registration_Info_UClass_ULEMON, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ULEMON), 3575252999U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_LiDAR_Source_LiDAR_LEMON_h_2975558635(TEXT("/Script/LiDAR"),
		Z_CompiledInDeferFile_FID_LiDAR_Source_LiDAR_LEMON_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_LiDAR_Source_LiDAR_LEMON_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
