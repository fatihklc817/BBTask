// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BBaseInteractableItem.h"
#include "BGenerator.generated.h"

/**
 * 
 */
UCLASS()
class BBTASK_API ABGenerator : public ABBaseInteractableItem
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere,Category="lights",Replicated)
	TArray<class ALight*> LightsList;

	virtual void Interact_Implementation(AActor* InstigatorActor) override;

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UFUNCTION(NetMulticast,Reliable)
	void OpenLights();
	
};
