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
	LIDAR_API UClass* Z_Construct_UClass_AMovingStaticMeshActor_NoRegister();
	LIDAR_API UClass* Z_Construct_UClass_AMovingStaticMeshActor();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_LiDAR();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	LIDAR_API UClass* Z_Construct_UClass_UMovableStaticMeshComponent_NoRegister();
	LIDAR_API UClass* Z_Construct_UClass_UInteractableInterface_NoRegister();
// End Cross Module References
	void AMovingStaticMeshActor::StaticRegisterNativesAMovingStaticMeshActor()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AMovingStaticMeshActor);
	UClass* Z_Construct_UClass_AMovingStaticMeshActor_NoRegister()
	{
		return AMovingStaticMeshActor::StaticClass();
	}
	struct Z_Construct_UClass_AMovingStaticMeshActor_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_BaseMesh_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_BaseMesh;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MovableMesh_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_MovableMesh;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InteractTag_MetaData[];
#endif
		static const UECodeGen_Private::FNamePropertyParams NewProp_InteractTag;
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
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMovingStaticMeshActor_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "MovingStaticMeshActor.h" },
		{ "ModuleRelativePath", "MovingStaticMeshActor.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMovingStaticMeshActor_Statics::NewProp_BaseMesh_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Moving" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "MovingStaticMeshActor.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMovingStaticMeshActor_Statics::NewProp_BaseMesh = { "BaseMesh", nullptr, (EPropertyFlags)0x00100000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMovingStaticMeshActor, BaseMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMovingStaticMeshActor_Statics::NewProp_BaseMesh_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMovingStaticMeshActor_Statics::NewProp_BaseMesh_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMovingStaticMeshActor_Statics::NewProp_MovableMesh_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Moving" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "MovingStaticMeshActor.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMovingStaticMeshActor_Statics::NewProp_MovableMesh = { "MovableMesh", nullptr, (EPropertyFlags)0x00100000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMovingStaticMeshActor, MovableMesh), Z_Construct_UClass_UMovableStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMovingStaticMeshActor_Statics::NewProp_MovableMesh_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMovingStaticMeshActor_Statics::NewProp_MovableMesh_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMovingStaticMeshActor_Statics::NewProp_InteractTag_MetaData[] = {
		{ "Category", "Moving" },
		{ "ModuleRelativePath", "MovingStaticMeshActor.h" },
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_AMovingStaticMeshActor_Statics::NewProp_InteractTag = { "InteractTag", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMovingStaticMeshActor, InteractTag), METADATA_PARAMS(Z_Construct_UClass_AMovingStaticMeshActor_Statics::NewProp_InteractTag_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMovingStaticMeshActor_Statics::NewProp_InteractTag_MetaData)) };
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
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMovingStaticMeshActor_Statics::NewProp_BaseMesh,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMovingStaticMeshActor_Statics::NewProp_MovableMesh,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMovingStaticMeshActor_Statics::NewProp_InteractTag,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMovingStaticMeshActor_Statics::NewProp_bIsDisabled,
	};
		const UECodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_AMovingStaticMeshActor_Statics::InterfaceParams[] = {
			{ Z_Construct_UClass_UInteractableInterface_NoRegister, (int32)VTABLE_OFFSET(AMovingStaticMeshActor, IInteractableInterface), false },  // 3948521902
		};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMovingStaticMeshActor_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMovingStaticMeshActor>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AMovingStaticMeshActor_Statics::ClassParams = {
		&AMovingStaticMeshActor::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AMovingStaticMeshActor_Statics::PropPointers,
		InterfaceParams,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
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
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_LiDAR_Source_LiDAR_MovingStaticMeshActor_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AMovingStaticMeshActor, AMovingStaticMeshActor::StaticClass, TEXT("AMovingStaticMeshActor"), &Z_Registration_Info_UClass_AMovingStaticMeshActor, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AMovingStaticMeshActor), 722309765U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_LiDAR_Source_LiDAR_MovingStaticMeshActor_h_1608339622(TEXT("/Script/LiDAR"),
		Z_CompiledInDeferFile_FID_LiDAR_Source_LiDAR_MovingStaticMeshActor_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_LiDAR_Source_LiDAR_MovingStaticMeshActor_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
