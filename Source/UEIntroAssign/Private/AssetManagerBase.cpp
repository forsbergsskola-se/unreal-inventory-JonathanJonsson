// Fill out your copyright notice in the Description page of Project Settings.

#include "AssetManagerBase.h"
#include "AbilitySystemGlobals.h"
 

void UAssetManagerBase::StartInitialLoading()
{
	Super::StartInitialLoading();

	//INIT GOES HERE
	UAbilitySystemGlobals::Get().InitGlobalData();
}
