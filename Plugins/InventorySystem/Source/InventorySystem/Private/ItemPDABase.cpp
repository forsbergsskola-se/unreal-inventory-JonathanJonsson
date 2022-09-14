// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemPDABase.h"


bool UItemPDABase::Use(const APawn* Pawn, bool Success)
{
	GEngine->AddOnScreenDebugMessage(-1, 2,FColor::Orange,"Used"+ItemName.ToString());
	return true;
}
