// Copyright Epic Games, Inc. All Rights Reserved.

#include "UnrealMegaJamGameMode.h"
#include "UnrealMegaJamCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUnrealMegaJamGameMode::AUnrealMegaJamGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
