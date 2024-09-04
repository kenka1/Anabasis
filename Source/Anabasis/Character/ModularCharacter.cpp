// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/ModularCharacter.h"
#include "Animation/BaseAnimInstance.h"
#include "Ability/ModularAbility.h"

#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

AModularCharacter::AModularCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	UE_LOG(LogTemp, Warning, TEXT("AModularCharacter::AModularCharacter()"));
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArmComponent");
	SpringArmComponent->SetupAttachment(GetRootComponent());
	SpringArmComponent->SetRelativeRotation(FRotator(-70.0, 0.0, 0.0));
	SpringArmComponent->TargetArmLength = 1000.0f;
	SpringArmComponent->bEnableCameraLag = true;
	SpringArmComponent->bInheritPitch = false;
	SpringArmComponent->bInheritRoll = false;
	SpringArmComponent->bInheritYaw = false;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	CameraComponent->SetupAttachment(SpringArmComponent);

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

}

void AModularCharacter::BeginPlay()
{
	Super::BeginPlay();
	BaseAnimInstance = Cast<UBaseAnimInstance>(GetMesh()->GetAnimInstance());
}

void AModularCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	ResetCountingDown(DeltaTime);

}

void AModularCharacter::Attack()
{
	if (CanAttack())
	{
		UE_LOG(LogTemp, Warning, TEXT("Attack"));
		CharacterState = ECharacterStates::Attack;
		CountingDown = AbilityData->DefaultAttackCountDown;
		PlayAttackMontage();
	}
}

bool AModularCharacter::CanAttack()
{
	return CountingDown <= 0 && BaseAnimInstance && CharacterState != ECharacterStates::Attack;
}

void AModularCharacter::CountDownEvent(float DeltaTime)
{
}

void AModularCharacter::PlayAttackMontage()
{
	if (AbilityData->DefaultAttackMontages.Num() != 0)
	{
		BaseAnimInstance->Montage_Play(AbilityData->DefaultAttackMontages[DefaultAttackIndex]);
		DefaultAttackIndex = (DefaultAttackIndex + 1) % AbilityData->DefaultAttackMontages.Num();
	}
}

void AModularCharacter::ResetCountingDown(float DeltaTimes)
{
	if (CountingDown > 0)
	{
		CountingDown -= DeltaTimes;
		ResetCharacterState();
	}
}

void AModularCharacter::ResetCharacterState()
{
	if (CharacterState == ECharacterStates::Attack)
		CharacterState = ECharacterStates::Idle;
}

float AModularCharacter::GetSpringArmLength() const
{
	return SpringArmComponent->TargetArmLength;
}

void AModularCharacter::SetSprintArmLength(float length)
{
	SpringArmComponent->TargetArmLength = length;
}