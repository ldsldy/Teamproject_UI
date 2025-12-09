// Fill out your copyright notice in the Description page of Project Settings.


#include "MVVMSubsystem.h"
#include "TeamProject_UI/ViewModel/PlayerStatusViewModel.h"

UPlayerStatusViewModel* UMVVMSubsystem::GetPlayerStatusViewModel()
{
	if (!PlayerStatusViewModel)
	{
		PlayerStatusViewModel = NewObject<UPlayerStatusViewModel>(this);
	}	
	return PlayerStatusViewModel;
}
