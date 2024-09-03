// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Weapon/ModularWeapon.h"
#include "CommonTypes/CommonTypes.h"
#include "ModularCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UAnabasisWeaponData;
class UModularAbility;
class UBaseAnimInstance;

UCLASS()
class ANABASIS_API AModularCharacter : public ACharacter, public IModularWeapon
{
	GENERATED_BODY()

public:
	AModularCharacter();
	virtual void Tick(float DeltaTime) override;

	FORCEINLINE ECharacterStates GetCharacterState() const { return CharacterState; }
	FORCEINLINE void SetCharacterState(ECharacterStates Type) { CharacterState = Type; }

	UFUNCTION(BlueprintPure)
	float GetSpringArmLength() const;

	UFUNCTION(BlueprintCallable)
	void SetSprintArmLength(float length);

	virtual void Attack() override;

protected:
	virtual void BeginPlay() override;
	virtual bool CanAttack() override;
	virtual void CountDownEvent(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = "ModularCharacter")
	UModularAbility* AbilityData;

	UPROPERTY()
	UBaseAnimInstance* BaseAnimInstance;

	ECharacterStates CharacterState = ECharacterStates::Idle;
private:

    UPROPERTY(EditAnywhere, Category = "ModularCharacter", meta = (AllowPrivateAccess))
    USpringArmComponent* SpringArmComponent;

    UPROPERTY(EditAnywhere, Category = "ModularCharacter", meta = (AllowPrivateAccess))
    UCameraComponent* CameraComponent;

};
