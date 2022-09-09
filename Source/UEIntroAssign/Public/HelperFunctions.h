// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "HelperFunctions.generated.h"

/**
 * 
 */
UCLASS()
class UEINTROASSIGN_API UHelperFunctions : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="GP21_HelperFunctions")
static TArray<AActor*> OrderByDistance(AActor* OwnerActor, TArray<AActor*> InputArray);
};
