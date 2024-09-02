// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ModularProjectile.generated.h"


UCLASS()
class ANABASIS_API AModularProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	AModularProjectile();
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

private:


};
