// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CharacterDataObject.generated.h"

/**
 * 
 */
UCLASS()
class TEAMPROJECT_UI_API UCharacterDataObject : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	TObjectPtr<UTexture2D> CharacterIcon;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<UTexture2D> CharacterIllustration;
};
