// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Navigation/PathFollowingComponent.h"
#include "GP_PathFollowingComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class UEINTROASSIGN_API UGP_PathFollowingComponent : public UPathFollowingComponent
{
	GENERATED_BODY()

public:
	/**
	 *Toggles path when doing navigation
	 */
	UPROPERTY(EditDefaultsOnly, Category="Debug")
	bool DebugPath;

	/*
	 *Color of debug diamonds
	 */
	UPROPERTY(EditDefaultsOnly, Category="Debug")
	FLinearColor DebugColor;


	
	// Sets default values for this component's properties
	UGP_PathFollowingComponent();
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
							   FActorComponentTickFunction* ThisTickFunction) override;

	/**
	 *@param Radius Radius of diamond
	 *@param Color Color of diamond
	 *@param Time Time for spawn diamond
	 *@param Thickness Thickness of diamond lines
	 */
	UFUNCTION(BlueprintCallable, Category="GP21")
	void DrawDiamondAtTargetDestination(float Radius, FLinearColor Color, float Time, float Thickness);

	UFUNCTION(BlueprintCallable,BlueprintPure, Category="GP21")
	bool IsLocationReachable(FVector EndDestination);

	// UFUNCTION(BlueprintCallable, Category="GP21")
	// static TArray<AActor*> OrderByDistance(AActor* OwnerActor, TArray<AActor*> InputArray);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
 
};
