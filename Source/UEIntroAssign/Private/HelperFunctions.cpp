// Fill out your copyright notice in the Description page of Project Settings.


#include "HelperFunctions.h"

TArray<AActor*> UHelperFunctions::OrderByDistance(AActor* OwnerActor, TArray<AActor*> InputArray)
{
	InputArray.Sort([OwnerActor](AActor& A,AActor& B)
	{
		float DistanceA = A.GetDistanceTo(OwnerActor);
		float DistanceB = B.GetDistanceTo(OwnerActor);
		return DistanceA < DistanceB;
	});
	return InputArray;
}
