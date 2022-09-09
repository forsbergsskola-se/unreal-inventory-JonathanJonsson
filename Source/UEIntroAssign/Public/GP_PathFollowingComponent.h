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

	UFUNCTION(BlueprintCallable, Category="GP21")
	void DrawDiamondAtTargetDestination(float Radius, FLinearColor Color, float LifeTime, float Thickness);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
 
};
