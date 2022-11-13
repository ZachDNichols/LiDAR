// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LiDAR/SpotlightActor.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSpotlightActor() {}
// Cross Module References
	LIDAR_API UClass* Z_Construct_UClass_ASpotlightActor_NoRegister();
	LIDAR_API UClass* Z_Construct_UClass_ASpotlightActor();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_LiDAR();
	ENGINE_API UClass* Z_Construct_UClass_USpotLightComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UPointLightComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	LIDAR_API UClass* Z_Construct_UClass_UInteractableInterface_NoRegister();
// End Cross Module References
	void ASpotlightActor::StaticRegisterNativesASpotlightActor()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ASpotlightActor);
	UClass* Z_Construct_UClass_ASpotlightActor_NoRegister()
	{
		return ASpotlightActor::StaticClass();
	}
	struct Z_Construct_UClass_ASpotlightActor_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Spotlight_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Spotlight;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MeshLight_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_MeshLight;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Mesh_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Mesh;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ObjectID_MetaData[];
#endif
		static const UECodeGen_Private::FUnsizedIntPropertyParams NewProp_ObjectID;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Intensity_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Intensity;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASpotlightActor_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_LiDAR,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASpotlightActor_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "SpotlightActor.h" },
		{ "ModuleRelativePath", "SpotlightActor.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASpotlightActor_Statics::NewProp_Spotlight_MetaData[] = {
		{ "Category", "Lighting" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "SpotlightActor.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASpotlightActor_Statics::NewProp_Spotlight = { "Spotlight", nullptr, (EPropertyFlags)0x00100000000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASpotlightActor, Spotlight), Z_Construct_UClass_USpotLightComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ASpotlightActor_Statics::NewProp_Spotlight_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASpotlightActor_Statics::NewProp_Spotlight_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASpotlightActor_Statics::NewProp_MeshLight_MetaData[] = {
		{ "Category", "Lighting" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "SpotlightActor.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASpotlightActor_Statics::NewProp_MeshLight = { "MeshLight", nullptr, (EPropertyFlags)0x00100000000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASpotlightActor, MeshLight), Z_Construct_UClass_UPointLightComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ASpotlightActor_Statics::NewProp_MeshLight_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASpotlightActor_Statics::NewProp_MeshLight_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASpotlightActor_Statics::NewProp_Mesh_MetaData[] = {
		{ "Category", "mesh" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "SpotlightActor.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASpotlightActor_Statics::NewProp_Mesh = { "Mesh", nullptr, (EPropertyFlags)0x00100000000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASpotlightActor, Mesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ASpotlightActor_Statics::NewProp_Mesh_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASpotlightActor_Statics::NewProp_Mesh_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASpotlightActor_Statics::NewProp_ObjectID_MetaData[] = {
		{ "Category", "Interaction" },
		{ "ModuleRelativePath", "SpotlightActor.h" },
	};
#endif
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_ASpotlightActor_Statics::NewProp_ObjectID = { "ObjectID", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASpotlightActor, ObjectID), METADATA_PARAMS(Z_Construct_UClass_ASpotlightActor_Statics::NewProp_ObjectID_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASpotlightActor_Statics::NewProp_ObjectID_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASpotlightActor_Statics::NewProp_Intensity_MetaData[] = {
		{ "Category", "Lighting" },
		{ "ModuleRelativePath", "SpotlightActor.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ASpotlightActor_Statics::NewProp_Intensity = { "Intensity", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASpotlightActor, Intensity), METADATA_PARAMS(Z_Construct_UClass_ASpotlightActor_Statics::NewProp_Intensity_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASpotlightActor_Statics::NewProp_Intensity_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ASpotlightActor_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASpotlightActor_Statics::NewProp_Spotlight,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASpotlightActor_Statics::NewProp_MeshLight,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASpotlightActor_Statics::NewProp_Mesh,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASpotlightActor_Statics::NewProp_ObjectID,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASpotlightActor_Statics::NewProp_Intensity,
	};
		const UECodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_ASpotlightActor_Statics::InterfaceParams[] = {
			{ Z_Construct_UClass_UInteractableInterface_NoRegister, (int32)VTABLE_OFFSET(ASpotlightActor, IInteractableInterface), false },  // 954022642
		};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASpotlightActor_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASpotlightActor>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ASpotlightActor_Statics::ClassParams = {
		&ASpotlightActor::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ASpotlightActor_Statics::PropPointers,
		InterfaceParams,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ASpotlightActor_Statics::PropPointers),
		UE_ARRAY_COUNT(InterfaceParams),
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ASpotlightActor_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ASpotlightActor_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ASpotlightActor()
	{
		if (!Z_Registration_Info_UClass_ASpotlightActor.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASpotlightActor.OuterSingleton, Z_Construct_UClass_ASpotlightActor_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ASpotlightActor.OuterSingleton;
	}
	template<> LIDAR_API UClass* StaticClass<ASpotlightActor>()
	{
		return ASpotlightActor::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASpotlightActor);
	struct Z_CompiledInDeferFile_FID_LiDAR_Source_LiDAR_SpotlightActor_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_LiDAR_Source_LiDAR_SpotlightActor_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ASpotlightActor, ASpotlightActor::StaticClass, TEXT("ASpotlightActor"), &Z_Registration_Info_UClass_ASpotlightActor, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASpotlightActor), 2276049372U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_LiDAR_Source_LiDAR_SpotlightActor_h_1517485345(TEXT("/Script/LiDAR"),
		Z_CompiledInDeferFile_FID_LiDAR_Source_LiDAR_SpotlightActor_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_LiDAR_Source_LiDAR_SpotlightActor_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
