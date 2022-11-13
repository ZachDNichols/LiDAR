// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AFirstPersonCharacter;
#ifdef LIDAR_LEMON_generated_h
#error "LEMON.generated.h already included, missing '#pragma once' in LEMON.h"
#endif
#define LIDAR_LEMON_generated_h

#define FID_LiDAR_Source_LiDAR_LEMON_h_19_SPARSE_DATA
#define FID_LiDAR_Source_LiDAR_LEMON_h_19_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execEndPlay); \
	DECLARE_FUNCTION(execDecreaseRadius); \
	DECLARE_FUNCTION(execIncreaseRadius); \
	DECLARE_FUNCTION(execEndFire); \
	DECLARE_FUNCTION(execFire); \
	DECLARE_FUNCTION(execAttachWeapon);


#define FID_LiDAR_Source_LiDAR_LEMON_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execEndPlay); \
	DECLARE_FUNCTION(execDecreaseRadius); \
	DECLARE_FUNCTION(execIncreaseRadius); \
	DECLARE_FUNCTION(execEndFire); \
	DECLARE_FUNCTION(execFire); \
	DECLARE_FUNCTION(execAttachWeapon);


#define FID_LiDAR_Source_LiDAR_LEMON_h_19_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesALEMON(); \
	friend struct Z_Construct_UClass_ALEMON_Statics; \
public: \
	DECLARE_CLASS(ALEMON, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/LiDAR"), NO_API) \
	DECLARE_SERIALIZER(ALEMON)


#define FID_LiDAR_Source_LiDAR_LEMON_h_19_INCLASS \
private: \
	static void StaticRegisterNativesALEMON(); \
	friend struct Z_Construct_UClass_ALEMON_Statics; \
public: \
	DECLARE_CLASS(ALEMON, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/LiDAR"), NO_API) \
	DECLARE_SERIALIZER(ALEMON)


#define FID_LiDAR_Source_LiDAR_LEMON_h_19_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ALEMON(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ALEMON) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ALEMON); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ALEMON); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ALEMON(ALEMON&&); \
	NO_API ALEMON(const ALEMON&); \
public:


#define FID_LiDAR_Source_LiDAR_LEMON_h_19_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ALEMON(ALEMON&&); \
	NO_API ALEMON(const ALEMON&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ALEMON); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ALEMON); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ALEMON)


#define FID_LiDAR_Source_LiDAR_LEMON_h_16_PROLOG
#define FID_LiDAR_Source_LiDAR_LEMON_h_19_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_LiDAR_Source_LiDAR_LEMON_h_19_SPARSE_DATA \
	FID_LiDAR_Source_LiDAR_LEMON_h_19_RPC_WRAPPERS \
	FID_LiDAR_Source_LiDAR_LEMON_h_19_INCLASS \
	FID_LiDAR_Source_LiDAR_LEMON_h_19_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_LiDAR_Source_LiDAR_LEMON_h_19_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_LiDAR_Source_LiDAR_LEMON_h_19_SPARSE_DATA \
	FID_LiDAR_Source_LiDAR_LEMON_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_LiDAR_Source_LiDAR_LEMON_h_19_INCLASS_NO_PURE_DECLS \
	FID_LiDAR_Source_LiDAR_LEMON_h_19_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> LIDAR_API UClass* StaticClass<class ALEMON>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_LiDAR_Source_LiDAR_LEMON_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
