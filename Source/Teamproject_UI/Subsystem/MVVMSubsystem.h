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
	// --- 뷰모델 반환 함수 ---
	UFUNCTION(BlueprintPure)
	UPlayerStatusViewModel* GetPlayerStatusViewModel();

	// --- 캐릭터, 컴포넌트 등록 및 해제 함수 ---
	UFUNCTION()
	void ResgisterPlayerStatComp(class UPlayerStatComponent* NewComp);
	UFUNCTION()
	void UnregisterPlayerStatComp(class UPlayerStatComponent* ExitingComp);

private:
	UPROPERTY()
	TObjectPtr<UPlayerStatusViewModel> PlayerStatusViewModel;
};
