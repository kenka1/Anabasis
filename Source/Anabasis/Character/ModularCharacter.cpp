// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/ModularCharacter.h"

#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

AModularCharacter::AModularCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	UE_LOG(LogTemp, Warning, TEXT("AModularCharacter::AModularCharacter()"));
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArmComponent");
	SpringArmComponent->SetupAttachment(GetRootComponent());
	SpringArmComponent->SetRelativeRotation(FRotator(-70.0, 0.0, 0.0));
	SpringArmComponent->TargetArmLength = 1000.0f;
	SpringArmComponent->bEnableCameraLag = true;
	SpringArmComponent->bInheritPitch = false;
	SpringArmComponent->bInheritRoll = false;
	SpringArmComponent->bInheritYaw = false;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	CameraComponent->SetupAttachment(SpringArmComponent);

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

}

void AModularCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AModularCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

float AModularCharacter::GetSpringArmLength() const
{
	return SpringArmComponent->TargetArmLength;
}

void AModularCharacter::SetSprintArmLength(float length)
{
	SpringArmComponent->TargetArmLength = length;
}

void AModularCharacter::PitchFire()
{
}