// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MyBlueprintFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class CPPTESTING_API UMyBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int NumberOne;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int NumberTwo;
	
	
	
	UFUNCTION(BlueprintCallable, Category = "MyBlueprintLibrary|PrintMyStuff")
	static void PrintMyStuff();

};
