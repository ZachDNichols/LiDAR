// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LiDAR/VoiceLineTrigger.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVoiceLineTrigger() {}
// Cross Module References
	LIDAR_API UClass* Z_Construct_UClass_AVoiceLineTrigger_NoRegister();
	LIDAR_API UClass* Z_Construct_UClass_AVoiceLineTrigger();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_LiDAR();
// End Cross Module References
	void AVoiceLineTrigger::StaticRegisterNativesAVoiceLineTrigger()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AVoiceLineTrigger);
	UClass* Z_Construct_UClass_AVoiceLineTrigger_NoRegister()
	{
		return AVoiceLineTrigger::StaticClass();
	}
	struct Z_Construct_UClass_AVoiceLineTrigger_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AVoiceLineTrigger_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_LiDAR,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVoiceLineTrigger_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "VoiceLineTrigger.h" },
		{ "ModuleRelativePath", "VoiceLineTrigger.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AVoiceLineTrigger_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AVoiceLineTrigger>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AVoiceLineTrigger_Statics::ClassParams = {
		&AVoiceLineTrigger::StaticClass,
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
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AVoiceLineTrigger_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AVoiceLineTrigger_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AVoiceLineTrigger()
	{
		if (!Z_Registration_Info_UClass_AVoiceLineTrigger.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AVoiceLineTrigger.OuterSingleton, Z_Construct_UClass_AVoiceLineTrigger_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AVoiceLineTrigger.OuterSingleton;
	}
	template<> LIDAR_API UClass* StaticClass<AVoiceLineTrigger>()
	{
		return AVoiceLineTrigger::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AVoiceLineTrigger);
	struct Z_CompiledInDeferFile_FID_LiDAR_Source_LiDAR_VoiceLineTrigger_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_LiDAR_Source_LiDAR_VoiceLineTrigger_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AVoiceLineTrigger, AVoiceLineTrigger::StaticClass, TEXT("AVoiceLineTrigger"), &Z_Registration_Info_UClass_AVoiceLineTrigger, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AVoiceLineTrigger), 3039443795U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_LiDAR_Source_LiDAR_VoiceLineTrigger_h_2592461628(TEXT("/Script/LiDAR"),
		Z_CompiledInDeferFile_FID_LiDAR_Source_LiDAR_VoiceLineTrigger_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_LiDAR_Source_LiDAR_VoiceLineTrigger_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
