// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Teamproject_UI/Data/ChapterData.h"
#include "GameStateSubsystem.generated.h"

UENUM(BlueprintType)
enum class EGameState : uint8
{
	EGS_None			UMETA(DisplayName = "None"),
	EGS_MainMenu		UMETA(DisplayName = "MainMenu"),	  // 메인 메뉴 화면
	EGS_Lobby			UMETA(DisplayName = "Lobby"),		  // 로비 화면
	EGS_InGame			UMETA(DisplayName = "In Game"),		  // 플레이 중
	EGS_Paused			UMETA(DisplayName = "Paused"),		  // 메뉴도 열려있는 상태
	EGS_ChapterClear	UMETA(DisplayName = "Chapter Clear"), // 챕터 클리어 화면
	EGS_GameOver		UMETA(DisplayName = "Game Over")	  // 게임 오버 화면
};

USTRUCT(BlueprintType)
struct FStageInfo
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	int32 Chapter = 1;

	UPROPERTY(BlueprintReadWrite)
	int32 Stage = 1;
};

USTRUCT(BlueprintType)
struct FPlayingGameData
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "Game State")
	FStageInfo CurrentStage; 			// 현재 스테이지 번호
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGameStateChanged, EGameState, NewState);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnStageChanged, FStageInfo, NewStage);
/**
 * 
 */
UCLASS()
class TEAMPROJECT_UI_API UGameStateSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	// ===============================================
	// 메인 메뉴 관련 함수들
	// ===============================================
	UFUNCTION(BlueprintCallable, Category = "Game State")
	void StartNewGame();
	
	UFUNCTION(BlueprintCallable, Category = "Game State")
	void ContinueGame();

	UFUNCTION(BlueprintCallable, Category = "Game State")
	void ReturnMainMenu();

	UFUNCTION(BlueprintCallable, Category = "Game State")
	void QuitGame();

	// ===============================================
	// 로비 관련 함수들
	// =============================================== 
	
	// --- 로비 입장 ---
	UFUNCTION(BlueprintCallable, Category = "Lobby")
	void GoToLobby();
	
	// --- 스테이지 시작 ---
	UFUNCTION(BlueprintCallable, Category = "Lobby")
	void StartFromLobby();

	// ===============================================
	// 스테이지 진행 관련 함수들
	// ===============================================
	UFUNCTION(BlueprintCallable, Category = "Stage")
	void OnStageClear();

	UFUNCTION(BlueprintCallable, Category = "Stage")
	void ContinueToNextStage();

	UFUNCTION(BlueprintCallable, Category = "Stage")
	void OnPlayerDeath();

	// ===============================================
	// Getter 함수들
	// ===============================================
	UFUNCTION(BlueprintPure, Category = "Game State")
	EGameState GetCurrentGameState() const { return CurrentState; }

	UFUNCTION(BlueprintPure, Category = "Stage")
	FStageInfo GetCurrentStageInfo() const { return PlayingGameData.CurrentStage;}

	UFUNCTION(BlueprintPure, Category = "Stage")
	const FPlayingGameData& GetPlayingGameData() const { return PlayingGameData; }

	UFUNCTION(BlueprintPure, Category = "Game State")
	bool CanContinueGame() const;

	UFUNCTION(BlueprintPure, Category = "Chapter")
	bool GetCurrentChapterInfo(FChapterInfo& OutInfo) const;

	// ===============================================
	// 이벤트 델리게이트들
	// ===============================================
	UPROPERTY(BlueprintAssignable)
	FOnGameStateChanged OnGameStateChanged;
	UPROPERTY(BlueprintAssignable)
	FOnStageChanged OnStageChanged;

private:
	// ===============================================
	// 헬퍼 함수들
	// ===============================================
	void SetGameState(EGameState NewState);
	void ResetPlayingGameData();
	void AdvanceToNextStage();
	void StartCurrentStage();
	void SaveProgress();
	void LoadProgress();
	void LoadChapterData();

	bool IsLastStageOfChapter() const;

/////////////////////////////////////////////////////
// 변수 영역
/////////////////////////////////////////////////////
private:
	UPROPERTY()
	EGameState CurrentState = EGameState::EGS_None;

	UPROPERTY()
	FPlayingGameData PlayingGameData;

	// --- 스테이지와 챕터 정보 ---
	UPROPERTY()
	TObjectPtr<UChapterDataAsset> ChapterData = nullptr;

	// --- 맵 이름들 ---
	FName MainMenuMap	= TEXT("MainMenu");
	FName LobbyMap		= TEXT("Lobby");
};
