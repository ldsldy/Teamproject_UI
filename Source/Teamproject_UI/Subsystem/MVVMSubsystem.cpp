// Fill out your copyright notice in the Description page of Project Settings.


#include "MVVMSubsystem.h"
#include "TeamProject_UI/ViewModel/PlayerStatusViewModel.h"
#include "TeamProject_UI/Components/PlayerStatComponent.h"

UPlayerStatusViewModel* UMVVMSubsystem::GetPlayerStatusViewModel()
{
	if (!PlayerStatusViewModel)
	{
		PlayerStatusViewModel = NewObject<UPlayerStatusViewModel>(this);
	}	
	return PlayerStatusViewModel;
}

void UMVVMSubsystem::ResgisterPlayerStatComp(UPlayerStatComponent* NewComp)
{
	if (!NewComp) return;

	// 기존에 등록된 컴포넌트가 있다면 해제(안정장치)
	UnregisterPlayerStatComp(NewComp);

	// 뷰모델 가져오기
	GetPlayerStatusViewModel();

	// 델리게이트 바인딩(컴포넌트의 체력이 바뀌면 -> 뷰모델의 SetHealth도 실행 등등)
	NewComp->OnHealthChanged.AddDynamic(PlayerStatusViewModel, &UPlayerStatusViewModel::SetHealth);
	NewComp->OnResourceChanged.AddDynamic(PlayerStatusViewModel, &UPlayerStatusViewModel::SetResource);
	
	// 초기 값 설정
	PlayerStatusViewModel->SetHealth(NewComp->GetCurrentHealth(), NewComp->GetMaxHealth());
	PlayerStatusViewModel->SetResource(NewComp->GetCurrentResource(), NewComp->GetMaxResource());
	PlayerStatusViewModel->SetPlayerIcon(NewComp->GetPlayerIcon());
}

void UMVVMSubsystem::UnregisterPlayerStatComp(UPlayerStatComponent* ExitingComp)
{
	if (ExitingComp && PlayerStatusViewModel)
	{
		// 델리게이트 언바인딩
		ExitingComp->OnHealthChanged.RemoveDynamic(PlayerStatusViewModel, &UPlayerStatusViewModel::SetHealth);
		ExitingComp->OnResourceChanged.RemoveDynamic(PlayerStatusViewModel, &UPlayerStatusViewModel::SetResource);
	}
}

