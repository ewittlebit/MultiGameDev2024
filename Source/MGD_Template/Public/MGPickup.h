// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/Actor.h"
#include "MGPickup.generated.h"

UCLASS()
class MGD_TEMPLATE_API AMGPickup : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMGPickup();

	UPROPERTY(EditAnywhere, Category=Components)
	UCapsuleComponent* PickupTrigger;

	UPROPERTY(EditAnywhere, Category=Components)
	UStaticMeshComponent* Mesh;

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

protected:

	// run code when pickup is activated
	void ActivatePickup(AActor* pickupActor);

	UFUNCTION(BlueprintImplementableEvent, Category=Pickup)
	void BP_OnActivatePickup(AActor* pickupActor);

    UFUNCTION(NetMulticast, Reliable, Category=Replication)
	void DeactivatePickup();

	UFUNCTION(NetMulticast, Reliable, Category=Replication)
    void ReactivatePickup();
	
	UPROPERTY(EditDefaultsOnly, Category=Pickup)
	TSubclassOf<AActor> PickupActorClass;
};
