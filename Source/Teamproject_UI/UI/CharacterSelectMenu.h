// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CharacterSelectMenu.generated.h"

/**
 * 
 */
UCLASS()
class TEAMPROJECT_UI_API UCharacterSelectMenu : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	virtual void NativeConstruct() override;

protected:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UTileView> CharacterTileView = nullptr;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UImage> CharacterImage = nullptr;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UButton> SelectButton = nullptr;
};
