// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef LIDAR_Dot_generated_h
#error "Dot.generated.h already included, missing '#pragma once' in Dot.h"
#endif
#define LIDAR_Dot_generated_h

#define FID_LiDAR_Source_LiDAR_Dot_h_12_SPARSE_DATA
#define FID_LiDAR_Source_LiDAR_Dot_h_12_RPC_WRAPPERS
#define FID_LiDAR_Source_LiDAR_Dot_h_12_RPC_WRAPPERS_NO_PURE_DECLS
#define FID_LiDAR_Source_LiDAR_Dot_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesADot(); \
	friend struct Z_Construct_UClass_ADot_Statics; \
public: \
	DECLARE_CLASS(ADot, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/LiDAR"), NO_API) \
	DECLARE_SERIALIZER(ADot)


#define FID_LiDAR_Source_LiDAR_Dot_h_12_INCLASS \
private: \
	static void StaticRegisterNativesADot(); \
	friend struct Z_Construct_UClass_ADot_Statics; \
public: \
	DECLARE_CLASS(ADot, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/LiDAR"), NO_API) \
	DECLARE_SERIALIZER(ADot)


#define FID_LiDAR_Source_LiDAR_Dot_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ADot(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ADot) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ADot); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ADot); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ADot(ADot&&); \
	NO_API ADot(const ADot&); \
public:


#define FID_LiDAR_Source_LiDAR_Dot_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ADot(ADot&&); \
	NO_API ADot(const ADot&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ADot); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ADot); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ADot)


#define FID_LiDAR_Source_LiDAR_Dot_h_9_PROLOG
#define FID_LiDAR_Source_LiDAR_Dot_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_LiDAR_Source_LiDAR_Dot_h_12_SPARSE_DATA \
	FID_LiDAR_Source_LiDAR_Dot_h_12_RPC_WRAPPERS \
	FID_LiDAR_Source_LiDAR_Dot_h_12_INCLASS \
	FID_LiDAR_Source_LiDAR_Dot_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_LiDAR_Source_LiDAR_Dot_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_LiDAR_Source_LiDAR_Dot_h_12_SPARSE_DATA \
	FID_LiDAR_Source_LiDAR_Dot_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_LiDAR_Source_LiDAR_Dot_h_12_INCLASS_NO_PURE_DECLS \
	FID_LiDAR_Source_LiDAR_Dot_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> LIDAR_API UClass* StaticClass<class ADot>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_LiDAR_Source_LiDAR_Dot_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
