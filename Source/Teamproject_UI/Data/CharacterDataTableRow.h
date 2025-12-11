// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CharacterDataTableRow.generated.h"
/**
 * 
 */

USTRUCT(BlueprintType)
struct FCharacterDataTableRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnyWhere, BlueprintReadOnly)
	FString CharacterName;

	UPROPERTY(EditAnyWhere, BlueprintReadOnly)
	TObjectPtr<UTexture2D> CharacterIcon;

	UPROPERTY(EditAnyWhere, BlueprintReadOnly)
	TObjectPtr<UTexture2D> CharacterIllustration;
};
