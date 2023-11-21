// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BBaseInteractableItem.h"
#include "Engine/DataTable.h"
#include "BChestInteractable.generated.h"

USTRUCT(BlueprintType)
struct FChestSpawnObjects : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly,Category="DataTable")
	TSubclassOf<AActor> SpawnActorClass;
	
	
};


UCLASS()
class BBTASK_API ABChestInteractable : public ABBaseInteractableItem
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditDefaultsOnly,Replicated)
	UDataTable* SpawnObjectDataTable;

protected:
	UPROPERTY(VisibleAnywhere)
	class UArrowComponent* SpawnSocketPos;
	
public:
	ABChestInteractable();
	
	virtual void Interact_Implementation(AActor* InstigatorActor) override;

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

protected:
	void SpawnRandomObjFromDTTable();
	
};
