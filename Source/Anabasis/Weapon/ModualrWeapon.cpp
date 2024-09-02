// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon/ModularWeapon.h"
#include "Character/ModularCharacter.h"
#include "Weapon/AnabasisWeaponData.h"

#include "Components/SkeletalMeshComponent.h"
#include "Components/SphereComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetSystemLibrary.h"

AModularWeapon::AModularWeapon()
{
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>("MeshComponent");
	SetRootComponent(MeshComponent);
	MeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	SphereComponent = CreateDefaultSubobject<USphereComponent>("SphereComponent");
	SphereComponent->SetupAttachment(GetRootComponent());
	SphereComponent->SetSphereRadius(100.0f);
	SphereComponent->OnComponentBeginOverlap.AddDynamic(this, &AModularWeapon::OnBeginOverlap);

}

void AModularWeapon::BeginPlay()
{
	Super::BeginPlay();
	Ammo = WeaponData->MaxAmmo;
}

void AModularWeapon::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AModularCharacter* Target = Cast<AModularCharacter>(OtherActor);
	if (Target)
	{
		WeaponOwner = Target;
		Target->SetWeapon(this);
		Target->SetCharacterState(ECharacterStates::Armed);
		SphereComponent->OnComponentBeginOverlap.RemoveAll(this);
		SphereComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);

		MeshComponent->AttachToComponent(Target->GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, SocketName);
	}
}

void AModularWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	CountDownEvent(DeltaTime);
}

void AModularWeapon::Fire(const FVector& MousePos)
{
	if (GetWorld() && CanFire())
	{
		WeaponOwner->SetCharacterState(ECharacterStates::Fire);
		WeaponOwner->PlayAnimMontage(WeaponData->AnimMontage);

		FHitResult HitResult;
		FVector Start = WeaponOwner->GetMesh()->GetSocketLocation(WeaponData->MuzzleStart);
		FVector End = MousePos; // .GetSafeNormal()* WeaponData->TraceDist;
		//WeaponOwner->PitchFire();
		bool Hit = GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECollisionChannel::ECC_Visibility);
		if (Hit)
		{
			UKismetSystemLibrary::DrawDebugLine(this, Start, HitResult.Location, FLinearColor::Red, 0.05f);
			UKismetSystemLibrary::DrawDebugPoint(this, HitResult.Location, 15.0f, FLinearColor::Red, 5.0f);
		}
		--Ammo;
	}
}

bool AModularWeapon::CanFire()
{
	return WeaponOwner && Ammo > 0 && CountDownTimer == WeaponData->CountDown;
}

void AModularWeapon::CountDownEvent(float DeltaTime)
{
	if (CountDownTimer > 0)
	{
		CountDownTimer -= DeltaTime;
	}
	else
	{
		CountDownTimer = WeaponData->CountDown;
	}
}