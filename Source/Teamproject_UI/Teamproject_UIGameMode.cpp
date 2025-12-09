// Copyright Epic Games, Inc. All Rights Reserved.

#include "Teamproject_UIGameMode.h"
#include "Teamproject_UICharacter.h"
#include "UObject/ConstructorHelpers.h"

ATeamproject_UIGameMode::ATeamproject_UIGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
