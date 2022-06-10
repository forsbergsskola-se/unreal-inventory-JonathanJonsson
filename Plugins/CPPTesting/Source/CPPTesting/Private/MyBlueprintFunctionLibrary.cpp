// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBlueprintFunctionLibrary.h"

void UMyBlueprintFunctionLibrary::PrintMyStuff()
{
	if(GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1,10.0f,FColor::Green,"Printing my stuff!");
	}
}
