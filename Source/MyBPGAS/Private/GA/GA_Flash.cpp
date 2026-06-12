// GA_Flash.cpp

#include "GA/GA_Flash.h"
#include "Abilities/Tasks/AbilityTask_MoveToLocation.h"

void UGA_Flash::ActivateAbility(
	const FGameplayAbilitySpecHandle Handle, 
	const FGameplayAbilityActorInfo* ActorInfo, 
	const FGameplayAbilityActivationInfo ActivationInfo, 
	const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	AActor* AvatarActor = GetAvatarActorFromActorInfo();
	FVector TargetLocation = (AvatarActor->GetActorForwardVector() * 500.f) 
		+ AvatarActor->GetActorLocation();


	UAbilityTask_MoveToLocation* MoveToLocation = UAbilityTask_MoveToLocation::MoveToLocation(
		this,
		NAME_None,
		TargetLocation,
		0.01,	// Duration 같은 변수도 상수가 아닌 변수로 만드는게 좋음
		nullptr,
		nullptr
	);

	if (MoveToLocation)	// MoveToLocation이 실행이 되면
	{
		// OnTargetLocationReached 델리게이트가 호출될 때 UGA_Flash::OnMoveFinished 가 실행됨
		MoveToLocation->OnTargetLocationReached.AddDynamic(this, &UGA_Flash::OnMoveFinished);
		
		MoveToLocation->ReadyForActivation();	// 반드시 필요한 코드, 최종 실행, 모든 Task에서 해당 코드가 필요
	}
}

void UGA_Flash::OnMoveFinished()
{
	EndAbility(CurrentSpecHandle, CurrentActorInfo, CurrentActivationInfo, true, false);
}