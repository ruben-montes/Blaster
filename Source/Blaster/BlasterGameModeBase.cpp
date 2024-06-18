// Copyright Epic Games, Inc. All Rights Reserved.

#include "BlasterGameModeBase.h"
#include "UObject/ConstructorHelpers.h"

ABlasterGameModeBase::ABlasterGameModeBase()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprints/Character/BP_BlasterCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
