// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemPDABase.generated.h"

/**
 * 
 */
UCLASS()
class INVENTORYSYSTEM_API UItemPDABase : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly,EditDefaultsOnly, Category="Basic")
	FText ItemName; 

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category="Basic")
	float Damage;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category="Basic")
	FName SocketSlot;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category="Basic")
	UStaticMesh* Mesh;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category="Basic")
	UTexture2D* Thumbnail;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category="Basic")
	bool Stackable;

	UFUNCTION(BlueprintNativeEvent,BlueprintCallable, Category="Basic")
	bool Use(const APawn* Pawn);

	
	
};
