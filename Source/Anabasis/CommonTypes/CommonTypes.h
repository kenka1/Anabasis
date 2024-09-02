#pragma once

UENUM(BlueprintType)
enum class ECharacterStates : uint8
{
	Idle UMETA(DisplayName = "Idle"),
	Walk UMETA(DisplayName = "Walk"),
	Run UMETA(DisplayName = "Run"),
	Armed UMETA(DisplayName = "Armed"),
	Fire UMETA(DisplayName = "Fire"),
	Dead UMETA(DisplayName = "Dead")
};