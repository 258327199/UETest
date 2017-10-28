// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "T418GameMode.h"
#include "T418Character.h"
#include "UObject/ConstructorHelpers.h"

AT418GameMode::AT418GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
