// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AFirstPersonCharacter;
class UPrimitiveComponent;
class AActor;
struct FHitResult;
#ifdef LIDAR_WeaponPickupComponent_generated_h
#error "WeaponPickupComponent.generated.h already included, missing '#pragma once' in WeaponPickupComponent.h"
#endif
#define LIDAR_WeaponPickupComponent_generated_h

#define FID_LiDAR_Source_LiDAR_WeaponPickupComponent_h_10_DELEGATE \
struct _Script_LiDAR_eventOnPickUp_Parms \
{ \
	AFirstPersonCharacter* PickUpCharacter; \
}; \
static inline void FOnPickUp_DelegateWrapper(const FMulticastScriptDelegate& OnPickUp, AFirstPersonCharacter* PickUpCharacter) \
{ \
	_Script_LiDAR_eventOnPickUp_Parms Parms; \
	Parms.PickUpCharacter=PickUpCharacter; \
	OnPickUp.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define FID_LiDAR_Source_LiDAR_WeaponPickupComponent_h_15_SPARSE_DATA
#define FID_LiDAR_Source_LiDAR_WeaponPickupComponent_h_15_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnSphereBeginOverlap);


#define FID_LiDAR_Source_LiDAR_WeaponPickupComponent_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnSphereBeginOverlap);


#define FID_LiDAR_Source_LiDAR_WeaponPickupComponent_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUWeaponPickupComponent(); \
	friend struct Z_Construct_UClass_UWeaponPickupComponent_Statics; \
public: \
	DECLARE_CLASS(UWeaponPickupComponent, USphereComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/LiDAR"), NO_API) \
	DECLARE_SERIALIZER(UWeaponPickupComponent)


#define FID_LiDAR_Source_LiDAR_WeaponPickupComponent_h_15_INCLASS \
private: \
	static void StaticRegisterNativesUWeaponPickupComponent(); \
	friend struct Z_Construct_UClass_UWeaponPickupComponent_Statics; \
public: \
	DECLARE_CLASS(UWeaponPickupComponent, USphereComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/LiDAR"), NO_API) \
	DECLARE_SERIALIZER(UWeaponPickupComponent)


#define FID_LiDAR_Source_LiDAR_WeaponPickupComponent_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UWeaponPickupComponent(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UWeaponPickupComponent) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UWeaponPickupComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UWeaponPickupComponent); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UWeaponPickupComponent(UWeaponPickupComponent&&); \
	NO_API UWeaponPickupComponent(const UWeaponPickupComponent&); \
public:


#define FID_LiDAR_Source_LiDAR_WeaponPickupComponent_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UWeaponPickupComponent(UWeaponPickupComponent&&); \
	NO_API UWeaponPickupComponent(const UWeaponPickupComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UWeaponPickupComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UWeaponPickupComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UWeaponPickupComponent)


#define FID_LiDAR_Source_LiDAR_WeaponPickupComponent_h_12_PROLOG
#define FID_LiDAR_Source_LiDAR_WeaponPickupComponent_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_LiDAR_Source_LiDAR_WeaponPickupComponent_h_15_SPARSE_DATA \
	FID_LiDAR_Source_LiDAR_WeaponPickupComponent_h_15_RPC_WRAPPERS \
	FID_LiDAR_Source_LiDAR_WeaponPickupComponent_h_15_INCLASS \
	FID_LiDAR_Source_LiDAR_WeaponPickupComponent_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_LiDAR_Source_LiDAR_WeaponPickupComponent_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_LiDAR_Source_LiDAR_WeaponPickupComponent_h_15_SPARSE_DATA \
	FID_LiDAR_Source_LiDAR_WeaponPickupComponent_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_LiDAR_Source_LiDAR_WeaponPickupComponent_h_15_INCLASS_NO_PURE_DECLS \
	FID_LiDAR_Source_LiDAR_WeaponPickupComponent_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> LIDAR_API UClass* StaticClass<class UWeaponPickupComponent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_LiDAR_Source_LiDAR_WeaponPickupComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
