// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PlayerStatComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnHealthChanged, float, CurrentHealth, float, MaxHealth);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnResourceChanged, float, CurrentResource, float, MaxResource);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TEAMPROJECT_UI_API UPlayerStatComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPlayerStatComponent();

	UPROPERTY(BlueprintAssignable, Category = "Stat")
	FOnHealthChanged OnHealthChanged;
	UPROPERTY(BlueprintAssignable, Category = "Stat")
	FOnResourceChanged OnResourceChanged;

	// --- 체력 Setter 함수 ---
	UFUNCTION(BlueprintCallable)
	void SetHealth(float NewHealth);
	
	// --- 최대 체력 Setter 함수 ---
	UFUNCTION(BlueprintCallable)
	void SetMaxHealth(float NewMaxHealth);

	// --- 체력 Getter 함수 ---
	UFUNCTION(BlueprintCallable)
	float GetCurrentHealth() const{ return CurrentHealth; }
	UFUNCTION(BlueprintCallable)
	float GetMaxHealth() const { return MaxHealth; }

	// --- 자원 Setter 함수 ---
	UFUNCTION(BlueprintCallable)
	void SetResource(float NewResource);

	// -- 자원 Getter 함수 ---
	UFUNCTION(BlueprintCallable)
	float GetCurrentResource() const { return CurrentResource; }
	UFUNCTION(BlueprintCallable)
	float GetMaxResource() const { return MaxResource; }

	// --- 플레이어 아이콘 Getter 함수 ---
	UFUNCTION(BlueprintCallable)
	UTexture2D* GetPlayerIcon() const { return PlayerIcon; }

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Icon")
	TObjectPtr<class UTexture2D> PlayerIcon = nullptr;

private:
	float CurrentHealth = 100.0f;
	float MaxHealth = 100.0f;
	
	float CurrentResource = 100.0f;
	float MaxResource = 100.0f;
};
