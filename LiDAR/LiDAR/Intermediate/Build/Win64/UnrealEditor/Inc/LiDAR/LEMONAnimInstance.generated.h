// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AFirstPersonCharacter;
#ifdef LIDAR_LEMONAnimInstance_generated_h
#error "LEMONAnimInstance.generated.h already included, missing '#pragma once' in LEMONAnimInstance.h"
#endif
#define LIDAR_LEMONAnimInstance_generated_h

#define FID_LiDAR_Source_LiDAR_LEMONAnimInstance_h_18_SPARSE_DATA
#define FID_LiDAR_Source_LiDAR_LEMONAnimInstance_h_18_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execEndShoot); \
	DECLARE_FUNCTION(execShoot); \
	DECLARE_FUNCTION(execAssignCharacter); \
	DECLARE_FUNCTION(execUpdateAnimProperties);


#define FID_LiDAR_Source_LiDAR_LEMONAnimInstance_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execEndShoot); \
	DECLARE_FUNCTION(execShoot); \
	DECLARE_FUNCTION(execAssignCharacter); \
	DECLARE_FUNCTION(execUpdateAnimProperties);


#define FID_LiDAR_Source_LiDAR_LEMONAnimInstance_h_18_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesULEMONAnimInstance(); \
	friend struct Z_Construct_UClass_ULEMONAnimInstance_Statics; \
public: \
	DECLARE_CLASS(ULEMONAnimInstance, UAnimInstance, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/LiDAR"), NO_API) \
	DECLARE_SERIALIZER(ULEMONAnimInstance)


#define FID_LiDAR_Source_LiDAR_LEMONAnimInstance_h_18_INCLASS \
private: \
	static void StaticRegisterNativesULEMONAnimInstance(); \
	friend struct Z_Construct_UClass_ULEMONAnimInstance_Statics; \
public: \
	DECLARE_CLASS(ULEMONAnimInstance, UAnimInstance, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/LiDAR"), NO_API) \
	DECLARE_SERIALIZER(ULEMONAnimInstance)


#define FID_LiDAR_Source_LiDAR_LEMONAnimInstance_h_18_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ULEMONAnimInstance(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ULEMONAnimInstance) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ULEMONAnimInstance); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ULEMONAnimInstance); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ULEMONAnimInstance(ULEMONAnimInstance&&); \
	NO_API ULEMONAnimInstance(const ULEMONAnimInstance&); \
public:


#define FID_LiDAR_Source_LiDAR_LEMONAnimInstance_h_18_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ULEMONAnimInstance(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ULEMONAnimInstance(ULEMONAnimInstance&&); \
	NO_API ULEMONAnimInstance(const ULEMONAnimInstance&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ULEMONAnimInstance); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ULEMONAnimInstance); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ULEMONAnimInstance)


#define FID_LiDAR_Source_LiDAR_LEMONAnimInstance_h_15_PROLOG
#define FID_LiDAR_Source_LiDAR_LEMONAnimInstance_h_18_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_LiDAR_Source_LiDAR_LEMONAnimInstance_h_18_SPARSE_DATA \
	FID_LiDAR_Source_LiDAR_LEMONAnimInstance_h_18_RPC_WRAPPERS \
	FID_LiDAR_Source_LiDAR_LEMONAnimInstance_h_18_INCLASS \
	FID_LiDAR_Source_LiDAR_LEMONAnimInstance_h_18_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_LiDAR_Source_LiDAR_LEMONAnimInstance_h_18_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_LiDAR_Source_LiDAR_LEMONAnimInstance_h_18_SPARSE_DATA \
	FID_LiDAR_Source_LiDAR_LEMONAnimInstance_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_LiDAR_Source_LiDAR_LEMONAnimInstance_h_18_INCLASS_NO_PURE_DECLS \
	FID_LiDAR_Source_LiDAR_LEMONAnimInstance_h_18_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> LIDAR_API UClass* StaticClass<class ULEMONAnimInstance>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_LiDAR_Source_LiDAR_LEMONAnimInstance_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
