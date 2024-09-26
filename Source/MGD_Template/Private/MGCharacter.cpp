// Fill out your copyright notice in the Description page of Project Settings.


#include "MGCharacter.h"

#include "Kismet/KismetMathLibrary.h"
#include "Runtime/AnimGraphRuntime/Public/KismetAnimationLibrary.h"

// Sets default values
AMGCharacter::AMGCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}
void AMGCharacter::PMoveCharacter(FVector2D axis)
{
	//Create a local rotation vairable
	FRotator controlRot;

	// set the yar to the same as the controllers yaw
	controlRot.Yaw = GetControlRotation().Yaw;

	//move the character forward and back
	AddMovementInput(UKismetMathLibrary::GetForwardVector(controlRot),axis.Y);

	//move the character right and left
	AddMovementInput(UKismetMathLibrary::GetRightVector(controlRot),axis.X);
	
}


