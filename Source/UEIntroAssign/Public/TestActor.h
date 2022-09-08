// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "GameFramework/Actor.h"
#include "TestActor.generated.h"

UCLASS()
class UEINTROASSIGN_API ATestActor : public AActor
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable, Category="GP_21_JonathanJonsson")
	void DrawDiamondAtTargetLocation(FVector Location, float Radius, int Segments,FColor Color );
	// Sets default values for this actor's properties
	ATestActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
