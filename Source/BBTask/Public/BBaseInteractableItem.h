// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractInterface.h"
#include "GameFramework/Actor.h"
#include "BBaseInteractableItem.generated.h"

UCLASS()
class BBTASK_API ABBaseInteractableItem : public AActor , public  IInteractInterface
{
	GENERATED_BODY()
protected:
	
	UPROPERTY(EditDefaultsOnly,Category="Comps")
	UStaticMeshComponent* Mesh;
	
public:	
	ABBaseInteractableItem();

	virtual void Interact_Implementation(AActor* InstigatorActor) override;
	

};
