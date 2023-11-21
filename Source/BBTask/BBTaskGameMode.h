// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameFramework/GameModeBase.h"
#include "BBTaskGameMode.generated.h"

USTRUCT()
struct FWorldRandomSpawnObjects : public FTableRowBase
{
	GENERATED_BODY()
public:
	UPROPERTY(EditDefaultsOnly,Category="DataTable")
	TSubclassOf<AActor> SpawnActorClass;
};

UCLASS(minimalapi)
class ABBTaskGameMode : public AGameModeBase
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditDefaultsOnly,Category="DT",Replicated)
	UDataTable* WorldSpawnObjectsDataTable;

	UPROPERTY()
	TArray<class ABWorldSpawnPoint*> SpawnPoints;
	
	FTimerHandle TimerHandle_SpawnRandomItem;

	UPROPERTY()
	ABWorldSpawnPoint* LastUsedSpawnPoint;

	UPROPERTY()
	AActor* LastSpawnedItem;
	
public:
	ABBTaskGameMode();

	virtual void StartPlay() override;

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UFUNCTION(Server,Reliable)
	void SpawnRandomItemInWorld();
};



