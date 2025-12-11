// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerSelectMenu.h"
#include "Components/TileView.h"
#include "Components/Image.h"
#include "Components/Button.h"
#include "Teamproject_UI/Object/CharacterDataObject.h"

void UCharacterSelectMenu::NativeConstruct()
{
	Super::NativeConstruct();

	if (CharacterTileView)
	{
		// 게임 서브시스템에 캐릭터 데이터 테이블 저장
		// 게임 시작시에 게임 서브 시스템에서 캐릭터 데이터 테이블 로드
		

		// 데이터 테이블에서 캐릭터 정보를 차례로 불러와서
		// 각 캐릭터의 데이터가 들어있는 UObject를 생성한 후
		// TileView에 추가
		UCharacterDataObject* CharacterData = NewObject<UCharacterDataObject>(this);
		CharacterTileView->AddItem(CharacterData);
	}
		
}
