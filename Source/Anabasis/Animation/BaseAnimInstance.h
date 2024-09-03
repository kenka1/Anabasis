// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "CommonTypes/CommonTypes.h"
#include "BaseAnimInstance.generated.h"

class AModularCharacter;
class UCharacterMovementComponent;

UCLASS()
class ANABASIS_API UBaseAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

protected:

	UPROPERTY(BlueprintReadOnly, Category = "BaseAnimInstance")
	AModularCharacter* Owner;

	UPROPERTY(BlueprintReadOnly, Category = "BaseAnimInstance")
	UCharacterMovementComponent* MovementComponent;

	UPROPERTY(BlueprintReadWrite, Category = "BaseAnimInstance")
	ECharacterStates CharacterState;

private:

};