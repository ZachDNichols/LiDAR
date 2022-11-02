// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef LIDAR_MovableStaticMeshComponent_generated_h
#error "MovableStaticMeshComponent.generated.h already included, missing '#pragma once' in MovableStaticMeshComponent.h"
#endif
#define LIDAR_MovableStaticMeshComponent_generated_h

#define FID_LiDAR_Source_LiDAR_MovableStaticMeshComponent_h_35_SPARSE_DATA
#define FID_LiDAR_Source_LiDAR_MovableStaticMeshComponent_h_35_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnMoveFinished); \
	DECLARE_FUNCTION(execOnMove); \
	DECLARE_FUNCTION(execMove);


#define FID_LiDAR_Source_LiDAR_MovableStaticMeshComponent_h_35_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnMoveFinished); \
	DECLARE_FUNCTION(execOnMove); \
	DECLARE_FUNCTION(execMove);


#define FID_LiDAR_Source_LiDAR_MovableStaticMeshComponent_h_35_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUMovableStaticMeshComponent(); \
	friend struct Z_Construct_UClass_UMovableStaticMeshComponent_Statics; \
public: \
	DECLARE_CLASS(UMovableStaticMeshComponent, UStaticMeshComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/LiDAR"), NO_API) \
	DECLARE_SERIALIZER(UMovableStaticMeshComponent)


#define FID_LiDAR_Source_LiDAR_MovableStaticMeshComponent_h_35_INCLASS \
private: \
	static void StaticRegisterNativesUMovableStaticMeshComponent(); \
	friend struct Z_Construct_UClass_UMovableStaticMeshComponent_Statics; \
public: \
	DECLARE_CLASS(UMovableStaticMeshComponent, UStaticMeshComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/LiDAR"), NO_API) \
	DECLARE_SERIALIZER(UMovableStaticMeshComponent)


#define FID_LiDAR_Source_LiDAR_MovableStaticMeshComponent_h_35_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UMovableStaticMeshComponent(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UMovableStaticMeshComponent) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMovableStaticMeshComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMovableStaticMeshComponent); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UMovableStaticMeshComponent(UMovableStaticMeshComponent&&); \
	NO_API UMovableStaticMeshComponent(const UMovableStaticMeshComponent&); \
public:


#define FID_LiDAR_Source_LiDAR_MovableStaticMeshComponent_h_35_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UMovableStaticMeshComponent(UMovableStaticMeshComponent&&); \
	NO_API UMovableStaticMeshComponent(const UMovableStaticMeshComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMovableStaticMeshComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMovableStaticMeshComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UMovableStaticMeshComponent)


#define FID_LiDAR_Source_LiDAR_MovableStaticMeshComponent_h_32_PROLOG
#define FID_LiDAR_Source_LiDAR_MovableStaticMeshComponent_h_35_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_LiDAR_Source_LiDAR_MovableStaticMeshComponent_h_35_SPARSE_DATA \
	FID_LiDAR_Source_LiDAR_MovableStaticMeshComponent_h_35_RPC_WRAPPERS \
	FID_LiDAR_Source_LiDAR_MovableStaticMeshComponent_h_35_INCLASS \
	FID_LiDAR_Source_LiDAR_MovableStaticMeshComponent_h_35_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_LiDAR_Source_LiDAR_MovableStaticMeshComponent_h_35_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_LiDAR_Source_LiDAR_MovableStaticMeshComponent_h_35_SPARSE_DATA \
	FID_LiDAR_Source_LiDAR_MovableStaticMeshComponent_h_35_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_LiDAR_Source_LiDAR_MovableStaticMeshComponent_h_35_INCLASS_NO_PURE_DECLS \
	FID_LiDAR_Source_LiDAR_MovableStaticMeshComponent_h_35_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> LIDAR_API UClass* StaticClass<class UMovableStaticMeshComponent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_LiDAR_Source_LiDAR_MovableStaticMeshComponent_h


#define FOREACH_ENUM_EROTATIONAXIS(op) \
	op(ERotationAxis::Yaw) \
	op(ERotationAxis::Pitch) \
	op(ERotationAxis::Roll) 

enum class ERotationAxis : uint8;
template<> LIDAR_API UEnum* StaticEnum<ERotationAxis>();

#define FOREACH_ENUM_ELOCATIONAXIS(op) \
	op(ELocationAxis::X) \
	op(ELocationAxis::Y) \
	op(ELocationAxis::Z) 

enum class ELocationAxis : uint8;
template<> LIDAR_API UEnum* StaticEnum<ELocationAxis>();

#define FOREACH_ENUM_EMOVEMENTTYPE(op) \
	op(EMovementType::Location) \
	op(EMovementType::Rotation) 

enum class EMovementType : uint8;
template<> LIDAR_API UEnum* StaticEnum<EMovementType>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
