// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/GPAbilitySystemBase.h"


// Sets default values for this component's properties
UGPAbilitySystemBase::UGPAbilitySystemBase()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGPAbilitySystemBase::BeginPlay()
{
	Super::BeginPlay();
	
	GrantAbilities();

	if(!GrantAttributes())
	{
		GEngine->AddOnScreenDebugMessage(
			-1, 10, FColor::Red,
			FString::Printf(TEXT("%s has no attributes"), *GetOwner()->GetName()));
	}
}
 

bool UGPAbilitySystemBase::GrantAbilities()
{
	if(GrantedAbilities.IsEmpty())
	{
		GEngine->AddOnScreenDebugMessage(-1, 10,FColor::Red,
		FString::Printf(TEXT("%s has no abilities!"), *GetOwner()->GetName()));
		UE_LOG(LogTemp,Warning,TEXT("WARNING! Missing abilities!"));
		
		return false;

	}
	
	for (const TSubclassOf<UGameplayAbility>& Ability : GrantedAbilities)
	{
		if(Ability == nullptr)
		{
			GEngine->AddOnScreenDebugMessage(-1, 10,FColor::Red,
		FString::Printf(TEXT("%s has empty ability slot!"), *GetOwner()->GetName()));
		}

		checkf(Ability, TEXT("Missing ability in slot %s!"), *GetOwner()->GetName());

		if(const FGameplayAbilitySpec* FoundSpec = FindAbilitySpecFromClass(Ability))
		{
				//If we already have ability, continue!
        		if(FoundSpec->Ability->GetClass() == Ability)
        			continue;	
		}
		
		FGameplayAbilitySpec AbilitySpec(Ability);
		GiveAbility(AbilitySpec);
	}
	
	return true;
}

bool UGPAbilitySystemBase::GrantAttributes()
{

	if(GrantedAttribute.IsEmpty())
		return false;

	TArray<UAttributeSet*> AttributeSets;
	
	for (TSubclassOf<UAttributeSet> T : GrantedAttribute)
	{
		T.GetDefaultObject()->InitFromMetaDataTable(DTAttribute);
		AttributeSets.AddUnique(T.GetDefaultObject());
		AddAttributeSetSubobject(T.GetDefaultObject());

	}
	return true;
}

