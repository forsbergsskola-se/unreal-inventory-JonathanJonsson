// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryBase.h"

#include <string>

#include "Net/UnrealNetwork.h"


// Sets default values for this component's properties
UInventoryBase::UInventoryBase()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	SetIsReplicatedByDefault(true);

	// ...
}

TArray<FItemStruct>& UInventoryBase::GetItems()
{
	return Items;
}
 

bool UInventoryBase::AddItemNew(const FItemStruct& NewItem)
{
	if(NewItem.IsValid())
	{
		Items.Add(NewItem);
		OnInventoryChanged.Broadcast(NewItem);
		return true;
	}

	return false;
}

bool UInventoryBase::AddItem(UPARAM(ref) FItemStruct& Item)
{
	for(const FItemStruct ItemIndex : GetItems())
	{

		if(ItemIndex.ItemPDA == Item.ItemPDA && Item.ItemPDA->Stackable)
		{
			Item.Amount += 1;
			OnInventoryChanged.Broadcast(Item);
			return true;
		}
	}
	
	AddItemNew(Item);
	return true;
}

bool UInventoryBase::RemoveItem(const FItemStruct& Item)
{

	if(Items.Remove(Item) > 0)
	{
		OnInventoryChanged.Broadcast(Item);
		return true;
	}

	return false;
}

bool UInventoryBase::TransferItem(UInventoryBase* TargetInventory, const FItemStruct& Item)
{
	if(TargetInventory->AddItemNew(Item))
	{
		return RemoveItem(Item);
	}
	return false;
}


FItemStruct UInventoryBase::CreateItem(const FItemStruct& Item)
{
	if(Item.ItemPDA)
		return FItemStruct{Item.ItemPDA};

	return FItemStruct(nullptr);
}


// Called when the game starts
void UInventoryBase::BeginPlay()
{
	Super::BeginPlay();
	
	// ...
	
}


// Called every frame
void UInventoryBase::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	if(bDebug)
		Debug();

}

void UInventoryBase::Debug()
{
	for(const FItemStruct ItemIndex : GetItems())
	{
		FString string = FString::Printf(TEXT("Item name: %s"), *ItemIndex.ItemPDA->ItemName.ToString());
		PRINT(0,string);
	}
}

void UInventoryBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UInventoryBase, Items)
}

