// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CommonTypes/CommonTypes.h"
#include "ModularCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class AModularWeapon;

UCLASS()
class ANABASIS_API AModularCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AModularCharacter();
	virtual void Tick(float DeltaTime) override;

	FORCEINLINE void SetWeapon(AModularWeapon* weapon) { Weapon = weapon; }
	FORCEINLINE AModularWeapon* GetWeapon() const { return Weapon; }
	FORCEINLINE ECharacterStates GetCharacterState() const { return CharacterState; }
	FORCEINLINE void SetCharacterState(ECharacterStates Type) { CharacterState = Type; }

	UFUNCTION(BlueprintPure)
	float GetSpringArmLength() const;

	UFUNCTION(BlueprintCallable)
	void SetSprintArmLength(float length);

	void PitchFire();

protected:
	virtual void BeginPlay() override;

private:

    UPROPERTY(EditAnywhere, Category = "ModularCharacter", meta = (AllowPrivateAccess))
    USpringArmComponent* SpringArmComponent;

    UPROPERTY(EditAnywhere, Category = "ModularCharacter", meta = (AllowPrivateAccess))
    UCameraComponent* CameraComponent;

	UPROPERTY(VisibleAnywhere, Category = "ModularCharacter", meta = (AllowPrivateAccess))
	AModularWeapon* Weapon = nullptr;

	ECharacterStates CharacterState = ECharacterStates::Idle;
};
