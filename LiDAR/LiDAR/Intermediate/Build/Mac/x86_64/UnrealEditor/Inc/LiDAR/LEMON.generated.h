// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef LIDAR_LEMON_generated_h
#error "LEMON.generated.h already included, missing '#pragma once' in LEMON.h"
#endif
#define LIDAR_LEMON_generated_h

#define FID_LiDAR_Source_LiDAR_LEMON_h_13_SPARSE_DATA
#define FID_LiDAR_Source_LiDAR_LEMON_h_13_RPC_WRAPPERS
#define FID_LiDAR_Source_LiDAR_LEMON_h_13_RPC_WRAPPERS_NO_PURE_DECLS
#define FID_LiDAR_Source_LiDAR_LEMON_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesULEMON(); \
	friend struct Z_Construct_UClass_ULEMON_Statics; \
public: \
	DECLARE_CLASS(ULEMON, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/LiDAR"), NO_API) \
	DECLARE_SERIALIZER(ULEMON)


#define FID_LiDAR_Source_LiDAR_LEMON_h_13_INCLASS \
private: \
	static void StaticRegisterNativesULEMON(); \
	friend struct Z_Construct_UClass_ULEMON_Statics; \
public: \
	DECLARE_CLASS(ULEMON, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/LiDAR"), NO_API) \
	DECLARE_SERIALIZER(ULEMON)


#define FID_LiDAR_Source_LiDAR_LEMON_h_13_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ULEMON(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ULEMON) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ULEMON); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ULEMON); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ULEMON(ULEMON&&); \
	NO_API ULEMON(const ULEMON&); \
public:


#define FID_LiDAR_Source_LiDAR_LEMON_h_13_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ULEMON(ULEMON&&); \
	NO_API ULEMON(const ULEMON&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ULEMON); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ULEMON); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ULEMON)


#define FID_LiDAR_Source_LiDAR_LEMON_h_10_PROLOG
#define FID_LiDAR_Source_LiDAR_LEMON_h_13_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_LiDAR_Source_LiDAR_LEMON_h_13_SPARSE_DATA \
	FID_LiDAR_Source_LiDAR_LEMON_h_13_RPC_WRAPPERS \
	FID_LiDAR_Source_LiDAR_LEMON_h_13_INCLASS \
	FID_LiDAR_Source_LiDAR_LEMON_h_13_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_LiDAR_Source_LiDAR_LEMON_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_LiDAR_Source_LiDAR_LEMON_h_13_SPARSE_DATA \
	FID_LiDAR_Source_LiDAR_LEMON_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_LiDAR_Source_LiDAR_LEMON_h_13_INCLASS_NO_PURE_DECLS \
	FID_LiDAR_Source_LiDAR_LEMON_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> LIDAR_API UClass* StaticClass<class ULEMON>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_LiDAR_Source_LiDAR_LEMON_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
