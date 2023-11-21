// Copyright Epic Games, Inc. All Rights Reserved.

#include "BBTaskGameMode.h"
#include "BBTaskCharacter.h"
#include "EngineUtils.h"
#include "Components/ArrowComponent.h"
#include "Net/UnrealNetwork.h"
#include "Public/BWorldSpawnPoint.h"
#include "UObject/ConstructorHelpers.h"

ABBTaskGameMode::ABBTaskGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void ABBTaskGameMode::StartPlay()
{
	Super::StartPlay();

	for (ABWorldSpawnPoint* SpawnPoint : TActorRange<ABWorldSpawnPoint>(GetWorld()))
	{
		SpawnPoints.Push(SpawnPoint);
	}

	GetWorldTimerManager().SetTimer(TimerHandle_SpawnRandomItem,this,&ABBTaskGameMode::SpawnRandomItemInWorld,45,true,10);
}

void ABBTaskGameMode::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ABBTaskGameMode,WorldSpawnObjectsDataTable);
}

void ABBTaskGameMode::SpawnRandomItemInWorld_Implementation()
{
	if (LastUsedSpawnPoint)
	{
		//do not spawn at the last spawned point 
		SpawnPoints.Remove(LastUsedSpawnPoint);
	}
	
	if (LastSpawnedItem)
	{
		LastSpawnedItem->Destroy();
	}
	
	int RandomIndex = FMath::RandRange(0,SpawnPoints.Num() - 1);
	ABWorldSpawnPoint* SelectedSpawnPoint = SpawnPoints[RandomIndex];
	
	TArray<FWorldRandomSpawnObjects*> Rows;
	WorldSpawnObjectsDataTable->GetAllRows("",Rows);
	if (Rows.Num()>0)
	{
		int RandomIndexOfDT = FMath::RandRange(0,Rows.Num() - 1 );
		TSubclassOf<AActor> ActorToSpawnClass = Rows[RandomIndexOfDT]->SpawnActorClass;
		LastSpawnedItem = GetWorld()->SpawnActor<AActor>(ActorToSpawnClass, SelectedSpawnPoint->SpawnSocket->GetComponentLocation(), FRotator::ZeroRotator);
		SpawnPoints.Push(LastUsedSpawnPoint);
		LastUsedSpawnPoint = SelectedSpawnPoint;
		
		UE_LOG(LogTemp, Warning, TEXT("Spawned Random World item"));
	}
}
