// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryStructs.h"
#include "InventoryBase.generated.h"



UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable)
class INVENTORYSYSTEM_API UInventoryBase : public UActorComponent
{
	GENERATED_BODY()

FItemStruct ItemBase;

public:
	// Sets default values for this component's properties
	UInventoryBase();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	TArray<FItemStruct>& GetItems();


	UFUNCTION(BlueprintCallable)
	bool AddItemNew(const FItemStruct& NewItem);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;

	
private:
	TArray<FItemStruct> Items;
	
};
