// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryStructs.h"
#include "InventoryBase.generated.h"

#define PRINT(Time, String) GEngine->AddOnScreenDebugMessage(-1,Time,FColor::Orange, String);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnInventoryChangedSignature, FItemStruct, Item);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable)
class INVENTORYSYSTEM_API UInventoryBase : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UInventoryBase();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="GP_JJ")
	TArray<FItemStruct>& GetItems();


	//For adding NEW item to inventory (as in not in a stack)
	UFUNCTION(BlueprintCallable, Category="GP_JJ")
	bool AddItemNew(const FItemStruct& NewItem);

	//Adding an item (might be new OR to a stack)
	UFUNCTION(BlueprintCallable, Category="GP_JJ")
	bool AddItemzz(UPARAM(ref) FItemStruct& Item);

	UFUNCTION(BlueprintCallable, Category="GP_JJ")
	bool RemoveItem(const FItemStruct& Item);

	UFUNCTION(BlueprintCallable, Category="GP_JJ")
	bool TransferItem(UInventoryBase* TargetInventory, const FItemStruct& Item);
	
	UFUNCTION(BlueprintCallable, Category="GP_JJ")
	FItemStruct CreateItem(const FItemStruct& Item);

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
							   FActorComponentTickFunction* ThisTickFunction) override;
	UPROPERTY(EditDefaultsOnly)
	bool bDebug;	

	UPROPERTY(BlueprintAssignable, Category="GP_JJ")
	FOnInventoryChangedSignature OnInventoryChanged;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	TArray<FItemStruct> Items;

	void Debug();
};
