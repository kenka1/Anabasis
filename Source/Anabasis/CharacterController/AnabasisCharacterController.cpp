#include "CharacterController/AnabasisCharacterController.h"
#include "Character/ModularCharacter.h"
#include "Weapon/ModularWeapon.h"

#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Engine/LocalPlayer.h"
#include "Subsystems/LocalPlayerSubsystem.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"

AAnabasisCharacterController::AAnabasisCharacterController()
{
	UE_LOG(LogTemp, Warning, TEXT("AAnabasisCharacterController::AAnabasisCharacterController()"));
	bShowMouseCursor = true;
}

void AAnabasisCharacterController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	Action_Look(DeltaSeconds);
}

void AAnabasisCharacterController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("AAnabasisCharacterController::BeginPlay()"));

	ControlledPawn = GetPawn<AModularCharacter>();
	check(ControlledPawn);
}

void AAnabasisCharacterController::SetupInputComponent()
{
	Super::SetupInputComponent();
	UE_LOG(LogTemp, Warning, TEXT("AAnabasisCharacterController::SetupInputComponent()"));
	UEnhancedInputLocalPlayerSubsystem* PlayerSubsystem = GetLocalPlayer()->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
	if (PlayerSubsystem)
	{
		PlayerSubsystem->AddMappingContext(IMC_Default, 0);
	}

	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);
	if (EnhancedInputComponent)
	{
		EnhancedInputComponent->BindAction(IA_Move, ETriggerEvent::Triggered, this, &AAnabasisCharacterController::Action_Move);
		EnhancedInputComponent->BindAction(IA_Zoom, ETriggerEvent::Triggered, this, &AAnabasisCharacterController::Action_Zoom);
		EnhancedInputComponent->BindAction(IA_Fire, ETriggerEvent::Triggered, this, &AAnabasisCharacterController::Action_Attack);
		EnhancedInputComponent->BindAction(IA_Fire, ETriggerEvent::Completed, this, &AAnabasisCharacterController::Action_AttackStop);
	}

}

void AAnabasisCharacterController::Action_Move(const FInputActionValue& InputActionValue)
{
	const FVector2D ActionValue = InputActionValue.Get<FVector2D>();

	if (ActionValue.X)
	{
		ControlledPawn->AddMovementInput(FVector(1.0, 0.0, 0.0), ActionValue.X);
	}
	if (ActionValue.Y)
	{
		ControlledPawn->AddMovementInput(FVector(0.0, 1.0, 0.0), ActionValue.Y);
	}
}

void AAnabasisCharacterController::Action_Look(float DeltaSeconds)
{
	ClaculateNormalizeMousePosition();

	if (ControlledPawn)
	{
		double Yaw = UKismetMathLibrary::FindLookAtRotation(ControlledPawn->GetActorLocation(), MousePos).Yaw;
		ControlledPawn->SetActorRotation(FRotator(0.0, Yaw, 0.0));
	}
}

void AAnabasisCharacterController::Action_Zoom(const FInputActionValue& InputActionValue)
{
	ZoomDirValue = InputActionValue.Get<float>();
	NumberIterations = 0;
	GetWorldTimerManager().SetTimer(ZoomTimerHandle, this, &AAnabasisCharacterController::Timer_Zoom, UGameplayStatics::GetWorldDeltaSeconds(this), true);
}

void AAnabasisCharacterController::Timer_Zoom()
{
	if (NumberIterations > 50)
	{
		GetWorldTimerManager().ClearTimer(ZoomTimerHandle);
		NumberIterations = 0;
		return;
	}

	float SpringArmLength = ControlledPawn->GetSpringArmLength();
	SpringArmLength -= ZoomStep * ZoomDirValue;
	SpringArmLength = FMath::Clamp(SpringArmLength, ZoomMin, ZoomMax);
	ControlledPawn->SetSprintArmLength(SpringArmLength);

	++NumberIterations;
}

void AAnabasisCharacterController::Action_Attack()
{
	if (!ControlledPawn)
		return;
	ControlledPawn->Attack();
}

void AAnabasisCharacterController::Action_AttackStop()
{
	// FIRE STOP EVENT
}

void AAnabasisCharacterController::ClaculateNormalizeMousePosition()
{
	FHitResult HitResult;
	bool hit = GetHitResultUnderCursorByChannel(ETraceTypeQuery::TraceTypeQuery3, false, HitResult);
	if (hit)
	{
		//UKismetSystemLibrary::DrawDebugPoint(this, HitResult.Location, 15.0f, FLinearColor::Red, 0.1f);
		MousePos = HitResult.Location;
	}
}
