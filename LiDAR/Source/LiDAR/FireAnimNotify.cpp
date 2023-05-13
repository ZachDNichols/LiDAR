// Copyright 2023 Zach Nichols, All Rights Reserved


#include "FireAnimNotify.h"
#include "LEMON.h"
#include "Engine.h"

void UFireAnimNotify::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	if (MeshComp)
	{
		if (ALEMON* Gun = Cast<ALEMON>(MeshComp->GetOwner()))
		{
			Gun->bIsFiring = true;
			UE_LOG(LogTemp, Display, TEXT("Firing"));
		}
	}
}

