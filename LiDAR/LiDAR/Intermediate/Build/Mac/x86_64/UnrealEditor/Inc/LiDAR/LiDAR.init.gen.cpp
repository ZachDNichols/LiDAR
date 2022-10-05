// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLiDAR_init() {}
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_LiDAR;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_LiDAR()
	{
		if (!Z_Registration_Info_UPackage__Script_LiDAR.OuterSingleton)
		{
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/LiDAR",
				nullptr,
				0,
				PKG_CompiledIn | 0x00000000,
				0x70DA977F,
				0x66E02C26,
				METADATA_PARAMS(nullptr, 0)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_LiDAR.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_LiDAR.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_LiDAR(Z_Construct_UPackage__Script_LiDAR, TEXT("/Script/LiDAR"), Z_Registration_Info_UPackage__Script_LiDAR, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x70DA977F, 0x66E02C26));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
