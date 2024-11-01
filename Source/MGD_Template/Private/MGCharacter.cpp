// Fill out your copyright notice in the Description page of Project Settings.


#include "MGCharacter.h"

#include "Kismet/KismetArrayLibrary.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
AMGCharacter::AMGCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}
void AMGCharacter::PMoveCharacter(FVector2d axis)
{
    FRotator controlRot;

	controlRot.Yaw = GetControlRotation().Yaw;

	AddMovementInput(UKismetMathLibrary::GetForwardVector(controlRot), axis.Y);

	AddMovementInput(UKismetMathLibrary::GetForwardVector(controlRot), axis.X);
}


