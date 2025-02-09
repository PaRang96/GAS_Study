// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "../GAS_Study.h"
#include "Parang_GameplayAbility.generated.h"

/**
 * 
 */
UCLASS()
class GAS_STUDY_API UParang_GameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, Category = "Ability")
	EAbilityInputID AbilityInputID { EAbilityInputID::None };
	
public:
	EAbilityInputID GetAbilityInputID() { return AbilityInputID; };
};
