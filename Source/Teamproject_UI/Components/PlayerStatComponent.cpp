// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerStatComponent.h"
#include "Teamproject_UI/Subsystem/MVVMSubsystem.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UPlayerStatComponent::UPlayerStatComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UPlayerStatComponent::SetHealth(float NewHealth)
{
	CurrentHealth = FMath::Clamp(NewHealth, 0.0f, MaxHealth);

	if(OnHealthChanged.IsBound())
	{
		OnHealthChanged.Broadcast(CurrentHealth, MaxHealth);
	}
}

void UPlayerStatComponent::SetMaxHealth(float NewMaxHealth)
{
	MaxHealth = FMath::Max(0.0f, NewMaxHealth);
	if(OnHealthChanged.IsBound())
	{
		OnHealthChanged.Broadcast(CurrentHealth, MaxHealth);
	}
}

void UPlayerStatComponent::SetResource(float NewResource)
{
	CurrentResource = FMath::Clamp(NewResource, 0.0f, MaxResource);
	if (OnResourceChanged.IsBound())
	{
		OnResourceChanged.Broadcast(CurrentResource, MaxResource);
	}
}


// Called when the game starts
void UPlayerStatComponent::BeginPlay()
{
	Super::BeginPlay();

	if (UMVVMSubsystem* mVVMSubsystem = UGameplayStatics::GetGameInstance(this)->GetSubsystem<UMVVMSubsystem>())
	{
		mVVMSubsystem->ResgisterPlayerStatComp(this);
	}
}

void UPlayerStatComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	if (UMVVMSubsystem* mVVMSubsystem = UGameplayStatics::GetGameInstance(this)->GetSubsystem<UMVVMSubsystem>())
	{
		mVVMSubsystem->UnregisterPlayerStatComp(this);
	}

	Super::EndPlay(EndPlayReason);
}


// Called every frame
void UPlayerStatComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

