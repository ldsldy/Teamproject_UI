// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerStatusViewModel.h"

void UPlayerStatusViewModel::SetHealth(float CurrentHealth, float MaxHealth)
{
	float HealthPercent = FMath::Clamp(CurrentHealth / MaxHealth, 0.0f, 1.0f);
	OnPlayerHealthChanged.Broadcast(HealthPercent);

	// --- 체력 텍스트 포함 버전 ---
	//FText HealthText = FText::FromString(FString::Printf(TEXT("%d / %d"), FMath::RoundToInt(CurrentHealth), FMath::RoundToInt(MaxHealth)));
	//OnPlayerHealthChangedWithText.Broadcast(HealthPercent, HealthText);
}

void UPlayerStatusViewModel::SetResource(float CurrentResource, float MaxResource)
{
	float ResourcePercent = FMath::Clamp(CurrentResource / MaxResource, 0.0f, 1.0f);
	OnPlayerResourceChanged.Broadcast(ResourcePercent);
}


void UPlayerStatusViewModel::SetIcon(UTexture2D* NewIcon)
{
	if (!NewIcon) return;

	OnPlayerIconChanged.Broadcast(NewIcon);
}
