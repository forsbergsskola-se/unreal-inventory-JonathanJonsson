// Fill out your copyright notice in the Description page of Project Settings.


#include "GP_PathFollowingComponent.h"

#include "AIController.h"
#include "NavigationSystem.h"
#include "AI/NavigationSystemBase.h"


// Sets default values for this component's properties
UGP_PathFollowingComponent::UGP_PathFollowingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGP_PathFollowingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UGP_PathFollowingComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                               FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if(DebugPath)
 		DrawDiamondAtTargetDestination(20,DebugColor,0.1f,3);
}

void UGP_PathFollowingComponent::DrawDiamondAtTargetDestination(float Radius, FLinearColor Color, float Time, float Thickness)
{
	if(!Path)
		return;

	TArray<FNavPathPoint> PathPoints = Path->GetPathPoints();

	for (FNavPathPoint point : PathPoints)
	{
		DrawDebugSphere(GetWorld(), point,Radius,4, Color.ToFColorSRGB(),false, Time, 0, Thickness);
	}
}

bool UGP_PathFollowingComponent::IsLocationReachable(FVector EndDestination)
{
	UNavigationSystemV1* NavSystem = FNavigationSystem::GetCurrent<UNavigationSystemV1>(GetWorld());

	APawn* EnemyPawn = Cast<AAIController>(GetOwner())->GetPawn();
	
	
	FPathFindingQuery Query{GetOwner(), *MyNavData, EnemyPawn->GetActorLocation(), EndDestination};
	
	return NavSystem->TestPathSync(Query);
	
}

TArray<AActor*> UGP_PathFollowingComponent::OrderByDistance(AActor* OwnerActor, TArray<AActor*> InputArray)
{
	InputArray.Sort([OwnerActor](AActor& A,AActor& B)
	{
		float DistanceA = A.GetDistanceTo(OwnerActor);
		float DistanceB = B.GetDistanceTo(OwnerActor);
		return DistanceA > DistanceB;
	});
	return InputArray;
}	
 

