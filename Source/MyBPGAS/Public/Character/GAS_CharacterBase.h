// GAS_CharacterBase.h

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"				// GAS
#include "AbilitySystemComponent.h"				// GAS
#include "GAS_CharacterBase.generated.h"

UCLASS()
class MYBPGAS_API AGAS_CharacterBase 
	: public ACharacter
	, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AGAS_CharacterBase();

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Get GAS Component
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

protected:
	virtual void BeginPlay() override;

	virtual void PossessedBy(AController* NewConroller) override;

protected:
	// 캐릭터 하나당 하나씩 붙는 AbilitySystemComponent
	// HP, MP 같은 변수들이 이 컴포넌트에 붙음
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AbilitySystem")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AbilitySystem")
	TObjectPtr<class UGAS_AttributeSetBase> AttributeSet;
};