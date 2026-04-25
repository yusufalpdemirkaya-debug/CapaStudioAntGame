// Fill out your copyright notice in the Description page of Project Settings.


#include "AtomHeartAntAttributeSets.h"

#include "Net/UnrealNetwork.h"

UAtomHeartAntAttributeSets::UAtomHeartAntAttributeSets()
{
	Health = 100.f;
	MaxHealth = 100.f;
	Stamina = 100.f;
	MaxStamina = 100.f;
}

void UAtomHeartAntAttributeSets::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UAtomHeartAntAttributeSets, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAtomHeartAntAttributeSets, MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAtomHeartAntAttributeSets, Stamina, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAtomHeartAntAttributeSets, MaxStamina, COND_None, REPNOTIFY_Always);
}
