#pragma once
#include "ItemPDABase.h"


#include "InventoryStructs.generated.h"


USTRUCT(BlueprintType)
struct FItemStruct
 {
  GENERATED_BODY();

 // FItemStruct(UItemPDABase* ItemPdaBase, float Durability) : ItemPDA(ItemPdaBase), Durability(Durability)
 // {
 //  ItemPDA = ItemPdaBase;
 // }
 
  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  UItemPDABase* ItemPDA;

 UPROPERTY(BlueprintReadWrite)
 float Durability;

 UPROPERTY(BlueprintReadWrite)
 int Amount;

 };
