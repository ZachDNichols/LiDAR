// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LiDAR/LEMONAnimInstance.h"
#include "Engine/Classes/Components/SkeletalMeshComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLEMONAnimInstance() {}
// Cross Module References
	LIDAR_API UClass* Z_Construct_UClass_ULEMONAnimInstance_NoRegister();
	LIDAR_API UClass* Z_Construct_UClass_ULEMONAnimInstance();
	ENGINE_API UClass* Z_Construct_UClass_UAnimInstance();
	UPackage* Z_Construct_UPackage__Script_LiDAR();
	LIDAR_API UClass* Z_Construct_UClass_AFirstPersonCharacter_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(ULEMONAnimInstance::execEndShoot)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->EndShoot();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ULEMONAnimInstance::execShoot)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Shoot();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ULEMONAnimInstance::execAssignCharacter)
	{
		P_GET_OBJECT(AFirstPersonCharacter,Z_Param_TargetCharacter);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->AssignCharacter(Z_Param_TargetCharacter);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ULEMONAnimInstance::execUpdateAnimProperties)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->UpdateAnimProperties();
		P_NATIVE_END;
	}
	void ULEMONAnimInstance::StaticRegisterNativesULEMONAnimInstance()
	{
		UClass* Class = ULEMONAnimInstance::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "AssignCharacter", &ULEMONAnimInstance::execAssignCharacter },
			{ "EndShoot", &ULEMONAnimInstance::execEndShoot },
			{ "Shoot", &ULEMONAnimInstance::execShoot },
			{ "UpdateAnimProperties", &ULEMONAnimInstance::execUpdateAnimProperties },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ULEMONAnimInstance_AssignCharacter_Statics
	{
		struct LEMONAnimInstance_eventAssignCharacter_Parms
		{
			AFirstPersonCharacter* TargetCharacter;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_TargetCharacter;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ULEMONAnimInstance_AssignCharacter_Statics::NewProp_TargetCharacter = { "TargetCharacter", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(LEMONAnimInstance_eventAssignCharacter_Parms, TargetCharacter), Z_Construct_UClass_AFirstPersonCharacter_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULEMONAnimInstance_AssignCharacter_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULEMONAnimInstance_AssignCharacter_Statics::NewProp_TargetCharacter,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULEMONAnimInstance_AssignCharacter_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "LEMONAnimInstance.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULEMONAnimInstance_AssignCharacter_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULEMONAnimInstance, nullptr, "AssignCharacter", nullptr, nullptr, sizeof(Z_Construct_UFunction_ULEMONAnimInstance_AssignCharacter_Statics::LEMONAnimInstance_eventAssignCharacter_Parms), Z_Construct_UFunction_ULEMONAnimInstance_AssignCharacter_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULEMONAnimInstance_AssignCharacter_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULEMONAnimInstance_AssignCharacter_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ULEMONAnimInstance_AssignCharacter_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULEMONAnimInstance_AssignCharacter()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULEMONAnimInstance_AssignCharacter_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULEMONAnimInstance_EndShoot_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULEMONAnimInstance_EndShoot_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "LEMONAnimInstance.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULEMONAnimInstance_EndShoot_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULEMONAnimInstance, nullptr, "EndShoot", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULEMONAnimInstance_EndShoot_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ULEMONAnimInstance_EndShoot_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULEMONAnimInstance_EndShoot()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULEMONAnimInstance_EndShoot_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULEMONAnimInstance_Shoot_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULEMONAnimInstance_Shoot_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "LEMONAnimInstance.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULEMONAnimInstance_Shoot_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULEMONAnimInstance, nullptr, "Shoot", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULEMONAnimInstance_Shoot_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ULEMONAnimInstance_Shoot_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULEMONAnimInstance_Shoot()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULEMONAnimInstance_Shoot_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULEMONAnimInstance_UpdateAnimProperties_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULEMONAnimInstance_UpdateAnimProperties_Statics::Function_MetaDataParams[] = {
		{ "Category", "Animation" },
		{ "ModuleRelativePath", "LEMONAnimInstance.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULEMONAnimInstance_UpdateAnimProperties_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULEMONAnimInstance, nullptr, "UpdateAnimProperties", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04080400, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULEMONAnimInstance_UpdateAnimProperties_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ULEMONAnimInstance_UpdateAnimProperties_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULEMONAnimInstance_UpdateAnimProperties()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULEMONAnimInstance_UpdateAnimProperties_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ULEMONAnimInstance);
	UClass* Z_Construct_UClass_ULEMONAnimInstance_NoRegister()
	{
		return ULEMONAnimInstance::StaticClass();
	}
	struct Z_Construct_UClass_ULEMONAnimInstance_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_isShooting_MetaData[];
#endif
		static void NewProp_isShooting_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_isShooting;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_speed_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_speed;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ULEMONAnimInstance_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UAnimInstance,
		(UObject* (*)())Z_Construct_UPackage__Script_LiDAR,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ULEMONAnimInstance_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ULEMONAnimInstance_AssignCharacter, "AssignCharacter" }, // 880986765
		{ &Z_Construct_UFunction_ULEMONAnimInstance_EndShoot, "EndShoot" }, // 2957576259
		{ &Z_Construct_UFunction_ULEMONAnimInstance_Shoot, "Shoot" }, // 935692460
		{ &Z_Construct_UFunction_ULEMONAnimInstance_UpdateAnimProperties, "UpdateAnimProperties" }, // 4280443694
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULEMONAnimInstance_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n *\n */" },
		{ "HideCategories", "AnimInstance" },
		{ "IncludePath", "LEMONAnimInstance.h" },
		{ "ModuleRelativePath", "LEMONAnimInstance.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULEMONAnimInstance_Statics::NewProp_isShooting_MetaData[] = {
		{ "Category", "Animation Property" },
		{ "ModuleRelativePath", "LEMONAnimInstance.h" },
	};
#endif
	void Z_Construct_UClass_ULEMONAnimInstance_Statics::NewProp_isShooting_SetBit(void* Obj)
	{
		((ULEMONAnimInstance*)Obj)->isShooting = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ULEMONAnimInstance_Statics::NewProp_isShooting = { "isShooting", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ULEMONAnimInstance), &Z_Construct_UClass_ULEMONAnimInstance_Statics::NewProp_isShooting_SetBit, METADATA_PARAMS(Z_Construct_UClass_ULEMONAnimInstance_Statics::NewProp_isShooting_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ULEMONAnimInstance_Statics::NewProp_isShooting_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULEMONAnimInstance_Statics::NewProp_speed_MetaData[] = {
		{ "Category", "Animation Property" },
		{ "ModuleRelativePath", "LEMONAnimInstance.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ULEMONAnimInstance_Statics::NewProp_speed = { "speed", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ULEMONAnimInstance, speed), METADATA_PARAMS(Z_Construct_UClass_ULEMONAnimInstance_Statics::NewProp_speed_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ULEMONAnimInstance_Statics::NewProp_speed_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ULEMONAnimInstance_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULEMONAnimInstance_Statics::NewProp_isShooting,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULEMONAnimInstance_Statics::NewProp_speed,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ULEMONAnimInstance_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ULEMONAnimInstance>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ULEMONAnimInstance_Statics::ClassParams = {
		&ULEMONAnimInstance::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ULEMONAnimInstance_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ULEMONAnimInstance_Statics::PropPointers),
		0,
		0x009000A8u,
		METADATA_PARAMS(Z_Construct_UClass_ULEMONAnimInstance_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ULEMONAnimInstance_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ULEMONAnimInstance()
	{
		if (!Z_Registration_Info_UClass_ULEMONAnimInstance.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ULEMONAnimInstance.OuterSingleton, Z_Construct_UClass_ULEMONAnimInstance_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ULEMONAnimInstance.OuterSingleton;
	}
	template<> LIDAR_API UClass* StaticClass<ULEMONAnimInstance>()
	{
		return ULEMONAnimInstance::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ULEMONAnimInstance);
	struct Z_CompiledInDeferFile_FID_LiDAR_Source_LiDAR_LEMONAnimInstance_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_LiDAR_Source_LiDAR_LEMONAnimInstance_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ULEMONAnimInstance, ULEMONAnimInstance::StaticClass, TEXT("ULEMONAnimInstance"), &Z_Registration_Info_UClass_ULEMONAnimInstance, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ULEMONAnimInstance), 1227891048U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_LiDAR_Source_LiDAR_LEMONAnimInstance_h_3742720716(TEXT("/Script/LiDAR"),
		Z_CompiledInDeferFile_FID_LiDAR_Source_LiDAR_LEMONAnimInstance_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_LiDAR_Source_LiDAR_LEMONAnimInstance_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
