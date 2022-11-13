// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class USoundBase;
#ifdef LIDAR_SpeakerInterface_generated_h
#error "SpeakerInterface.generated.h already included, missing '#pragma once' in SpeakerInterface.h"
#endif
#define LIDAR_SpeakerInterface_generated_h

#define FID_LiDAR_Source_LiDAR_SpeakerInterface_h_14_SPARSE_DATA
#define FID_LiDAR_Source_LiDAR_SpeakerInterface_h_14_RPC_WRAPPERS \
	virtual void PlaySound_Implementation(USoundBase* Sound) {}; \
	virtual FName GetObjectTag_Implementation() { return NAME_None; }; \
 \
	DECLARE_FUNCTION(execPlaySound); \
	DECLARE_FUNCTION(execGetObjectTag);


#define FID_LiDAR_Source_LiDAR_SpeakerInterface_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual void PlaySound_Implementation(USoundBase* Sound) {}; \
	virtual FName GetObjectTag_Implementation() { return NAME_None; }; \
 \
	DECLARE_FUNCTION(execPlaySound); \
	DECLARE_FUNCTION(execGetObjectTag);


#define FID_LiDAR_Source_LiDAR_SpeakerInterface_h_14_EVENT_PARMS \
	struct SpeakerInterface_eventGetObjectTag_Parms \
	{ \
		FName ReturnValue; \
	}; \
	struct SpeakerInterface_eventPlaySound_Parms \
	{ \
		USoundBase* Sound; \
	};


#define FID_LiDAR_Source_LiDAR_SpeakerInterface_h_14_CALLBACK_WRAPPERS
#define FID_LiDAR_Source_LiDAR_SpeakerInterface_h_14_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	LIDAR_API USpeakerInterface(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USpeakerInterface) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(LIDAR_API, USpeakerInterface); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USpeakerInterface); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	LIDAR_API USpeakerInterface(USpeakerInterface&&); \
	LIDAR_API USpeakerInterface(const USpeakerInterface&); \
public:


#define FID_LiDAR_Source_LiDAR_SpeakerInterface_h_14_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	LIDAR_API USpeakerInterface(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	LIDAR_API USpeakerInterface(USpeakerInterface&&); \
	LIDAR_API USpeakerInterface(const USpeakerInterface&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(LIDAR_API, USpeakerInterface); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USpeakerInterface); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USpeakerInterface)


#define FID_LiDAR_Source_LiDAR_SpeakerInterface_h_14_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUSpeakerInterface(); \
	friend struct Z_Construct_UClass_USpeakerInterface_Statics; \
public: \
	DECLARE_CLASS(USpeakerInterface, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/LiDAR"), LIDAR_API) \
	DECLARE_SERIALIZER(USpeakerInterface)


#define FID_LiDAR_Source_LiDAR_SpeakerInterface_h_14_GENERATED_BODY_LEGACY \
		PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_LiDAR_Source_LiDAR_SpeakerInterface_h_14_GENERATED_UINTERFACE_BODY() \
	FID_LiDAR_Source_LiDAR_SpeakerInterface_h_14_STANDARD_CONSTRUCTORS \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_LiDAR_Source_LiDAR_SpeakerInterface_h_14_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_LiDAR_Source_LiDAR_SpeakerInterface_h_14_GENERATED_UINTERFACE_BODY() \
	FID_LiDAR_Source_LiDAR_SpeakerInterface_h_14_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_LiDAR_Source_LiDAR_SpeakerInterface_h_14_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~ISpeakerInterface() {} \
public: \
	typedef USpeakerInterface UClassType; \
	typedef ISpeakerInterface ThisClass; \
	static FName Execute_GetObjectTag(UObject* O); \
	static void Execute_PlaySound(UObject* O, USoundBase* Sound); \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_LiDAR_Source_LiDAR_SpeakerInterface_h_14_INCLASS_IINTERFACE \
protected: \
	virtual ~ISpeakerInterface() {} \
public: \
	typedef USpeakerInterface UClassType; \
	typedef ISpeakerInterface ThisClass; \
	static FName Execute_GetObjectTag(UObject* O); \
	static void Execute_PlaySound(UObject* O, USoundBase* Sound); \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_LiDAR_Source_LiDAR_SpeakerInterface_h_11_PROLOG \
	FID_LiDAR_Source_LiDAR_SpeakerInterface_h_14_EVENT_PARMS


#define FID_LiDAR_Source_LiDAR_SpeakerInterface_h_22_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_LiDAR_Source_LiDAR_SpeakerInterface_h_14_SPARSE_DATA \
	FID_LiDAR_Source_LiDAR_SpeakerInterface_h_14_RPC_WRAPPERS \
	FID_LiDAR_Source_LiDAR_SpeakerInterface_h_14_CALLBACK_WRAPPERS \
	FID_LiDAR_Source_LiDAR_SpeakerInterface_h_14_INCLASS_IINTERFACE \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_LiDAR_Source_LiDAR_SpeakerInterface_h_22_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_LiDAR_Source_LiDAR_SpeakerInterface_h_14_SPARSE_DATA \
	FID_LiDAR_Source_LiDAR_SpeakerInterface_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_LiDAR_Source_LiDAR_SpeakerInterface_h_14_CALLBACK_WRAPPERS \
	FID_LiDAR_Source_LiDAR_SpeakerInterface_h_14_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> LIDAR_API UClass* StaticClass<class USpeakerInterface>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_LiDAR_Source_LiDAR_SpeakerInterface_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
