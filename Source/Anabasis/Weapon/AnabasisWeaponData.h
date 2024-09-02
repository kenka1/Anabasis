// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "AnabasisWeaponData.generated.h"

class UAnimMontage;

UCLASS()
class ANABASIS_API UAnabasisWeaponData : public UDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, Category = "AnabasisWeaponData", meta = (AllowPrivateAccess))
	FName SocketName = "";

	UPROPERTY(EditAnywhere, Category = "AnabasisWeaponData", meta = (AllowPrivateAccess))
	FName MuzzleStart = "";

	UPROPERTY(EditAnywhere, Category = "AnabasisWeaponData", meta = (AllowPrivateAccess))
	FName MuzzleEnd = "";

	UPROPERTY(EditAnywhere, Category = "AnabasisWeaponData", meta = (AllowPrivateAccess))
	int32 MaxAmmo = 100;

	UPROPERTY(EditAnywhere, Category = "AnabasisWeaponData", meta = (AllowPrivateAccess))
	int32 Damage = 5;

	UPROPERTY(EditAnywhere, Category = "AnabasisWeaponData", meta = (AllowPrivateAccess))
	float TraceDist = 1000.0f;

	UPROPERTY(EditAnywhere, Category = "AnabasisWeaponData", meta = (AllowPrivateAccess))
	float CountDown = 0.1f;

	UPROPERTY(EditAnywhere, Category = "AnabasisWeaponData", meta = (AllowPrivateAccess))
	UAnimMontage* AnimMontage;


protected:

private:
	
};
