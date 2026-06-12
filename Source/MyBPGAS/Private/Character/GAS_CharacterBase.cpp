// GAS_CharacterBase.cpp

#include "Character/GAS_CharacterBase.h"
#include "Components/CapsuleComponent.h" 
#include "GameFramework/CharacterMovementComponent.h"


AGAS_CharacterBase::AGAS_CharacterBase()
{
	PrimaryActorTick.bCanEverTick = true;

	GetCapsuleComponent()->InitCapsuleSize(35.f, 90.f);
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 500.f, 0.f);
	GetCharacterMovement()->JumpZVelocity = 500.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
	GetCharacterMovement()->BrakingDecelerationFalling = 1500.f;

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