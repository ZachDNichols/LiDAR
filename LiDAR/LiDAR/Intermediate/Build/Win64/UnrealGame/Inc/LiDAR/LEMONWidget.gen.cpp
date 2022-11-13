// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LiDAR/LEMONWidget.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLEMONWidget() {}
// Cross Module References
	LIDAR_API UClass* Z_Construct_UClass_ULEMONWidget_NoRegister();
	LIDAR_API UClass* Z_Construct_UClass_ULEMONWidget();
	UMG_API UClass* Z_Construct_UClass_UUserWidget();
	UPackage* Z_Construct_UPackage__Script_LiDAR();
	UMG_API UClass* Z_Construct_UClass_UProgressBar_NoRegister();
// End Cross Module References
	void ULEMONWidget::StaticRegisterNativesULEMONWidget()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ULEMONWidget);
	UClass* Z_Construct_UClass_ULEMONWidget_NoRegister()
	{
		return ULEMONWidget::StaticClass();
	}
	struct Z_Construct_UClass_ULEMONWidget_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RadiusBar_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_RadiusBar;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ULEMONWidget_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UUserWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_LiDAR,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULEMONWidget_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "LEMONWidget.h" },
		{ "ModuleRelativePath", "LEMONWidget.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULEMONWidget_Statics::NewProp_RadiusBar_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "LEMONWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "LEMONWidget.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ULEMONWidget_Statics::NewProp_RadiusBar = { "RadiusBar", nullptr, (EPropertyFlags)0x0010000000080009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ULEMONWidget, RadiusBar), Z_Construct_UClass_UProgressBar_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ULEMONWidget_Statics::NewProp_RadiusBar_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ULEMONWidget_Statics::NewProp_RadiusBar_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ULEMONWidget_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULEMONWidget_Statics::NewProp_RadiusBar,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ULEMONWidget_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ULEMONWidget>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ULEMONWidget_Statics::ClassParams = {
		&ULEMONWidget::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ULEMONWidget_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ULEMONWidget_Statics::PropPointers),
		0,
		0x00B010A0u,
		METADATA_PARAMS(Z_Construct_UClass_ULEMONWidget_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ULEMONWidget_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ULEMONWidget()
	{
		if (!Z_Registration_Info_UClass_ULEMONWidget.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ULEMONWidget.OuterSingleton, Z_Construct_UClass_ULEMONWidget_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ULEMONWidget.OuterSingleton;
	}
	template<> LIDAR_API UClass* StaticClass<ULEMONWidget>()
	{
		return ULEMONWidget::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ULEMONWidget);
	struct Z_CompiledInDeferFile_FID_LiDAR_Source_LiDAR_LEMONWidget_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_LiDAR_Source_LiDAR_LEMONWidget_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ULEMONWidget, ULEMONWidget::StaticClass, TEXT("ULEMONWidget"), &Z_Registration_Info_UClass_ULEMONWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ULEMONWidget), 2383174140U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_LiDAR_Source_LiDAR_LEMONWidget_h_1508929842(TEXT("/Script/LiDAR"),
		Z_CompiledInDeferFile_FID_LiDAR_Source_LiDAR_LEMONWidget_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_LiDAR_Source_LiDAR_LEMONWidget_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
