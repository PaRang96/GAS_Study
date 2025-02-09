// Fill out your copyright notice in the Description page of Project Settings.


#include "ParangBaseCharacter.h"
#include "AbilitySystemComponent.h"
#include "Parang_GameplayAbility.h"
#include "Parang_HealthSet.h"

// Sets default values
AParangBaseCharacter::AParangBaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>("AbilitySystemComp");
	HealthSet = CreateDefaultSubobject<UParang_HealthSet>("HealthSet");
}

// Called when the game starts or when spawned
void AParangBaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	HealthSet->OnDamageTaken.AddUObject(this, &AParangBaseCharacter::OnDamageTakenChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		HealthSet->GetHealthAttribute()).AddUObject(
			this, &AParangBaseCharacter::OnHealthAttributeChanged);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		HealthSet->GetShieldAttribute()).AddUObject(
			this, &AParangBaseCharacter::OnShieldAttributeChanged);
}

// Called every frame
void AParangBaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AParangBaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

UAbilitySystemComponent* AParangBaseCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void AParangBaseCharacter::InitializeAbilities()
{
	// Give Attributes, Server Only
	if (!HasAuthority() || !AbilitySystemComponent)
	{
		return;
	}

	for (TSubclassOf<UParang_GameplayAbility>& Ability : DefaultAbilities)
	{
		FGameplayAbilitySpecHandle SpecHandle = AbilitySystemComponent->GiveAbility(
			FGameplayAbilitySpec(Ability, 1, static_cast<int32>(
				Ability.GetDefaultObject()->GetAbilityInputID()), this));
	}
}

void AParangBaseCharacter::InitializeEffects()
{
	if (!AbilitySystemComponent)
	{
		return;
	}

	FGameplayEffectContextHandle EffectContext = AbilitySystemComponent->MakeEffectContext();
	EffectContext.AddSourceObject(this);

	for (TSubclassOf<UGameplayEffect>& Effect : DefaultEffects)
	{
		FGameplayEffectSpecHandle SpecHandle = AbilitySystemComponent->MakeOutgoingSpec(
			Effect, 1, EffectContext);

		if (SpecHandle.IsValid())
		{
			FActiveGameplayEffectHandle GEHandle = 
				AbilitySystemComponent->ApplyGameplayEffectSpecToSelf(
					*SpecHandle.Data.Get());
		}
	}
}

void AParangBaseCharacter::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	if (!AbilitySystemComponent)
	{
		return;
	}

	AbilitySystemComponent->InitAbilityActorInfo(this, this);

	InitializeEffects();
	InitializeAbilities();
}

void AParangBaseCharacter::OnDamageTakenChanged(AActor* DamageInstigator, AActor* DamageCauser, 
	const FGameplayTagContainer& GameplayTagContainer, float Damage)
{
	OnDamageTaken(DamageInstigator, DamageCauser, GameplayTagContainer, Damage);
}

void AParangBaseCharacter::OnHealthAttributeChanged(const FOnAttributeChangeData& Data)
{
	OnHealthChanged(Data.OldValue, Data.NewValue);
}

void AParangBaseCharacter::OnShieldAttributeChanged(const FOnAttributeChangeData& Data)
{
	OnShieldChanged(Data.OldValue, Data.NewValue);
}

