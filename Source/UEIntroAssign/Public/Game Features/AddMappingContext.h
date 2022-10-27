// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatureAction.h"
#include "InputMappingContext.h"
#include "Components/GameFrameworkComponentManager.h"
#include "AddMappingContext.generated.h"

USTRUCT()
struct FGameFeatureMappingEntry
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	TSoftClassPtr<APlayerController> ControllerClass;

	UInputMappingContext* MappingContext;
	
};


UCLASS()
class UEINTROASSIGN_API UAddMappingContext : public UGameFeatureAction
{
	GENERATED_BODY()

	virtual void OnGameFeatureActivating() override;
	FDelegateHandle GameInstanceHandle;
	TArray<FGameFeatureMappingEntry> MappingEntries;
	TArray<TSharedPtr<FComponentRequestHandle>> ExtensionHandlers;
	void HandleGameInstanceStart(UGameInstance* GameInstance);
	void HandleExtensionDelegate(AActor* ActorClass, FName Name, int EntryIndex);
};
