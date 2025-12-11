// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterDataObject.h"
#include "Teamproject_UI/Data/CharacterDataTableRow.h"

void UCharacterDataObject::InitFromDataTableRow(const FCharacterDataTableRow& DataRow)
{
	CharacterType = DataRow.CharacterType;
	CharacterIcon = DataRow.CharacterIcon;
	CharacterIllustration = DataRow.CharacterIllustration;
}
