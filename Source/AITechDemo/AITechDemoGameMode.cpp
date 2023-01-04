// Copyright Epic Games, Inc. All Rights Reserved.

#include "AITechDemoGameMode.h"
#include "AITechDemoPlayerController.h"
#include "AITechDemoCharacter.h"
#include "UObject/ConstructorHelpers.h"

AAITechDemoGameMode::AAITechDemoGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AAITechDemoPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownPlayerController"));
	if(PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
}