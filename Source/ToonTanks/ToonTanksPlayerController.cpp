// Fill out your copyright notice in the Description page of Project Settings.


#include "ToonTanksPlayerController.h"
#include "GameFramework/Pawn.h"

void AToonTanksPlayerController::SetPlayerEnabledState(bool PlayerEnabled)
{
	if(PlayerEnabled)
	{
		GetPawn()->EnableInput(this);
	}
	else 
	{
		GetPawn()->DisableInput(this);
	}

	bShowMouseCursor = PlayerEnabled;
}
