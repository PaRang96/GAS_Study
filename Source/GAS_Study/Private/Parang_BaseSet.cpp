// Fill out your copyright notice in the Description page of Project Settings.


#include "Parang_BaseSet.h"

void UParang_BaseSet::ClampAttributeOnChange(
	const FGameplayAttribute& Attribute, float& NewValue) const
{

}

void UParang_BaseSet::PreAttributeBaseChange(
	const FGameplayAttribute& Attribute, float& NewValue) const
{
	Super::PreAttributeBaseChange(Attribute, NewValue);

	ClampAttributeOnChange(Attribute, NewValue);
}

void UParang_BaseSet::PreAttributeChange(
	const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);

	ClampAttributeOnChange(Attribute, NewValue);
}

