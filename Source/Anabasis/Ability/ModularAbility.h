// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ModularAbility.generated.h"

class UAnimMontage;

UCLASS()
class ANABASIS_API UModularAbility : public UDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, Category = "AnabasisWeaponData")
	float CountDown = 0.1f;

	UPROPERTY(EditAnywhere, Category = "ModularAbility")
	UAnimMontage* DefaultAttackMontage;
};
