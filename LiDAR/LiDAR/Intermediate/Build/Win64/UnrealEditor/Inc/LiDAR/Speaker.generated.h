// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef LIDAR_Speaker_generated_h
#error "Speaker.generated.h already included, missing '#pragma once' in Speaker.h"
#endif
#define LIDAR_Speaker_generated_h

#define FID_LiDAR_Source_LiDAR_Speaker_h_15_SPARSE_DATA
#define FID_LiDAR_Source_LiDAR_Speaker_h_15_RPC_WRAPPERS
#define FID_LiDAR_Source_LiDAR_Speaker_h_15_RPC_WRAPPERS_NO_PURE_DECLS
#define FID_LiDAR_Source_LiDAR_Speaker_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesASpeaker(); \
	friend struct Z_Construct_UClass_ASpeaker_Statics; \
public: \
	DECLARE_CLASS(ASpeaker, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/LiDAR"), NO_API) \
	DECLARE_SERIALIZER(ASpeaker) \
	virtual UObject* _getUObject() const override { return const_cast<ASpeaker*>(this); }


#define FID_LiDAR_Source_LiDAR_Speaker_h_15_INCLASS \
private: \
	static void StaticRegisterNativesASpeaker(); \
	friend struct Z_Construct_UClass_ASpeaker_Statics; \
public: \
	DECLARE_CLASS(ASpeaker, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/LiDAR"), NO_API) \
	DECLARE_SERIALIZER(ASpeaker) \
	virtual UObject* _getUObject() const override { return const_cast<ASpeaker*>(this); }


#define FID_LiDAR_Source_LiDAR_Speaker_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ASpeaker(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ASpeaker) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASpeaker); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASpeaker); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ASpeaker(ASpeaker&&); \
	NO_API ASpeaker(const ASpeaker&); \
public:


#define FID_LiDAR_Source_LiDAR_Speaker_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ASpeaker(ASpeaker&&); \
	NO_API ASpeaker(const ASpeaker&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASpeaker); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASpeaker); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ASpeaker)


#define FID_LiDAR_Source_LiDAR_Speaker_h_12_PROLOG
#define FID_LiDAR_Source_LiDAR_Speaker_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_LiDAR_Source_LiDAR_Speaker_h_15_SPARSE_DATA \
	FID_LiDAR_Source_LiDAR_Speaker_h_15_RPC_WRAPPERS \
	FID_LiDAR_Source_LiDAR_Speaker_h_15_INCLASS \
	FID_LiDAR_Source_LiDAR_Speaker_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_LiDAR_Source_LiDAR_Speaker_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_LiDAR_Source_LiDAR_Speaker_h_15_SPARSE_DATA \
	FID_LiDAR_Source_LiDAR_Speaker_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_LiDAR_Source_LiDAR_Speaker_h_15_INCLASS_NO_PURE_DECLS \
	FID_LiDAR_Source_LiDAR_Speaker_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> LIDAR_API UClass* StaticClass<class ASpeaker>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_LiDAR_Source_LiDAR_Speaker_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
