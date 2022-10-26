// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatureAction.h"
#include "GameFeaturesSubsystem.h"
#include "Abilities/GameplayAbility.h"
#include "Components/GameFrameworkComponentManager.h"
#include "AddAbilities.generated.h"


USTRUCT()
struct FGameFeatureAbilityEntry
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	TSoftClassPtr<AActor> ActorClass;

	UPROPERTY(EditAnywhere)
	TSoftClassPtr<UGameplayAbility> AbilityClass;
};
/**
 * 
 */
UCLASS()
class UEINTROASSIGN_API UAddAbilities : public UGameFeatureAction
{
	GENERATED_BODY()

protected:
	TArray<TSharedPtr<FComponentRequestHandle>> ExtensionHandler;
	UPROPERTY(EditAnywhere)
	TArray<FGameFeatureAbilityEntry> Abilities;
	FDelegateHandle GameInstanceHandle;
	
	virtual void OnGameFeatureActivating(FGameFeatureActivatingContext& Context) override;
	virtual void OnGameFeatureDeactivating(FGameFeatureDeactivatingContext& Context) override;
	
	void HandleGameInstanceStart(UGameInstance* GameInstance);

	void HandleExtensionDelegate(AActor* ActorClass, FName Name, int EntryIndex);
};
