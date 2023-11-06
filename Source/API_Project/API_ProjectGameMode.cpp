// Copyright Epic Games, Inc. All Rights Reserved.

#include "API_ProjectGameMode.h"
#include "API_ProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"

AAPI_ProjectGameMode::AAPI_ProjectGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
