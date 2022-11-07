// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LiDAR/FirstDiagloueScriptedSequence.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFirstDiagloueScriptedSequence() {}
// Cross Module References
	LIDAR_API UClass* Z_Construct_UClass_AFirstDiagloueScriptedSequence_NoRegister();
	LIDAR_API UClass* Z_Construct_UClass_AFirstDiagloueScriptedSequence();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_LiDAR();
	ENGINE_API UClass* Z_Construct_UClass_USoundBase_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USoundAttenuation_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(AFirstDiagloueScriptedSequence::execPlayVoiceLine)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->PlayVoiceLine();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AFirstDiagloueScriptedSequence::execInteract)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Interact();
		P_NATIVE_END;
	}
	void AFirstDiagloueScriptedSequence::StaticRegisterNativesAFirstDiagloueScriptedSequence()
	{
		UClass* Class = AFirstDiagloueScriptedSequence::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "Interact", &AFirstDiagloueScriptedSequence::execInteract },
			{ "PlayVoiceLine", &AFirstDiagloueScriptedSequence::execPlayVoiceLine },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AFirstDiagloueScriptedSequence_Interact_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AFirstDiagloueScriptedSequence_Interact_Statics::Function_MetaDataParams[] = {
		{ "Category", "Voice Function" },
		{ "ModuleRelativePath", "FirstDiagloueScriptedSequence.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AFirstDiagloueScriptedSequence_Interact_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AFirstDiagloueScriptedSequence, nullptr, "Interact", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AFirstDiagloueScriptedSequence_Interact_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AFirstDiagloueScriptedSequence_Interact_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AFirstDiagloueScriptedSequence_Interact()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AFirstDiagloueScriptedSequence_Interact_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AFirstDiagloueScriptedSequence_PlayVoiceLine_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AFirstDiagloueScriptedSequence_PlayVoiceLine_Statics::Function_MetaDataParams[] = {
		{ "Category", "Voice Function" },
		{ "ModuleRelativePath", "FirstDiagloueScriptedSequence.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AFirstDiagloueScriptedSequence_PlayVoiceLine_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AFirstDiagloueScriptedSequence, nullptr, "PlayVoiceLine", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AFirstDiagloueScriptedSequence_PlayVoiceLine_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AFirstDiagloueScriptedSequence_PlayVoiceLine_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AFirstDiagloueScriptedSequence_PlayVoiceLine()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AFirstDiagloueScriptedSequence_PlayVoiceLine_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AFirstDiagloueScriptedSequence);
	UClass* Z_Construct_UClass_AFirstDiagloueScriptedSequence_NoRegister()
	{
		return AFirstDiagloueScriptedSequence::StaticClass();
	}
	struct Z_Construct_UClass_AFirstDiagloueScriptedSequence_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_VoiceLine_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_VoiceLine;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bIsDisabled_MetaData[];
#endif
		static void NewProp_bIsDisabled_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsDisabled;
		static const UECodeGen_Private::FUnsizedIntPropertyParams NewProp_TargetIDs_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TargetIDs_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_TargetIDs;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SoundAttenuation_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_SoundAttenuation;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AFirstDiagloueScriptedSequence_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_LiDAR,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AFirstDiagloueScriptedSequence_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AFirstDiagloueScriptedSequence_Interact, "Interact" }, // 1697449190
		{ &Z_Construct_UFunction_AFirstDiagloueScriptedSequence_PlayVoiceLine, "PlayVoiceLine" }, // 3322695196
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFirstDiagloueScriptedSequence_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "FirstDiagloueScriptedSequence.h" },
		{ "ModuleRelativePath", "FirstDiagloueScriptedSequence.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFirstDiagloueScriptedSequence_Statics::NewProp_VoiceLine_MetaData[] = {
		{ "Category", "Audio" },
		{ "ModuleRelativePath", "FirstDiagloueScriptedSequence.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFirstDiagloueScriptedSequence_Statics::NewProp_VoiceLine = { "VoiceLine", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFirstDiagloueScriptedSequence, VoiceLine), Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AFirstDiagloueScriptedSequence_Statics::NewProp_VoiceLine_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AFirstDiagloueScriptedSequence_Statics::NewProp_VoiceLine_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFirstDiagloueScriptedSequence_Statics::NewProp_bIsDisabled_MetaData[] = {
		{ "Category", "Trigger" },
		{ "ModuleRelativePath", "FirstDiagloueScriptedSequence.h" },
	};
#endif
	void Z_Construct_UClass_AFirstDiagloueScriptedSequence_Statics::NewProp_bIsDisabled_SetBit(void* Obj)
	{
		((AFirstDiagloueScriptedSequence*)Obj)->bIsDisabled = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AFirstDiagloueScriptedSequence_Statics::NewProp_bIsDisabled = { "bIsDisabled", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AFirstDiagloueScriptedSequence), &Z_Construct_UClass_AFirstDiagloueScriptedSequence_Statics::NewProp_bIsDisabled_SetBit, METADATA_PARAMS(Z_Construct_UClass_AFirstDiagloueScriptedSequence_Statics::NewProp_bIsDisabled_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AFirstDiagloueScriptedSequence_Statics::NewProp_bIsDisabled_MetaData)) };
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_AFirstDiagloueScriptedSequence_Statics::NewProp_TargetIDs_Inner = { "TargetIDs", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFirstDiagloueScriptedSequence_Statics::NewProp_TargetIDs_MetaData[] = {
		{ "Category", "Trigger" },
		{ "ModuleRelativePath", "FirstDiagloueScriptedSequence.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AFirstDiagloueScriptedSequence_Statics::NewProp_TargetIDs = { "TargetIDs", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFirstDiagloueScriptedSequence, TargetIDs), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_AFirstDiagloueScriptedSequence_Statics::NewProp_TargetIDs_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AFirstDiagloueScriptedSequence_Statics::NewProp_TargetIDs_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFirstDiagloueScriptedSequence_Statics::NewProp_SoundAttenuation_MetaData[] = {
		{ "Category", "Audio" },
		{ "ModuleRelativePath", "FirstDiagloueScriptedSequence.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFirstDiagloueScriptedSequence_Statics::NewProp_SoundAttenuation = { "SoundAttenuation", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFirstDiagloueScriptedSequence, SoundAttenuation), Z_Construct_UClass_USoundAttenuation_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AFirstDiagloueScriptedSequence_Statics::NewProp_SoundAttenuation_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AFirstDiagloueScriptedSequence_Statics::NewProp_SoundAttenuation_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AFirstDiagloueScriptedSequence_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFirstDiagloueScriptedSequence_Statics::NewProp_VoiceLine,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFirstDiagloueScriptedSequence_Statics::NewProp_bIsDisabled,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFirstDiagloueScriptedSequence_Statics::NewProp_TargetIDs_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFirstDiagloueScriptedSequence_Statics::NewProp_TargetIDs,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFirstDiagloueScriptedSequence_Statics::NewProp_SoundAttenuation,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AFirstDiagloueScriptedSequence_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AFirstDiagloueScriptedSequence>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AFirstDiagloueScriptedSequence_Statics::ClassParams = {
		&AFirstDiagloueScriptedSequence::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AFirstDiagloueScriptedSequence_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AFirstDiagloueScriptedSequence_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AFirstDiagloueScriptedSequence_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AFirstDiagloueScriptedSequence_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AFirstDiagloueScriptedSequence()
	{
		if (!Z_Registration_Info_UClass_AFirstDiagloueScriptedSequence.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AFirstDiagloueScriptedSequence.OuterSingleton, Z_Construct_UClass_AFirstDiagloueScriptedSequence_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AFirstDiagloueScriptedSequence.OuterSingleton;
	}
	template<> LIDAR_API UClass* StaticClass<AFirstDiagloueScriptedSequence>()
	{
		return AFirstDiagloueScriptedSequence::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AFirstDiagloueScriptedSequence);
	struct Z_CompiledInDeferFile_FID_LiDAR_Source_LiDAR_FirstDiagloueScriptedSequence_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_LiDAR_Source_LiDAR_FirstDiagloueScriptedSequence_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AFirstDiagloueScriptedSequence, AFirstDiagloueScriptedSequence::StaticClass, TEXT("AFirstDiagloueScriptedSequence"), &Z_Registration_Info_UClass_AFirstDiagloueScriptedSequence, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AFirstDiagloueScriptedSequence), 657207088U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_LiDAR_Source_LiDAR_FirstDiagloueScriptedSequence_h_2231520618(TEXT("/Script/LiDAR"),
		Z_CompiledInDeferFile_FID_LiDAR_Source_LiDAR_FirstDiagloueScriptedSequence_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_LiDAR_Source_LiDAR_FirstDiagloueScriptedSequence_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
