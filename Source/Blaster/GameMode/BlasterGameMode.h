// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "BlasterGameMode.generated.h"

class ABlasterCharacter;
class ABlasterPlayerController;

/**
 * 
 */
UCLASS()
class BLASTER_API ABlasterGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	ABlasterGameMode();
	virtual void Tick(float DeltaSeconds) override;
	
	virtual void PlayerEliminated(
		ABlasterCharacter* EliminatedCharacter, 
		ABlasterPlayerController* VictimController, 
		ABlasterPlayerController* AttackerController
	);

	virtual void RequestRespawn(ACharacter* ElimmedCharacter, AController* ElimmedController);

	UPROPERTY(EditDefaultsOnly)
	float WarmUpTime = 10.f;

	
	float LevelStartingTime = 0.f;

protected:
	virtual void BeginPlay() override;

private:
	float CountDownTime = 0.f;
};
