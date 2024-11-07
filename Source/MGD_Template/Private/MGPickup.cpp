// Fill out your copyright notice in the Description page of Project Settings.


#include "MGPickup.h"

// Sets default values
AMGPickup::AMGPickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SetReplicates(true);

	// create the component
	PickupTrigger = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Collision"));
	// set component to be root fo class
	SetRootComponent(PickupTrigger);

	//set the default size of the collision
	PickupTrigger->SetCapsuleHalfHeight(100.0f);
	PickupTrigger->SetCapsuleRadius(100.0f);

	// creating static mesh
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	// attach to actor
	Mesh->SetupAttachment(RootComponent);

	// move mesh up by default
	Mesh->SetRelativeLocation(FVector(0.0f, 0.0f, 50.0f));

	// turn collisions off on mesh
	Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

    // default allowed pickup class
	PickupActorClass= AActor::StaticClass();

	ResetTime = 10.0f;

	MeshRotateSpeed = 50.0f;
}

void AMGPickup::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	if (!HasAuthority())
	{
		return;
	}
	
	if (OtherActor->GetClass()->IsChildOf(PickupActorClass))
	{
		ActivatePickup(OtherActor);
	}
}

void AMGPickup::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	
// spinning mesh based on rotation speed
	Mesh->AddLocalRotation(FRotator(0.0f, MeshRotateSpeed * DeltaSeconds, 0.0f));

void AMGPickup::ActivatePickup(AActor* pickupActor)
{
	BP_OnActivatePickup(pickupActor);

	DeactivatePickup();
	
    if (ResetTime > 0.0f)
    {
    	// if so set timer to reactivate pickup
	    GetWorld()->GetTimerManager().SetTimer(TH_ReactivateTimer, this, &AMGPickup::ReactivatePickup, ResetTime);
    }
}

void AMGPickup::ReactivatePickup_Implementation()
{
	//is this server version
	if (HasAuthority())
	{
		PickupTrigger->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	}

	// regardless of server or client reveal mesh
	Mesh->SetVisibility(true, true);
}

void AMGPickup::DeactivatePickup_Implementation()
	{
		//is this the server version
		if (HasAuthority())
		{
			//if so, disable collision
			PickupTrigger->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		}
		//hide mesh
		Mesh->SetVisibility(false, true);
	}


