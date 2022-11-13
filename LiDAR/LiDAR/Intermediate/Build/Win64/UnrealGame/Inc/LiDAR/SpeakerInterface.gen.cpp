// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LiDAR/SpeakerInterface.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSpeakerInterface() {}
// Cross Module References
	LIDAR_API UClass* Z_Construct_UClass_USpeakerInterface_NoRegister();
	LIDAR_API UClass* Z_Construct_UClass_USpeakerInterface();
	COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
	UPackage* Z_Construct_UPackage__Script_LiDAR();
	ENGINE_API UClass* Z_Construct_UClass_USoundBase_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(ISpeakerInterface::execPlaySound)
	{
		P_GET_OBJECT(USoundBase,Z_Param_Sound);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->PlaySound_Implementation(Z_Param_Sound);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ISpeakerInterface::execGetObjectTag)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FName*)Z_Param__Result=P_THIS->GetObjectTag_Implementation();
		P_NATIVE_END;
	}
	FName ISpeakerInterface::GetObjectTag()
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_GetObjectTag instead.");
		SpeakerInterface_eventGetObjectTag_Parms Parms;
		return Parms.ReturnValue;
	}
	void ISpeakerInterface::PlaySound(USoundBase* Sound)
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_PlaySound instead.");
	}
	void USpeakerInterface::StaticRegisterNativesUSpeakerInterface()
	{
		UClass* Class = USpeakerInterface::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetObjectTag", &ISpeakerInterface::execGetObjectTag },
			{ "PlaySound", &ISpeakerInterface::execPlaySound },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_USpeakerInterface_GetObjectTag_Statics
	{
		static const UECodeGen_Private::FNamePropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_USpeakerInterface_GetObjectTag_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SpeakerInterface_eventGetObjectTag_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USpeakerInterface_GetObjectTag_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USpeakerInterface_GetObjectTag_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USpeakerInterface_GetObjectTag_Statics::Function_MetaDataParams[] = {
		{ "Category", "Interact" },
		{ "ModuleRelativePath", "SpeakerInterface.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USpeakerInterface_GetObjectTag_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USpeakerInterface, nullptr, "GetObjectTag", nullptr, nullptr, sizeof(SpeakerInterface_eventGetObjectTag_Parms), Z_Construct_UFunction_USpeakerInterface_GetObjectTag_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USpeakerInterface_GetObjectTag_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USpeakerInterface_GetObjectTag_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USpeakerInterface_GetObjectTag_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USpeakerInterface_GetObjectTag()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USpeakerInterface_GetObjectTag_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USpeakerInterface_PlaySound_Statics
	{
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Sound;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USpeakerInterface_PlaySound_Statics::NewProp_Sound = { "Sound", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SpeakerInterface_eventPlaySound_Parms, Sound), Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USpeakerInterface_PlaySound_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USpeakerInterface_PlaySound_Statics::NewProp_Sound,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USpeakerInterface_PlaySound_Statics::Function_MetaDataParams[] = {
		{ "Category", "Interact" },
		{ "ModuleRelativePath", "SpeakerInterface.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USpeakerInterface_PlaySound_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USpeakerInterface, nullptr, "PlaySound", nullptr, nullptr, sizeof(SpeakerInterface_eventPlaySound_Parms), Z_Construct_UFunction_USpeakerInterface_PlaySound_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USpeakerInterface_PlaySound_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USpeakerInterface_PlaySound_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USpeakerInterface_PlaySound_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USpeakerInterface_PlaySound()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USpeakerInterface_PlaySound_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(USpeakerInterface);
	UClass* Z_Construct_UClass_USpeakerInterface_NoRegister()
	{
		return USpeakerInterface::StaticClass();
	}
	struct Z_Construct_UClass_USpeakerInterface_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USpeakerInterface_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UInterface,
		(UObject* (*)())Z_Construct_UPackage__Script_LiDAR,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_USpeakerInterface_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_USpeakerInterface_GetObjectTag, "GetObjectTag" }, // 614894306
		{ &Z_Construct_UFunction_USpeakerInterface_PlaySound, "PlaySound" }, // 318479738
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USpeakerInterface_Statics::Class_MetaDataParams[] = {
		{ "ModuleRelativePath", "SpeakerInterface.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_USpeakerInterface_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ISpeakerInterface>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_USpeakerInterface_Statics::ClassParams = {
		&USpeakerInterface::StaticClass,
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
		0x000840A1u,
		METADATA_PARAMS(Z_Construct_UClass_USpeakerInterface_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USpeakerInterface_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USpeakerInterface()
	{
		if (!Z_Registration_Info_UClass_USpeakerInterface.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USpeakerInterface.OuterSingleton, Z_Construct_UClass_USpeakerInterface_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_USpeakerInterface.OuterSingleton;
	}
	template<> LIDAR_API UClass* StaticClass<USpeakerInterface>()
	{
		return USpeakerInterface::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(USpeakerInterface);
	static FName NAME_USpeakerInterface_GetObjectTag = FName(TEXT("GetObjectTag"));
	FName ISpeakerInterface::Execute_GetObjectTag(UObject* O)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(USpeakerInterface::StaticClass()));
		SpeakerInterface_eventGetObjectTag_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_USpeakerInterface_GetObjectTag);
		if (Func)
		{
			O->ProcessEvent(Func, &Parms);
		}
		else if (auto I = (ISpeakerInterface*)(O->GetNativeInterfaceAddress(USpeakerInterface::StaticClass())))
		{
			Parms.ReturnValue = I->GetObjectTag_Implementation();
		}
		return Parms.ReturnValue;
	}
	static FName NAME_USpeakerInterface_PlaySound = FName(TEXT("PlaySound"));
	void ISpeakerInterface::Execute_PlaySound(UObject* O, USoundBase* Sound)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(USpeakerInterface::StaticClass()));
		SpeakerInterface_eventPlaySound_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_USpeakerInterface_PlaySound);
		if (Func)
		{
			Parms.Sound=Sound;
			O->ProcessEvent(Func, &Parms);
		}
		else if (auto I = (ISpeakerInterface*)(O->GetNativeInterfaceAddress(USpeakerInterface::StaticClass())))
		{
			I->PlaySound_Implementation(Sound);
		}
	}
	struct Z_CompiledInDeferFile_FID_LiDAR_Source_LiDAR_SpeakerInterface_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_LiDAR_Source_LiDAR_SpeakerInterface_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_USpeakerInterface, USpeakerInterface::StaticClass, TEXT("USpeakerInterface"), &Z_Registration_Info_UClass_USpeakerInterface, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USpeakerInterface), 787741526U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_LiDAR_Source_LiDAR_SpeakerInterface_h_2522299115(TEXT("/Script/LiDAR"),
		Z_CompiledInDeferFile_FID_LiDAR_Source_LiDAR_SpeakerInterface_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_LiDAR_Source_LiDAR_SpeakerInterface_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
