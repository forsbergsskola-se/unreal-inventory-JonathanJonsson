// Fill out your copyright notice in the Description page of Project Settings.


#include "Game Features/AddAbilities.h"

#include "AbilitySystemComponent.h"
#include "Components/GameFrameworkComponentManager.h"
#include "GameFeaturesSubsystem.h"

void UAddAbilities::OnGameFeatureActivating(FGameFeatureActivatingContext& Context)
{
	Super::OnGameFeatureActivating(Context);
	GameInstanceHandle = FWorldDelegates::OnStartGameInstance.AddUObject(this,&UAddAbilities::HandleGameInstanceStart);
}

void UAddAbilities::OnGameFeatureDeactivating(FGameFeatureDeactivatingContext& Context)
{
	Super::OnGameFeatureDeactivating(Context);
	FWorldDelegates::OnStartGameInstance.Remove(GameInstanceHandle);
}

void UAddAbilities::HandleGameInstanceStart(UGameInstance* GameInstance)
{
	UGameFrameworkComponentManager* ComponentManager = UGameInstance::GetSubsystem<UGameFrameworkComponentManager>(GameInstance);
	int EntryIndex =0;

	for (int i = 0; i < Abilities.Num(); i++)
	{
		FGameFeatureAbilityEntry AbilityEntry = Abilities[i];
		const UGameFrameworkComponentManager::FExtensionHandlerDelegate ExtensionDelegate = UGameFrameworkComponentManager::FExtensionHandlerDelegate::CreateUObject(this, &UAddAbilities::HandleExtensionDelegate, EntryIndex);
		ExtensionHandler.Add(ComponentManager->AddExtensionHandler(AbilityEntry.ActorClass, ExtensionDelegate));
	}
}

void UAddAbilities::HandleExtensionDelegate(AActor* ActorClass, FName Name, int entryIndex)
{
	UAbilitySystemComponent* AbilitySystemComponent = ActorClass->FindComponentByClass<UAbilitySystemComponent>();
	const TSubclassOf<UGameplayAbility> Ability =  Abilities[entryIndex].AbilityClass.LoadSynchronous();
	const FGameplayAbilitySpec AbilitySpec{Ability};
	AbilitySystemComponent->GiveAbility(AbilitySpec);
}
