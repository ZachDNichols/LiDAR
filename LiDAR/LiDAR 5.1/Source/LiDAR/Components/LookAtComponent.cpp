// Copyright 2023 Zach Nichols, All Rights Reserved


#include "LookAtComponent.h"
#include "Camera/CameraComponent.h"
#include "Chaos/Utilities.h"
#include "Kismet/KismetMathLibrary.h"
#include "LiDAR/FirstPersonCharacter.h"

// Sets default values for this component's properties
ULookAtComponent::ULookAtComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	if (!bIgnoreOverlap)
	{
		OnComponentBeginOverlap.AddDynamic(this, &ULookAtComponent::OnSphereBeginOverlap);
		OnComponentEndOverlap.AddDynamic(this, &ULookAtComponent::OnSphereEndOverlap);
	}
	else
	{
		bInRange = true;
	}
}


// Called when the game starts
void ULookAtComponent::BeginPlay()
{
	Super::BeginPlay();

	Player = Cast<AFirstPersonCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn());
	ParentActor = GetOwner();
	if (Player)
	{
		PlayerCamera = Player->GetFirstPersonCameraComponent();
	}
}

void ULookAtComponent::OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor == Player)
	{
		bInRange = true;
	}
}

void ULookAtComponent::OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor == Player)
	{
		bInRange = false;
	}
}

bool ULookAtComponent::LookAt()
{
	if (bInRange)
	{
		FRotator LookAtRotation = UKismetMathLibrary::FindLookAtRotation(PlayerCamera->GetComponentLocation(), ParentActor->GetActorLocation());
		LookAtRotation.Normalize();
	
		float DotProduct = FVector::DotProduct(LookAtRotation.Vector(), PlayerCamera->GetForwardVector());
		DotProduct *= -1.f;
		UE_LOG(LogTemp, Display, TEXT("%f"), DotProduct);

		if (DotProduct > MinLookAtAngle && DotProduct < MaxLookAtAngle)
		{
			return true;
		}
	}
	
	return false;
}

// Called every frame
void ULookAtComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (!Player)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player or camera could not be found, trying again..."));
		Player = Cast<AFirstPersonCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn());
		PlayerCamera = Player->GetFirstPersonCameraComponent();
	}

	if (!PlayerCamera)
	{
		PlayerCamera = Player->GetFirstPersonCameraComponent();
	}

	if (Player && PlayerCamera)
	{
		PrimaryComponentTick.bCanEverTick = false;
	}
}

