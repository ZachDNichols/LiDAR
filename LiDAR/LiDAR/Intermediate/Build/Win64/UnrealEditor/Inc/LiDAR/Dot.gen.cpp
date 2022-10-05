// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LiDAR/Dot.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDot() {}
// Cross Module References
	LIDAR_API UClass* Z_Construct_UClass_ADot_NoRegister();
	LIDAR_API UClass* Z_Construct_UClass_ADot();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_LiDAR();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
// End Cross Module References
	void ADot::StaticRegisterNativesADot()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ADot);
	UClass* Z_Construct_UClass_ADot_NoRegister()
	{
		return ADot::StaticClass();
	}
	struct Z_Construct_UClass_ADot_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DotMesh_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_DotMesh;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ADot_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_LiDAR,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADot_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Dot.h" },
		{ "ModuleRelativePath", "Dot.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADot_Statics::NewProp_DotMesh_MetaData[] = {
		{ "Category", "mesh" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Dot.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ADot_Statics::NewProp_DotMesh = { "DotMesh", nullptr, (EPropertyFlags)0x00400000000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ADot, DotMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ADot_Statics::NewProp_DotMesh_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ADot_Statics::NewProp_DotMesh_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ADot_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADot_Statics::NewProp_DotMesh,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ADot_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ADot>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ADot_Statics::ClassParams = {
		&ADot::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ADot_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ADot_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ADot_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ADot_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ADot()
	{
		if (!Z_Registration_Info_UClass_ADot.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ADot.OuterSingleton, Z_Construct_UClass_ADot_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ADot.OuterSingleton;
	}
	template<> LIDAR_API UClass* StaticClass<ADot>()
	{
		return ADot::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ADot);
	struct Z_CompiledInDeferFile_FID_LiDAR_Source_LiDAR_Dot_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_LiDAR_Source_LiDAR_Dot_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ADot, ADot::StaticClass, TEXT("ADot"), &Z_Registration_Info_UClass_ADot, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ADot), 735577225U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_LiDAR_Source_LiDAR_Dot_h_4160930428(TEXT("/Script/LiDAR"),
		Z_CompiledInDeferFile_FID_LiDAR_Source_LiDAR_Dot_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_LiDAR_Source_LiDAR_Dot_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
