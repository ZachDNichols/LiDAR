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
	DEFINE_FUNCTION(ULEMONAnimInstance::execAssignCharacter)
	{
		P_GET_OBJECT(AFirstPersonCharacter,Z_Param_TargetCharacter);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->AssignCharacter(Z_Param_TargetCharacter);
		P_NATIVE_END;
	}
	void ULEMONAnimInstance::StaticRegisterNativesULEMONAnimInstance()
	{
		UClass* Class = ULEMONAnimInstance::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "AssignCharacter", &ULEMONAnimInstance::execAssignCharacter },
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
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULEMONAnimInstance_AssignCharacter_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULEMONAnimInstance, nullptr, "AssignCharacter", nullptr, nullptr, sizeof(Z_Construct_UFunction_ULEMONAnimInstance_AssignCharacter_Statics::LEMONAnimInstance_eventAssignCharacter_Parms), Z_Construct_UFunction_ULEMONAnimInstance_AssignCharacter_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULEMONAnimInstance_AssignCharacter_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULEMONAnimInstance_AssignCharacter_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ULEMONAnimInstance_AssignCharacter_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULEMONAnimInstance_AssignCharacter()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULEMONAnimInstance_AssignCharacter_Statics::FuncParams);
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
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ULEMONAnimInstance_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UAnimInstance,
		(UObject* (*)())Z_Construct_UPackage__Script_LiDAR,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ULEMONAnimInstance_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ULEMONAnimInstance_AssignCharacter, "AssignCharacter" }, // 3522566446
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULEMONAnimInstance_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n *\n */" },
		{ "HideCategories", "AnimInstance" },
		{ "IncludePath", "LEMONAnimInstance.h" },
		{ "ModuleRelativePath", "LEMONAnimInstance.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ULEMONAnimInstance_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ULEMONAnimInstance>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ULEMONAnimInstance_Statics::ClassParams = {
		&ULEMONAnimInstance::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
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
		{ Z_Construct_UClass_ULEMONAnimInstance, ULEMONAnimInstance::StaticClass, TEXT("ULEMONAnimInstance"), &Z_Registration_Info_UClass_ULEMONAnimInstance, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ULEMONAnimInstance), 3761072311U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_LiDAR_Source_LiDAR_LEMONAnimInstance_h_1679361999(TEXT("/Script/LiDAR"),
		Z_CompiledInDeferFile_FID_LiDAR_Source_LiDAR_LEMONAnimInstance_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_LiDAR_Source_LiDAR_LEMONAnimInstance_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
