// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLiDAR_init() {}
	LIDAR_API UFunction* Z_Construct_UDelegateFunction_LiDAR_OnPickUp__DelegateSignature();
	LIDAR_API UFunction* Z_Construct_UDelegateFunction_LiDAR_OnStopUseItem__DelegateSignature();
	LIDAR_API UFunction* Z_Construct_UDelegateFunction_LiDAR_OnUseItem__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_LiDAR;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_LiDAR()
	{
		if (!Z_Registration_Info_UPackage__Script_LiDAR.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_LiDAR_OnPickUp__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_LiDAR_OnStopUseItem__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_LiDAR_OnUseItem__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/LiDAR",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0x1ED82653,
				0xCF1DCD6A,
				METADATA_PARAMS(nullptr, 0)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_LiDAR.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_LiDAR.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_LiDAR(Z_Construct_UPackage__Script_LiDAR, TEXT("/Script/LiDAR"), Z_Registration_Info_UPackage__Script_LiDAR, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x1ED82653, 0xCF1DCD6A));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
