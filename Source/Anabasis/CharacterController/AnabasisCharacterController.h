#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "AnabasisCharacterController.generated.h"

class UInputAction;
class UInputMappingContext;
struct FInputActionValue;
class AModularCharacter;

UCLASS()
class ANABASIS_API AAnabasisCharacterController : public APlayerController
{
    GENERATED_BODY()

public:
    AAnabasisCharacterController();
    virtual void Tick(float DeltaSeconds) override;
    UFUNCTION(BlueprintCallable)
    FORCEINLINE void SetControlledPawn(AModularCharacter* Target) { ControlledPawn = Target; }
protected:
    virtual void BeginPlay() override;
    virtual void SetupInputComponent() override;
private:

    void Action_Move(const FInputActionValue& InputActionValue);
    void Action_Look(float DeltaSeconds);
    void Action_Zoom(const FInputActionValue& InputActionValue);
    void Timer_Zoom();
    void Action_Fire();
    void Action_FireStop();
    void ClaculateNormalizeMousePosition();

    UPROPERTY(EditAnywhere, Category = "AnabasisCharacterController", meta = (AllowPrivateAccess))
    UInputAction* IA_Move;

    UPROPERTY(EditAnywhere, Category = "AnabasisCharacterController", meta = (AllowPrivateAccess))
    UInputAction* IA_Zoom;

    UPROPERTY(EditAnywhere, Category = "AnabasisCharacterController", meta = (AllowPrivateAccess))
    UInputAction* IA_Fire;

    UPROPERTY(EditAnywhere, Category = "AnabasisCharacterController", meta = (AllowPrivateAccess))
    UInputMappingContext* IMC_Default;

    UPROPERTY(VisibleAnywhere, Category = "AnabasisCharacterController", meta = (AllowPrivateAccess))
    AModularCharacter* ControlledPawn = nullptr;

    UPROPERTY(EditAnywhere, Category = "AnabasisCharacterController", meta = (AllowPrivateAccess))
    int8 NumberIterations = 50;

    FTimerHandle ZoomTimerHandle;

    float ZoomDirValue = 0.0f;

    UPROPERTY(BlueprintReadOnly, Category = "AnabasisCharacterController", meta = (AllowPrivateAccess))

    FVector MousePos;

    UPROPERTY(EditAnywhere, Category = "AnabasisCharacterController", meta = (AllowPrivateAccess))
    float ZoomStep = 5.0f;

    UPROPERTY(EditAnywhere, Category = "AnabasisCharacterController", meta = (AllowPrivateAccess))
    float ZoomMin = 300.0f;

    UPROPERTY(EditAnywhere, Category = "AnabasisCharacterController", meta = (AllowPrivateAccess))
    float ZoomMax = 800.0f;

};