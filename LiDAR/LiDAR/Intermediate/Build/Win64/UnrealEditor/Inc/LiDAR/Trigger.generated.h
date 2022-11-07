// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UPrimitiveComponent;
class AActor;
struct FHitResult;
#ifdef LIDAR_Trigger_generated_h
#error "Trigger.generated.h already included, missing '#pragma once' in Trigger.h"
#endif
#define LIDAR_Trigger_generated_h

#define FID_LiDAR_Source_LiDAR_Trigger_h_14_SPARSE_DATA
#define FID_LiDAR_Source_LiDAR_Trigger_h_14_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnBeginOverlap);


#define FID_LiDAR_Source_LiDAR_Trigger_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnBeginOverlap);


#define FID_LiDAR_Source_LiDAR_Trigger_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesATrigger(); \
	friend struct Z_Construct_UClass_ATrigger_Statics; \
public: \
	DECLARE_CLASS(ATrigger, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/LiDAR"), NO_API) \
	DECLARE_SERIALIZER(ATrigger)


#define FID_LiDAR_Source_LiDAR_Trigger_h_14_INCLASS \
private: \
	static void StaticRegisterNativesATrigger(); \
	friend struct Z_Construct_UClass_ATrigger_Statics; \
public: \
	DECLARE_CLASS(ATrigger, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/LiDAR"), NO_API) \
	DECLARE_SERIALIZER(ATrigger)


#define FID_LiDAR_Source_LiDAR_Trigger_h_14_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ATrigger(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ATrigger) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ATrigger); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ATrigger); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ATrigger(ATrigger&&); \
	NO_API ATrigger(const ATrigger&); \
public:


#define FID_LiDAR_Source_LiDAR_Trigger_h_14_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ATrigger(ATrigger&&); \
	NO_API ATrigger(const ATrigger&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ATrigger); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ATrigger); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ATrigger)


#define FID_LiDAR_Source_LiDAR_Trigger_h_11_PROLOG
#define FID_LiDAR_Source_LiDAR_Trigger_h_14_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_LiDAR_Source_LiDAR_Trigger_h_14_SPARSE_DATA \
	FID_LiDAR_Source_LiDAR_Trigger_h_14_RPC_WRAPPERS \
	FID_LiDAR_Source_LiDAR_Trigger_h_14_INCLASS \
	FID_LiDAR_Source_LiDAR_Trigger_h_14_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_LiDAR_Source_LiDAR_Trigger_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_LiDAR_Source_LiDAR_Trigger_h_14_SPARSE_DATA \
	FID_LiDAR_Source_LiDAR_Trigger_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_LiDAR_Source_LiDAR_Trigger_h_14_INCLASS_NO_PURE_DECLS \
	FID_LiDAR_Source_LiDAR_Trigger_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> LIDAR_API UClass* StaticClass<class ATrigger>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_LiDAR_Source_LiDAR_Trigger_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
