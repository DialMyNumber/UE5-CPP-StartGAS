// GA_Flash

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "GA_Flash.generated.h"

UCLASS()
class MYBPGAS_API UGA_Flash : public UGameplayAbility
{
	GENERATED_BODY()
	
public:
	// Ability가 실행될 때 실행되는 코드
	virtual void ActivateAbility(
		const FGameplayAbilitySpecHandle Handle, 
		const FGameplayAbilityActorInfo* ActorInfo, 
		const FGameplayAbilityActivationInfo ActivationInfo, 
		const FGameplayEventData* TriggerEventData
	) override;

	// 끝났을 때 호출되는 함수
	UFUNCTION()
	void OnMoveFinished();
	
};