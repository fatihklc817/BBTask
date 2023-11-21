// Fill out your copyright notice in the Description page of Project Settings.


#include "BBTask/Public/BWorldSpawnPoint.h"

#include "Components/ArrowComponent.h"

// Sets default values
ABWorldSpawnPoint::ABWorldSpawnPoint()
{
 	//PrimaryActorTick.bCanEverTick = true;
	SpawnSocket = CreateDefaultSubobject<UArrowComponent>("SpawnSocket");
	RootComponent = SpawnSocket;
	
}



