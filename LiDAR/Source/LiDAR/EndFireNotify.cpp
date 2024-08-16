// Copyright 2023 Zach Nichols, All Rights Reserved


#include "EndFireNotify.h"
#include "LEMON.h"
#include "Engine.h"

void UEndFireNotify::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	if (MeshComp)
	{
		if (ALEMON* Gun = Cast<ALEMON>(MeshComp->GetOwner()))
		{
			Gun->bIsFiring = false;
		}
	}
}

