// GAS_CharacterBase.cpp

#include "Character/GAS_CharacterBase.h"
#include "Components/CapsuleComponent.h" 
#include "GameFramework/CharacterMovementComponent.h"

#include "AttributeSet/GAS_AttributeSetBase.h"


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

	AttributeSet = CreateDefaultSubobject<UGAS_AttributeSetBase>(TEXT("GASAttributeSetBase"));
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

void AGAS_CharacterBase::PossessedBy(AController* NewConroller)
{
	Super::PossessedBy(NewConroller);

	// 누가 소유자인지, 누가 사용중인 캐릭터인지 등
	AbilitySystemComponent->InitAbilityActorInfo(this, this);
}

// 기존에 사용하던 ApplyDamage, GameplayEffect를 사용하지 않고 SetHP로 직접 값 변경 시도 (권장x)
void AGAS_CharacterBase::MyApplyDamage(float DamageAmount)
{
	float NewHP = AttributeSet->GetHP() - DamageAmount;
	AttributeSet->SetHP(NewHP); // 직접 값을 변경하는 권장하지 않는 코드
}
