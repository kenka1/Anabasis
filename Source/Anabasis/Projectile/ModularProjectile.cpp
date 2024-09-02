// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectile/ModularProjectile.h"

AModularProjectile::AModularProjectile()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AModularProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

void AModularProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

