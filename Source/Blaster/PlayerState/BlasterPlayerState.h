// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "BlasterPlayerState.generated.h"

class ABlasterPlayerController;
class ABlasterCharacter;
/**
 * 
 */
UCLASS()
class BLASTER_API ABlasterPlayerState : public APlayerState
{
	GENERATED_BODY()

public:
	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;
	void AddToScore(float ScoreAmount);
	void AddToDefeats(int32 DefeatsAmount);

	/**
	 * Replication notifies
	 */
	virtual void OnRep_Score() override;
	
	UFUNCTION()
	virtual void OnRep_Defeats();
	
private:
	UPROPERTY()
	ABlasterCharacter* Character ;

	UPROPERTY()
	ABlasterPlayerController* Controller;

	UPROPERTY(ReplicatedUsing="OnRep_Defeats")
	int32 Defeats;
	
};
