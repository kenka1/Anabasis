// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "CommonTypes/CommonTypes.h"
#include "BaseAnimInstance.generated.h"

class AModularCharacter;

UCLASS()
class ANABASIS_API UBaseAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

	FORCEINLINE void SetInputValue(const FVector2D& TargetInputValue) { InputValue = TargetInputValue; }
	FORCEINLINE void SetMousePos(const FVector& TargetMousePos) { MousePos = TargetMousePos; }

protected:

	UPROPERTY(BlueprintReadOnly, Category = "BaseAnimInstance", meta = (AllowPrivateAccess))
	AModularCharacter* Owner;

	UPROPERTY(BlueprintReadOnly, Category = "BaseAnimInstance", meta = (AllowPrivateAccess))

	FVector2D DirValue;

	UPROPERTY(BlueprintReadOnly, Category = "BaseAnimInstance", meta = (AllowPrivateAccess))
	ECharacterStates CharacterState;

private:

	void CalculateDirValue();

	FVector2D InputValue;
	FVector MousePos;
};