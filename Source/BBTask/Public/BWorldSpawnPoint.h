// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BWorldSpawnPoint.generated.h"

UCLASS()
class BBTASK_API ABWorldSpawnPoint : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere)
	class UArrowComponent* SpawnSocket;
	
public:	
	// Sets default values for this actor's properties
	ABWorldSpawnPoint();



};
