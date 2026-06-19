// GAS_AttributeSetBase.cpp

#include "AttributeSet/GAS_AttributeSetBase.h"

UGAS_AttributeSetBase::UGAS_AttributeSetBase()
{
	InitHP(100.f);
	InitMaxHP(100.f);
	InitStamina(100.f);
	InitMaxStamina(100.f);

	//// HP 가져오기
	//GetHP();
	//
	//// HP 변경
	//SetHP(150.f);
	//
	//// HP 포인터
	//GetHPAttribute();
}

bool UGAS_AttributeSetBase::PreGameplayEffectExecute(FGameplayEffectModCallbackData& Data)
{
	Super::PreGameplayEffectExecute(Data);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("PreGameplayEffectExecute"));
	return true;	// 적용을 하려면 반드시 true로
}

void UGAS_AttributeSetBase::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("PreAttributeChange"));
}

void UGAS_AttributeSetBase::PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue)
{
	Super::PostAttributeChange(Attribute, OldValue, NewValue);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("PostAttributeChange"));
}

void UGAS_AttributeSetBase::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("PostGameplayEffectExecute"));
}
