// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ColorCubeBase.generated.h"

UENUM(BlueprintType)
enum class EColors : uint8
{
	Red,
	Green,
	Blue
};


UCLASS()
class UEINTROASSIGN_API AColorCubeBase : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AColorCubeBase();
	// Called every frame


	UFUNCTION(BlueprintCallable)
	void ChangeColor();
	

protected:
	// Called when the game starts or when spawned


	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* CubeComponent;
	
	UPROPERTY(EditDefaultsOnly)
	TMap<EColors, UMaterialInterface*> MaterialsMap;
	
private:
	UPROPERTY(ReplicatedUsing=Rep_CurrentColor) //Rep notify
	EColors CurrentColor;

	UFUNCTION()
	void Rep_CurrentColor();

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	
};
