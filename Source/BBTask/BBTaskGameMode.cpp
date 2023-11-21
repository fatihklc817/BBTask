// Copyright Epic Games, Inc. All Rights Reserved.

#include "BBTaskGameMode.h"
#include "BBTaskCharacter.h"
#include "UObject/ConstructorHelpers.h"

ABBTaskGameMode::ABBTaskGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
