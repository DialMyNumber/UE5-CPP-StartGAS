// GAS_CharacterBase.cpp

#include "Character/GAS_CharacterBase.h"


AGAS_CharacterBase::AGAS_CharacterBase()
{
	PrimaryActorTick.bCanEverTick = true;

	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
}

void AGAS_CharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void AGAS_CharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGAS_CharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

// 현재 이 CharacterBase가 가지고 있는 AbilitySystemComponent를 반환하는 Getter
UAbilitySystemComponent* AGAS_CharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}