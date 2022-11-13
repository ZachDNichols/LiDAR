// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef LIDAR_Laser_generated_h
#error "Laser.generated.h already included, missing '#pragma once' in Laser.h"
#endif
#define LIDAR_Laser_generated_h

#define FID_LiDAR_Source_LiDAR_Laser_h_15_SPARSE_DATA
#define FID_LiDAR_Source_LiDAR_Laser_h_15_RPC_WRAPPERS
#define FID_LiDAR_Source_LiDAR_Laser_h_15_RPC_WRAPPERS_NO_PURE_DECLS
#define FID_LiDAR_Source_LiDAR_Laser_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesALaser(); \
	friend struct Z_Construct_UClass_ALaser_Statics; \
public: \
	DECLARE_CLASS(ALaser, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/LiDAR"), NO_API) \
	DECLARE_SERIALIZER(ALaser)


#define FID_LiDAR_Source_LiDAR_Laser_h_15_INCLASS \
private: \
	static void StaticRegisterNativesALaser(); \
	friend struct Z_Construct_UClass_ALaser_Statics; \
public: \
	DECLARE_CLASS(ALaser, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/LiDAR"), NO_API) \
	DECLARE_SERIALIZER(ALaser)


#define FID_LiDAR_Source_LiDAR_Laser_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ALaser(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ALaser) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ALaser); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ALaser); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ALaser(ALaser&&); \
	NO_API ALaser(const ALaser&); \
public:


#define FID_LiDAR_Source_LiDAR_Laser_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ALaser(ALaser&&); \
	NO_API ALaser(const ALaser&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ALaser); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ALaser); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ALaser)


#define FID_LiDAR_Source_LiDAR_Laser_h_12_PROLOG
#define FID_LiDAR_Source_LiDAR_Laser_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_LiDAR_Source_LiDAR_Laser_h_15_SPARSE_DATA \
	FID_LiDAR_Source_LiDAR_Laser_h_15_RPC_WRAPPERS \
	FID_LiDAR_Source_LiDAR_Laser_h_15_INCLASS \
	FID_LiDAR_Source_LiDAR_Laser_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_LiDAR_Source_LiDAR_Laser_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_LiDAR_Source_LiDAR_Laser_h_15_SPARSE_DATA \
	FID_LiDAR_Source_LiDAR_Laser_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_LiDAR_Source_LiDAR_Laser_h_15_INCLASS_NO_PURE_DECLS \
	FID_LiDAR_Source_LiDAR_Laser_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> LIDAR_API UClass* StaticClass<class ALaser>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_LiDAR_Source_LiDAR_Laser_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
