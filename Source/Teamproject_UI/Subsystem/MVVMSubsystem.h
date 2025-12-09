// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "MVVMSubsystem.generated.h"

class UPlayerStatusViewModel;
/**
 * 
 */
UCLASS()
class TEAMPROJECT_UI_API UMVVMSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintPure)
	UPlayerStatusViewModel* GetPlayerStatusViewModel();

private:
	UPROPERTY()
	TObjectPtr<UPlayerStatusViewModel> PlayerStatusViewModel;
};
