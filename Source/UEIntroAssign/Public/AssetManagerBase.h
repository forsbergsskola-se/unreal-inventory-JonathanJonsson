﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "AssetManagerBase.generated.h"

/**
 * 
 */
UCLASS()
class UEINTROASSIGN_API UAssetManagerBase : public UAssetManager
{
	GENERATED_BODY()
public:

	virtual void StartInitialLoading() override;
};
