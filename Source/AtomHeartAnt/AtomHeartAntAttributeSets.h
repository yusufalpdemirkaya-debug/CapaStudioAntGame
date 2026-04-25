// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "AtomHeartAntAttributeSets.generated.h"

/**
 * 
 */
UCLASS()
class ATOMHEARTANT_API UAtomHeartAntAttributeSets : public UAttributeSet
{
	GENERATED_BODY()
public:
	
	UAtomHeartAntAttributeSets();
	
	UPROPERTY(BlueprintReadOnly, Category = "Attributes",ReplicatedUsing=OnRep_Health)
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS_BASIC(UAtomHeartAntAttributeSets, Health)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes",ReplicatedUsing=OnRep_MaxHealth)
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS_BASIC(UAtomHeartAntAttributeSets, MaxHealth)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes",ReplicatedUsing=OnRep_Stamina)
	FGameplayAttributeData Stamina;
	ATTRIBUTE_ACCESSORS_BASIC(UAtomHeartAntAttributeSets, Stamina)
	
	UPROPERTY(BlueprintReadOnly, Category = "Attributes",ReplicatedUsing=OnRep_MaxStamina)
	FGameplayAttributeData MaxStamina;
	ATTRIBUTE_ACCESSORS_BASIC(UAtomHeartAntAttributeSets, MaxStamina)

public:
	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldValue)
	{
		GAMEPLAYATTRIBUTE_REPNOTIFY(UAtomHeartAntAttributeSets, Health, OldValue);
	}
	
	UFUNCTION()
	void OnRep_Stamina(const FGameplayAttributeData& OldValue)
	{
		GAMEPLAYATTRIBUTE_REPNOTIFY(UAtomHeartAntAttributeSets, Stamina, OldValue);
	}
	
	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldValue)
	{
		GAMEPLAYATTRIBUTE_REPNOTIFY(UAtomHeartAntAttributeSets, MaxHealth, OldValue);
	}
	
	UFUNCTION()
	void OnRep_MaxStamina(const FGameplayAttributeData& OldValue)
	{
		GAMEPLAYATTRIBUTE_REPNOTIFY(UAtomHeartAntAttributeSets, MaxStamina, OldValue);
	}
	
	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;
};
