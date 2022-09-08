// Fill out your copyright notice in the Description page of Project Settings.


#include "TestActor.h"
 

void ATestActor::DrawDiamondAtTargetDestination(float Radius, FLinearColor Color, float LifeTime, float Thickness)
{
	FVector PathDestination = GetPathFollowingComponent() -> GetCurrentTargetLocation();
	FNavPathSharedPtr Path = GetPathFollowingComponent()->GetPath();
	if(!Path)
		return;

	TArray<FNavPathPoint> PathPoints = Path->GetPathPoints();

	for (FNavPathPoint point : PathPoints)
	{
		DrawDebugSphere(GetWorld(), point,Radius,4, Color.ToFColorSRGB(),false, LifeTime, 0, Thickness);
	}


}
 

// Sets default values
ATestActor::ATestActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATestActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

