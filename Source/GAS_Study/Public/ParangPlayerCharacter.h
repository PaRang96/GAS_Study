// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ParangBaseCharacter.h"
#include "ParangPlayerCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

/**
 * 
 */
UCLASS()
class GAS_STUDY_API AParangPlayerCharacter : public AParangBaseCharacter
{
	GENERATED_BODY()
	
	/* Camera boom positioning the camera behing the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", 
		meta = (AllowPrivateAccess = true))
	USpringArmComponent* SpringArmComp;

	/* Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera",
		meta = (AllowPrivateAccess = true))
	UCameraComponent* CameraComp;

	/* Mapping Context */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input",
		meta = (AllowPrivateAccess = true))
	UInputMappingContext* DefaultMappingContext;

	/* Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input",
		meta = (AllowPrivateAccess = true))
	UInputAction* JumpAction;

	/* Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input",
		meta = (AllowPrivateAccess = true))
	UInputAction* MoveAction;

	/* Look Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input",
		meta = (AllowPrivateAccess = true))
	UInputAction* LookAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input",
		meta = (AllowPrivateAccess = true))
	UInputAction* FireAbilityAction;

public:
	// Sets default values for this character's properties
	AParangPlayerCharacter();

protected:
	virtual void BeginPlay() override;

	void Look(const FInputActionValue& Value);

	void Move(const FInputActionValue& Value);

	virtual void SendAbilityLocalInput(const FInputActionValue& Value, int32 InputID);

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void FireAbility(const FInputActionValue& Value);
};
