// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterPreviewTile.h"

void UCharacterPreviewTile::NativeOnListItemObjectSet(UObject* ListItemObject)
{
	// MVVM을 이용하여 ListItemObject쪽으로 자신의 주소를 담아서 델리게이트 발송
	// 델리게이트를 받은 ListItemObject쪽에서 자신의 데이터를 다시 이곳으로 보내줌.
	
	//ListItemObject->
}
