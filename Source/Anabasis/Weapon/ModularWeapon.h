// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ModularWeapon.generated.h"

class USkeletalMeshComponent;
class USphereComponent;
class AModularCharacter;
class UAnabasisWeaponData;

UCLASS()
class ANABASIS_API AModularWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	AModularWeapon();
	virtual void Tick(float DeltaTime) override;
	void Fire(const FVector&);

protected:
	virtual void BeginPlay() override;

private:

	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	bool CanFire();
	void CountDownEvent(float DeltaTime);

	UPROPERTY()
	AModularCharacter* WeaponOwner;

	UPROPERTY(EditAnywhere, Category = "ModularWeapon", meta = (AllowPrivateAccess))
	FName SocketName;
	
	UPROPERTY(EditAnywhere, Category = "ModularWeapon", meta = (AllowPrivateAccess))
	UAnabasisWeaponData* WeaponData;

	float CountDownTimer = 0.0f;
	int32 Ammo;

	UPROPERTY(EditAnywhere, Category = "ModularWeapon", meta = (AllowPrivateAccess))
	USkeletalMeshComponent* MeshComponent;

	UPROPERTY(EditAnywhere, Category = "ModularWeapon", meta = (AllowPrivateAccess))
	USphereComponent* SphereComponent;
	
};
