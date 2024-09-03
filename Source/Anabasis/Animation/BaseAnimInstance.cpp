// Fill out your copyright notice in the Description page of Project Settings.


#include "Animation/BaseAnimInstance.h"
#include "Character/ModularCharacter.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

void UBaseAnimInstance::NativeInitializeAnimation()
{
	Owner = Cast<AModularCharacter>(GetOwningActor());

	Owner = Cast<AModularCharacter>(TryGetPawnOwner());
	if (Owner)
		MovementComponent = Cast<UCharacterMovementComponent>(Owner->GetMovementComponent());
}

void UBaseAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	if (Owner)
		CharacterState = Owner->GetCharacterState();
}