// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "UObject/Object.h"
#include "ActorWithMaterialManipulator.generated.h"

/**
 * 
 */
UCLASS()
class UEINTROASSIGN_API AActorWithMaterialManipulator : public AActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintPure, Category="GP_JJ")
	FLinearColor GetRandomColor();
};
