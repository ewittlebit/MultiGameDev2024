// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DiffResults.h"
#include "GameFramework/Character.h"
#include "MGCharacter.generated.h"

UCLASS()
class MGD_TEMPLATE_API AMGCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMGCharacter();

	UFUNCTION(BlueprintCallable, Category="Movement")
	void PMoveCharacter(FVector2D axis);

	UFUNCTION(BlueprintCallable, Category="Shooting")
    bool IsHoldingTrigger() const {return bIsHoldingTrigger;}

    UFUNCTION(BlueprintCallable, Category="Shooting")
	void HoldTrigger(bool pullOrRelease);

    UFUNCTION(BlueprintImplementableEvent, Category="Shooting")
	void OnTriggerChange(bool pullOrRelease);

    UFUNCTION(Server, Reliable, Category="Shooting")
	void Server_OnTriggerChange(const bool pullOrRelease);

    UFUNCTION(NetMulticast, Reliable, Category="Shooting")
	void Multi_OnTriggerChange(const bool pullOrRelease);

private:
	bool bIsHoldingTrigger;
};

