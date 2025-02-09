// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Parang_BaseSet.h"
#include "AbilitySystemComponent.h"
#include "Parang_HealthSet.generated.h"

DECLARE_MULTICAST_DELEGATE_FourParams(FDamageTakenEvent,
	AActor*, /*EffectInstigator*/
	AActor*, /*EffectCauser*/
	const FGameplayTagContainer&, /*GameplayTagContainer*/
	float /*Damage*/);

/**
 * 
 */
UCLASS()
class GAS_STUDY_API UParang_HealthSet : public UParang_BaseSet
{
	GENERATED_BODY()
	
public:
	UParang_HealthSet();

	UPROPERTY(BlueprintReadOnly, Category = "Attributes", Meta = (AllowPrivateAccess = true))
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UParang_HealthSet, Health);

	UPROPERTY(BlueprintReadOnly, Category = "Attributes", Meta = (AllowPrivateAccess = true))
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UParang_HealthSet, MaxHealth);

	UPROPERTY(BlueprintReadOnly, Category = "Attributes", Meta = (AllowPrivateAccess = true))
	FGameplayAttributeData Shield;
	ATTRIBUTE_ACCESSORS(UParang_HealthSet, Shield);

	UPROPERTY(BlueprintReadOnly, Category = "Attributes", Meta = (AllowPrivateAccess = true))
	FGameplayAttributeData MaxShield;
	ATTRIBUTE_ACCESSORS(UParang_HealthSet, MaxShield);

	UPROPERTY(BlueprintReadOnly, Category = "Attributes", Meta = (AllowPrivateAccess = true))
	FGameplayAttributeData ShieldRegen;
	ATTRIBUTE_ACCESSORS(UParang_HealthSet, ShieldRegen);

	UPROPERTY(BlueprintReadOnly, Category = "Attributes", Meta = (AllowPrivateAccess = true))
	FGameplayAttributeData InDamage;
	ATTRIBUTE_ACCESSORS(UParang_HealthSet, InDamage);

	mutable FDamageTakenEvent OnDamageTaken;

protected:
	virtual void ClampAttributeOnChange(const FGameplayAttribute& Attribute,
		float& NewValue) const override;
	virtual void PostGameplayEffectExecute(
		const FGameplayEffectModCallbackData& Data) override;
};
