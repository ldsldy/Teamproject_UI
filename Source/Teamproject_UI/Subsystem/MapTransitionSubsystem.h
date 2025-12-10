// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "MapTransitionSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class TEAMPROJECT_UI_API UMapTransitionSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
public:
	void GoToNextStage();

private:
	void SetCurrentStage();
private:
	// ---로비 정보---
	
	// --- 현재 스테이지 단계 ---

};
