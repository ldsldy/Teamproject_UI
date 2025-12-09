// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PlayerStatusViewModel.generated.h"

// --- 위젯에 체력 및 자원 변경을 알리기 위한 델리게이트 ---
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPlayerHealthChanged, float, NewHealthPercent);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPlayerResourceChanged, float, NewResourcePercent);

// --- 위젯에 플레이어 아이콘 변경을 알리기 위한 델리게이트 --- 
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPlayerIconChanged, UTexture2D*, NewPlayerIcon);

// --- 체력 텍스트 포함 버전 ---
//DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPlayerHealthChanged, float, NewHealthPercent, FText, NewHealthText);


/**
 * 
 */
UCLASS(Blueprintable)
class TEAMPROJECT_UI_API UPlayerStatusViewModel : public UObject
{
	GENERATED_BODY()
	
public:
	// --- 플레이어의 체력 설정 함수 ---
	void SetHealth(float CurrentHealth, float MaxHealth);

	// --- 플레이어의 자원 설정 함수 ---
	void SetResource(float CurrentResource, float MaxResource);

	// --- 플레이어 아이콘 설정 함수 ---
	void SetIcon(UTexture2D* NewIcon);

public:
	// --- 플레이어의 체력 변경 델리게이트 ---
	UPROPERTY(BlueprintAssignable)
	FOnPlayerHealthChanged OnPlayerHealthChanged;

	// --- 플레이어의 자원 변경 델리게이트 ---
	UPROPERTY(BlueprintAssignable)
	FOnPlayerResourceChanged OnPlayerResourceChanged;

	// --- 플레이어 아이콘 변경 델리게이트 ---
	UPROPERTY(BlueprintAssignable)
	FOnPlayerIconChanged OnPlayerIconChanged;

	// --- 체력 텍스트 포함 버전 ---
	//FOnPlayerHealthChanged OnPlayerHealthChangedWithText;
};
