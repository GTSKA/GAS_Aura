// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AuraAttributeSet.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API UAuraAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
public:
	UAuraAttributeSet();
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UPROPERTY(ReplicatedUsing = OnRep_Health, BlueprintReadOnly, Category="Aura Vital Attributes")
	FGameplayAttributeData Health;

	UPROPERTY(ReplicatedUsing = OnRep_MaxHealth, BlueprintReadOnly, Category="Aura Vital Attributes")
	FGameplayAttributeData MaxHealth;

	UPROPERTY(ReplicatedUsing = OnRep_Mana, BlueprintReadOnly, Category="Aura Vital Attributes");
	FGameplayAttributeData Mana;

	UPROPERTY(ReplicatedUsing = OnRep_MaxMana, BlueprintReadOnly, Category="Aura Vital Attributes");
	FGameplayAttributeData MaxMana;

	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldHealth) const;

	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const;

	UFUNCTION()
	void OnRep_Mana(const FGameplayAttributeData& OldMana) const;

	UFUNCTION()
	void OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const;



};
