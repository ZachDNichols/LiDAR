// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef LIDAR_SpotlightActor_generated_h
#error "SpotlightActor.generated.h already included, missing '#pragma once' in SpotlightActor.h"
#endif
#define LIDAR_SpotlightActor_generated_h

#define FID_LiDAR_Source_LiDAR_SpotlightActor_h_15_SPARSE_DATA
#define FID_LiDAR_Source_LiDAR_SpotlightActor_h_15_RPC_WRAPPERS
#define FID_LiDAR_Source_LiDAR_SpotlightActor_h_15_RPC_WRAPPERS_NO_PURE_DECLS
#define FID_LiDAR_Source_LiDAR_SpotlightActor_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesASpotlightActor(); \
	friend struct Z_Construct_UClass_ASpotlightActor_Statics; \
public: \
	DECLARE_CLASS(ASpotlightActor, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/LiDAR"), NO_API) \
	DECLARE_SERIALIZER(ASpotlightActor) \
	virtual UObject* _getUObject() const override { return const_cast<ASpotlightActor*>(this); }


#define FID_LiDAR_Source_LiDAR_SpotlightActor_h_15_INCLASS \
private: \
	static void StaticRegisterNativesASpotlightActor(); \
	friend struct Z_Construct_UClass_ASpotlightActor_Statics; \
public: \
	DECLARE_CLASS(ASpotlightActor, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/LiDAR"), NO_API) \
	DECLARE_SERIALIZER(ASpotlightActor) \
	virtual UObject* _getUObject() const override { return const_cast<ASpotlightActor*>(this); }


#define FID_LiDAR_Source_LiDAR_SpotlightActor_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ASpotlightActor(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ASpotlightActor) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASpotlightActor); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASpotlightActor); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ASpotlightActor(ASpotlightActor&&); \
	NO_API ASpotlightActor(const ASpotlightActor&); \
public:


#define FID_LiDAR_Source_LiDAR_SpotlightActor_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ASpotlightActor(ASpotlightActor&&); \
	NO_API ASpotlightActor(const ASpotlightActor&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASpotlightActor); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASpotlightActor); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ASpotlightActor)


#define FID_LiDAR_Source_LiDAR_SpotlightActor_h_12_PROLOG
#define FID_LiDAR_Source_LiDAR_SpotlightActor_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_LiDAR_Source_LiDAR_SpotlightActor_h_15_SPARSE_DATA \
	FID_LiDAR_Source_LiDAR_SpotlightActor_h_15_RPC_WRAPPERS \
	FID_LiDAR_Source_LiDAR_SpotlightActor_h_15_INCLASS \
	FID_LiDAR_Source_LiDAR_SpotlightActor_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_LiDAR_Source_LiDAR_SpotlightActor_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_LiDAR_Source_LiDAR_SpotlightActor_h_15_SPARSE_DATA \
	FID_LiDAR_Source_LiDAR_SpotlightActor_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_LiDAR_Source_LiDAR_SpotlightActor_h_15_INCLASS_NO_PURE_DECLS \
	FID_LiDAR_Source_LiDAR_SpotlightActor_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> LIDAR_API UClass* StaticClass<class ASpotlightActor>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_LiDAR_Source_LiDAR_SpotlightActor_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
