// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ModularWeapon.generated.h"

UINTERFACE(MinimalAPI)
class UModularWeapon : public UInterface
{
	GENERATED_BODY()
};

class ANABASIS_API IModularWeapon
{
	GENERATED_BODY()
public:

	virtual void Attack() = 0;
	virtual bool CanAttack() = 0;
	virtual void CountDownEvent(float DeltaTime) = 0;

};