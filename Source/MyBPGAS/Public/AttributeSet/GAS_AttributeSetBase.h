// GAS_AttributeSetBase.h

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"

#include "AbilitySystemComponent.h"

#include "GAS_AttributeSetBase.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)


UCLASS()
class MYBPGAS_API UGAS_AttributeSetBase : public UAttributeSet
{
	GENERATED_BODY()

public:
	UGAS_AttributeSetBase();

	//-------------------------------------
	// 외부 클래스에서 사용할 수 있어야 하기 때문에 public 범위 지정자에서 매크로 사용

	ATTRIBUTE_ACCESSORS(UGAS_AttributeSetBase, HP);
	ATTRIBUTE_ACCESSORS(UGAS_AttributeSetBase, MaxHP);
	ATTRIBUTE_ACCESSORS(UGAS_AttributeSetBase, Stamina);
	ATTRIBUTE_ACCESSORS(UGAS_AttributeSetBase, MaxStamina);


	//------------------------------- 아래 정의 순서대로 실행됨
	// GameplayEffect의 명령을 받은 직후 실행되는 함수
	// bool 값이 false이면 무효처리를 하는 등의 필터링에 유용
	virtual bool PreGameplayEffectExecute(struct FGameplayEffectModCallbackData& Data) override;

	// 값이 바뀌기 직전 호출
	// GetHPAttribute() 등의 함수를 Attribute에 인자로 넘겨주고, NewValue 값과 비교 가능
	// 힐을 받아서 HP가 MaxHP를 넘지 않도록, 데미지를 받아서 HP가 0 아래로 떨어지지 않도록 Clamp 기능 등
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)override;

	// 값이 바뀐 직후 호출
	// 바뀌기 전 OldValue와 NewValue를 이용해서
	// NewValue와 OldValue의 차이만큼 UI에 데미지 카운트를 반영하거나
	// NewValue가 특정 값보다 작아졌으니 캐릭터 외형를 상처 입은 외형으로 바꾸는 기능 등
	virtual void PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue) override;

	// GameplayEffect의 명령이 완전히 종료된 직후 실행되는 함수
	// !! 위 Pre/PostAttributeChange 함수에서는 값이 확정되지 않음 !! -> 이 함수에서 확정해야함
	// Data로 변수가 들어오는데, 경험치 로직, 특정 Character가 죽었는지 확인하는 등의 로직에 유용
	virtual void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data) override;

	
private:
	UPROPERTY()
	FGameplayAttributeData HP;

	UPROPERTY()
	FGameplayAttributeData MaxHP;

	UPROPERTY()
	FGameplayAttributeData Stamina;

	UPROPERTY()
	FGameplayAttributeData MaxStamina;
};
