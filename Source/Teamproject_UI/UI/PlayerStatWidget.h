// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlayerStatWidget.generated.h"

/**
 * 
 */
UCLASS()
class TEAMPROJECT_UI_API UPlayerStatWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;

private:
	/// --- 뷰모델
	void SetPlayerHealth(float NewHealthPercent);
	void SetPlayerResource(float NewResourcePercent);
	void SetPlayerIcon(UTexture2D* NewPlayerIcon);

///==================== 변수 ======================== 

protected:
	// --- 플레이어의 체력 프로그레스바---
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UProgressBar> PlayerHPBar;

	// --- 플레이어의 자원 프로그레스바---
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UProgressBar> PlayerResourceBar;

	// --- 플레이어의 아이콘 이미지 ---
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UImage> PlayerIconImage;

	UPROPERTY()
	TObjectPtr<class UPlayerStatusViewModel> PlayerStatusViewModel;
};
