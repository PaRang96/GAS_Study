// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "Parang_BaseSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName)
#define GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName)
#define GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName)
#define GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName)
#define GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/**
 * 
 */
UCLASS()
class GAS_STUDY_API UParang_BaseSet : public UAttributeSet
{
	GENERATED_BODY()
	
protected:
	virtual void PreAttributeBaseChange(const FGameplayAttribute& Attribute,
		float& NewValue) const override;
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute,
		float& NewValue) override;
	virtual void ClampAttributeOnChange(const FGameplayAttribute& Attribute,
		float& NewValue) const;
};
