// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Teamproject_UI/Data/CharacterDataTableRow.h"
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

	UFUNCTION()
	void OnCharacterSelected(UObject* SelectedItem);	

protected:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UTileView> CharacterTileView = nullptr;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UImage> CharacterImage = nullptr;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UButton> SelectButton = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "CharacterData")
	TObjectPtr<UDataTable> CharacterDataTable = nullptr;
};
