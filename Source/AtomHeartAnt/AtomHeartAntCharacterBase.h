// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystemComponent.h"
#include "GameFramework/Character.h"

#include "AtomHeartAntCharacterBase.generated.h"

class USpringArmComponent;
class UCameraComponent;

UCLASS(Abstract)
class ATOMHEARTANT_API AAtomHeartAntCharacterBase : public ACharacter , public IAbilitySystemInterface
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Components",meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;
	
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Components",meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FollowCamera;
	
public:
	// Sets default values for this character's properties
	AAtomHeartAntCharacterBase();

	UPROPERTY(BlueprintReadWrite, EditAnywhere,Category="GAS")
	UAbilitySystemComponent* AbilitySystemComponent;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere,Category="GAS")
	class UAtomHeartAntAttributeSets* AttributeSet;

protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere,Category="GAS")
	EGameplayEffectReplicationMode ReplicationMode =EGameplayEffectReplicationMode::Mixed;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	virtual void PossessedBy(AController*NewController) override;
	
	virtual void OnRep_PlayerState() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

protected:
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	FORCEINLINE class UCameraComponent* GetCamera() const { return FollowCamera; }
};
