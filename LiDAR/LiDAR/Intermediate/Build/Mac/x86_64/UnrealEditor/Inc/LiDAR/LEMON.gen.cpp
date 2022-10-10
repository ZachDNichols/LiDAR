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
// End Cross Module References
	void ULEMON::StaticRegisterNativesULEMON()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ULEMON);
	UClass* Z_Construct_UClass_ULEMON_NoRegister()
	{
		return ULEMON::StaticClass();
	}
	struct Z_Construct_UClass_ULEMON_Statics
	{
		static UObject* (*const DependentSingletons[])();
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
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
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
		{ Z_Construct_UClass_ULEMON, ULEMON::StaticClass, TEXT("ULEMON"), &Z_Registration_Info_UClass_ULEMON, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ULEMON), 3771005508U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_LiDAR_Source_LiDAR_LEMON_h_1896005783(TEXT("/Script/LiDAR"),
		Z_CompiledInDeferFile_FID_LiDAR_Source_LiDAR_LEMON_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_LiDAR_Source_LiDAR_LEMON_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
