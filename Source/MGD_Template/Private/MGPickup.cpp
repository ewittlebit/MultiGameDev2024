// Fill out your copyright notice in the Description page of Project Settings.


#include "MGPickup.h"

// Sets default values
AMGPickup::AMGPickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMGPickup::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMGPickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

