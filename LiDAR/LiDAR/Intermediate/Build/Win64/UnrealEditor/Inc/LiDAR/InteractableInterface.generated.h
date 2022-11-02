// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef LIDAR_InteractableInterface_generated_h
#error "InteractableInterface.generated.h already included, missing '#pragma once' in InteractableInterface.h"
#endif
#define LIDAR_InteractableInterface_generated_h

#define FID_LiDAR_Source_LiDAR_InteractableInterface_h_13_SPARSE_DATA
#define FID_LiDAR_Source_LiDAR_InteractableInterface_h_13_RPC_WRAPPERS \
	virtual void Interact_Implementation(bool bInteracting) {}; \
	virtual FName GetInteractTag_Implementation() { return NAME_None; }; \
 \
	DECLARE_FUNCTION(execInteract); \
	DECLARE_FUNCTION(execGetInteractTag);


#define FID_LiDAR_Source_LiDAR_InteractableInterface_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual void Interact_Implementation(bool bInteracting) {}; \
	virtual FName GetInteractTag_Implementation() { return NAME_None; }; \
 \
	DECLARE_FUNCTION(execInteract); \
	DECLARE_FUNCTION(execGetInteractTag);


#define FID_LiDAR_Source_LiDAR_InteractableInterface_h_13_EVENT_PARMS \
	struct InteractableInterface_eventGetInteractTag_Parms \
	{ \
		FName ReturnValue; \
	}; \
	struct InteractableInterface_eventInteract_Parms \
	{ \
		bool bInteracting; \
	};


#define FID_LiDAR_Source_LiDAR_InteractableInterface_h_13_CALLBACK_WRAPPERS
#define FID_LiDAR_Source_LiDAR_InteractableInterface_h_13_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	LIDAR_API UInteractableInterface(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UInteractableInterface) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(LIDAR_API, UInteractableInterface); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UInteractableInterface); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	LIDAR_API UInteractableInterface(UInteractableInterface&&); \
	LIDAR_API UInteractableInterface(const UInteractableInterface&); \
public:


#define FID_LiDAR_Source_LiDAR_InteractableInterface_h_13_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	LIDAR_API UInteractableInterface(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	LIDAR_API UInteractableInterface(UInteractableInterface&&); \
	LIDAR_API UInteractableInterface(const UInteractableInterface&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(LIDAR_API, UInteractableInterface); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UInteractableInterface); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UInteractableInterface)


#define FID_LiDAR_Source_LiDAR_InteractableInterface_h_13_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUInteractableInterface(); \
	friend struct Z_Construct_UClass_UInteractableInterface_Statics; \
public: \
	DECLARE_CLASS(UInteractableInterface, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/LiDAR"), LIDAR_API) \
	DECLARE_SERIALIZER(UInteractableInterface)


#define FID_LiDAR_Source_LiDAR_InteractableInterface_h_13_GENERATED_BODY_LEGACY \
		PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_LiDAR_Source_LiDAR_InteractableInterface_h_13_GENERATED_UINTERFACE_BODY() \
	FID_LiDAR_Source_LiDAR_InteractableInterface_h_13_STANDARD_CONSTRUCTORS \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_LiDAR_Source_LiDAR_InteractableInterface_h_13_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_LiDAR_Source_LiDAR_InteractableInterface_h_13_GENERATED_UINTERFACE_BODY() \
	FID_LiDAR_Source_LiDAR_InteractableInterface_h_13_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_LiDAR_Source_LiDAR_InteractableInterface_h_13_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~IInteractableInterface() {} \
public: \
	typedef UInteractableInterface UClassType; \
	typedef IInteractableInterface ThisClass; \
	static FName Execute_GetInteractTag(UObject* O); \
	static void Execute_Interact(UObject* O, bool bInteracting); \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_LiDAR_Source_LiDAR_InteractableInterface_h_13_INCLASS_IINTERFACE \
protected: \
	virtual ~IInteractableInterface() {} \
public: \
	typedef UInteractableInterface UClassType; \
	typedef IInteractableInterface ThisClass; \
	static FName Execute_GetInteractTag(UObject* O); \
	static void Execute_Interact(UObject* O, bool bInteracting); \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_LiDAR_Source_LiDAR_InteractableInterface_h_10_PROLOG \
	FID_LiDAR_Source_LiDAR_InteractableInterface_h_13_EVENT_PARMS


#define FID_LiDAR_Source_LiDAR_InteractableInterface_h_21_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_LiDAR_Source_LiDAR_InteractableInterface_h_13_SPARSE_DATA \
	FID_LiDAR_Source_LiDAR_InteractableInterface_h_13_RPC_WRAPPERS \
	FID_LiDAR_Source_LiDAR_InteractableInterface_h_13_CALLBACK_WRAPPERS \
	FID_LiDAR_Source_LiDAR_InteractableInterface_h_13_INCLASS_IINTERFACE \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_LiDAR_Source_LiDAR_InteractableInterface_h_21_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_LiDAR_Source_LiDAR_InteractableInterface_h_13_SPARSE_DATA \
	FID_LiDAR_Source_LiDAR_InteractableInterface_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_LiDAR_Source_LiDAR_InteractableInterface_h_13_CALLBACK_WRAPPERS \
	FID_LiDAR_Source_LiDAR_InteractableInterface_h_13_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> LIDAR_API UClass* StaticClass<class UInteractableInterface>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_LiDAR_Source_LiDAR_InteractableInterface_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
