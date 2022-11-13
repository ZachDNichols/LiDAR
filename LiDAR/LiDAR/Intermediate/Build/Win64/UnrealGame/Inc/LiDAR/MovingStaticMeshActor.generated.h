// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef LIDAR_MovingStaticMeshActor_generated_h
#error "MovingStaticMeshActor.generated.h already included, missing '#pragma once' in MovingStaticMeshActor.h"
#endif
#define LIDAR_MovingStaticMeshActor_generated_h

#define FID_LiDAR_Source_LiDAR_MovingStaticMeshActor_h_36_SPARSE_DATA
#define FID_LiDAR_Source_LiDAR_MovingStaticMeshActor_h_36_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execMove); \
	DECLARE_FUNCTION(execOnMoveFinished); \
	DECLARE_FUNCTION(execOnMove);


#define FID_LiDAR_Source_LiDAR_MovingStaticMeshActor_h_36_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execMove); \
	DECLARE_FUNCTION(execOnMoveFinished); \
	DECLARE_FUNCTION(execOnMove);


#define FID_LiDAR_Source_LiDAR_MovingStaticMeshActor_h_36_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAMovingStaticMeshActor(); \
	friend struct Z_Construct_UClass_AMovingStaticMeshActor_Statics; \
public: \
	DECLARE_CLASS(AMovingStaticMeshActor, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/LiDAR"), NO_API) \
	DECLARE_SERIALIZER(AMovingStaticMeshActor) \
	virtual UObject* _getUObject() const override { return const_cast<AMovingStaticMeshActor*>(this); }


#define FID_LiDAR_Source_LiDAR_MovingStaticMeshActor_h_36_INCLASS \
private: \
	static void StaticRegisterNativesAMovingStaticMeshActor(); \
	friend struct Z_Construct_UClass_AMovingStaticMeshActor_Statics; \
public: \
	DECLARE_CLASS(AMovingStaticMeshActor, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/LiDAR"), NO_API) \
	DECLARE_SERIALIZER(AMovingStaticMeshActor) \
	virtual UObject* _getUObject() const override { return const_cast<AMovingStaticMeshActor*>(this); }


#define FID_LiDAR_Source_LiDAR_MovingStaticMeshActor_h_36_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AMovingStaticMeshActor(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AMovingStaticMeshActor) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMovingStaticMeshActor); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMovingStaticMeshActor); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMovingStaticMeshActor(AMovingStaticMeshActor&&); \
	NO_API AMovingStaticMeshActor(const AMovingStaticMeshActor&); \
public:


#define FID_LiDAR_Source_LiDAR_MovingStaticMeshActor_h_36_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMovingStaticMeshActor(AMovingStaticMeshActor&&); \
	NO_API AMovingStaticMeshActor(const AMovingStaticMeshActor&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMovingStaticMeshActor); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMovingStaticMeshActor); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AMovingStaticMeshActor)


#define FID_LiDAR_Source_LiDAR_MovingStaticMeshActor_h_33_PROLOG
#define FID_LiDAR_Source_LiDAR_MovingStaticMeshActor_h_36_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_LiDAR_Source_LiDAR_MovingStaticMeshActor_h_36_SPARSE_DATA \
	FID_LiDAR_Source_LiDAR_MovingStaticMeshActor_h_36_RPC_WRAPPERS \
	FID_LiDAR_Source_LiDAR_MovingStaticMeshActor_h_36_INCLASS \
	FID_LiDAR_Source_LiDAR_MovingStaticMeshActor_h_36_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_LiDAR_Source_LiDAR_MovingStaticMeshActor_h_36_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_LiDAR_Source_LiDAR_MovingStaticMeshActor_h_36_SPARSE_DATA \
	FID_LiDAR_Source_LiDAR_MovingStaticMeshActor_h_36_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_LiDAR_Source_LiDAR_MovingStaticMeshActor_h_36_INCLASS_NO_PURE_DECLS \
	FID_LiDAR_Source_LiDAR_MovingStaticMeshActor_h_36_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> LIDAR_API UClass* StaticClass<class AMovingStaticMeshActor>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_LiDAR_Source_LiDAR_MovingStaticMeshActor_h


#define FOREACH_ENUM_EACTORROTATIONAXIS(op) \
	op(EActorRotationAxis::Yaw) \
	op(EActorRotationAxis::Pitch) \
	op(EActorRotationAxis::Roll) 

enum class EActorRotationAxis : uint8;
template<> LIDAR_API UEnum* StaticEnum<EActorRotationAxis>();

#define FOREACH_ENUM_EACTORLOCATIONAXIS(op) \
	op(EActorLocationAxis::X) \
	op(EActorLocationAxis::Y) \
	op(EActorLocationAxis::Z) 

enum class EActorLocationAxis : uint8;
template<> LIDAR_API UEnum* StaticEnum<EActorLocationAxis>();

#define FOREACH_ENUM_EACTORMOVEMENTTYPE(op) \
	op(EActorMovementType::Location) \
	op(EActorMovementType::Rotation) 

enum class EActorMovementType : uint8;
template<> LIDAR_API UEnum* StaticEnum<EActorMovementType>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
