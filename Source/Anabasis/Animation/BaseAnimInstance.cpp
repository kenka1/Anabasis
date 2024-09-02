// Fill out your copyright notice in the Description page of Project Settings.


#include "Animation/BaseAnimInstance.h"
#include "Character/ModularCharacter.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

void UBaseAnimInstance::NativeInitializeAnimation()
{
	Owner = Cast<AModularCharacter>(GetOwningActor());
}

void UBaseAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{

}

void UBaseAnimInstance::CalculateDirValue()
{
	FVector RightAxis = UKismetMathLibrary::Cross_VectorVector(FVector(0.0f, 0.0f, 1.0f), FVector(MousePos.X, MousePos.Y, 0.0));
	RightAxis.Normalize();

	DirValue.X = UKismetMathLibrary::DotProduct2D(FVector2D(MousePos.X, MousePos.Y), InputValue);
	DirValue.Y = UKismetMathLibrary::DotProduct2D(FVector2D(RightAxis.X, RightAxis.Y), InputValue);
}