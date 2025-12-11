// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "CharacterPreviewTile.generated.h"

class UImage;
/**
 * 
 */
UCLASS()
class TEAMPROJECT_UI_API UCharacterPreviewTile : public UUserWidget, public IUserObjectListEntry
{
	GENERATED_BODY()
	
protected:
	virtual void NativeOnListItemObjectSet(UObject* ListItemObject) override;

protected:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UImage> CharacterIcon;
};
