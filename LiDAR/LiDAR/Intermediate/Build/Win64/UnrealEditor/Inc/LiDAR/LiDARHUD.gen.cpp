// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LiDAR/LiDARHUD.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLiDARHUD() {}
// Cross Module References
	LIDAR_API UClass* Z_Construct_UClass_ULiDARHUD_NoRegister();
	LIDAR_API UClass* Z_Construct_UClass_ULiDARHUD();
	UMG_API UClass* Z_Construct_UClass_UUserWidget();
	UPackage* Z_Construct_UPackage__Script_LiDAR();
	UMG_API UClass* Z_Construct_UClass_UProgressBar_NoRegister();
// End Cross Module References
	void ULiDARHUD::StaticRegisterNativesULiDARHUD()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ULiDARHUD);
	UClass* Z_Construct_UClass_ULiDARHUD_NoRegister()
	{
		return ULiDARHUD::StaticClass();
	}
	struct Z_Construct_UClass_ULiDARHUD_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RadiusProgress_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_RadiusProgress;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ULiDARHUD_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UUserWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_LiDAR,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULiDARHUD_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "LiDARHUD.h" },
		{ "ModuleRelativePath", "LiDARHUD.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULiDARHUD_Statics::NewProp_RadiusProgress_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "LiDARHUD" },
		{ "Comment", "/* UPROPERTY(EditAnywhere, meta = (BindWidget))\n    UTextBlock* RadiusText; */" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "LiDARHUD.h" },
		{ "ToolTip", "UPROPERTY(EditAnywhere, meta = (BindWidget))\n   UTextBlock* RadiusText;" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ULiDARHUD_Statics::NewProp_RadiusProgress = { "RadiusProgress", nullptr, (EPropertyFlags)0x0010000000080009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ULiDARHUD, RadiusProgress), Z_Construct_UClass_UProgressBar_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ULiDARHUD_Statics::NewProp_RadiusProgress_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ULiDARHUD_Statics::NewProp_RadiusProgress_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ULiDARHUD_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULiDARHUD_Statics::NewProp_RadiusProgress,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ULiDARHUD_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ULiDARHUD>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ULiDARHUD_Statics::ClassParams = {
		&ULiDARHUD::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ULiDARHUD_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ULiDARHUD_Statics::PropPointers),
		0,
		0x00B010A0u,
		METADATA_PARAMS(Z_Construct_UClass_ULiDARHUD_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ULiDARHUD_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ULiDARHUD()
	{
		if (!Z_Registration_Info_UClass_ULiDARHUD.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ULiDARHUD.OuterSingleton, Z_Construct_UClass_ULiDARHUD_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ULiDARHUD.OuterSingleton;
	}
	template<> LIDAR_API UClass* StaticClass<ULiDARHUD>()
	{
		return ULiDARHUD::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ULiDARHUD);
	struct Z_CompiledInDeferFile_FID_LiDAR_Source_LiDAR_LiDARHUD_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_LiDAR_Source_LiDAR_LiDARHUD_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ULiDARHUD, ULiDARHUD::StaticClass, TEXT("ULiDARHUD"), &Z_Registration_Info_UClass_ULiDARHUD, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ULiDARHUD), 1921415030U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_LiDAR_Source_LiDAR_LiDARHUD_h_1474771543(TEXT("/Script/LiDAR"),
		Z_CompiledInDeferFile_FID_LiDAR_Source_LiDAR_LiDARHUD_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_LiDAR_Source_LiDAR_LiDARHUD_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
