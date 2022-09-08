// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "GameFramework/Actor.h"
#include "TestActor.generated.h"

UCLASS()
class UEINTROASSIGN_API ATestActor : public AAIController
{
	GENERATED_BODY()
	
public:
	
	UFUNCTION(BlueprintCallable, Category="GP_21_JonathanJonsson")
	void DrawDiamondAtTargetDestination(float Radius, FLinearColor Color, float LifeTime, float Thickness);
	// Sets default values for this actor's properties
	ATestActor();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
 
};
