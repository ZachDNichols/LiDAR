// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LiDAR/LiDARGameModeBase.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLiDARGameModeBase() {}
// Cross Module References
	LIDAR_API UClass* Z_Construct_UClass_ALiDARGameModeBase_NoRegister();
	LIDAR_API UClass* Z_Construct_UClass_ALiDARGameModeBase();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_LiDAR();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	LIDAR_API UClass* Z_Construct_UClass_AFirstPersonCharacter_NoRegister();
// End Cross Module References
	void ALiDARGameModeBase::StaticRegisterNativesALiDARGameModeBase()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ALiDARGameModeBase);
	UClass* Z_Construct_UClass_ALiDARGameModeBase_NoRegister()
	{
		return ALiDARGameModeBase::StaticClass();
	}
	struct Z_Construct_UClass_ALiDARGameModeBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Character_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_Character;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ALiDARGameModeBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_LiDAR,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ALiDARGameModeBase_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "LiDARGameModeBase.h" },
		{ "ModuleRelativePath", "LiDARGameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ALiDARGameModeBase_Statics::NewProp_Character_MetaData[] = {
		{ "Category", "Character" },
		{ "ModuleRelativePath", "LiDARGameModeBase.h" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_ALiDARGameModeBase_Statics::NewProp_Character = { "Character", nullptr, (EPropertyFlags)0x0014000000010015, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ALiDARGameModeBase, Character), Z_Construct_UClass_AFirstPersonCharacter_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_ALiDARGameModeBase_Statics::NewProp_Character_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ALiDARGameModeBase_Statics::NewProp_Character_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ALiDARGameModeBase_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ALiDARGameModeBase_Statics::NewProp_Character,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ALiDARGameModeBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ALiDARGameModeBase>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ALiDARGameModeBase_Statics::ClassParams = {
		&ALiDARGameModeBase::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ALiDARGameModeBase_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ALiDARGameModeBase_Statics::PropPointers),
		0,
		0x009002ACu,
		METADATA_PARAMS(Z_Construct_UClass_ALiDARGameModeBase_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ALiDARGameModeBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ALiDARGameModeBase()
	{
		if (!Z_Registration_Info_UClass_ALiDARGameModeBase.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ALiDARGameModeBase.OuterSingleton, Z_Construct_UClass_ALiDARGameModeBase_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ALiDARGameModeBase.OuterSingleton;
	}
	template<> LIDAR_API UClass* StaticClass<ALiDARGameModeBase>()
	{
		return ALiDARGameModeBase::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ALiDARGameModeBase);
	struct Z_CompiledInDeferFile_FID_LiDAR_Source_LiDAR_LiDARGameModeBase_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_LiDAR_Source_LiDAR_LiDARGameModeBase_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ALiDARGameModeBase, ALiDARGameModeBase::StaticClass, TEXT("ALiDARGameModeBase"), &Z_Registration_Info_UClass_ALiDARGameModeBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ALiDARGameModeBase), 1404705381U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_LiDAR_Source_LiDAR_LiDARGameModeBase_h_3421581085(TEXT("/Script/LiDAR"),
		Z_CompiledInDeferFile_FID_LiDAR_Source_LiDAR_LiDARGameModeBase_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_LiDAR_Source_LiDAR_LiDARGameModeBase_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
