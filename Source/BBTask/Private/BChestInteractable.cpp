// Fill out your copyright notice in the Description page of Project Settings.


#include "BBTask/Public/BChestInteractable.h"

#include "Components/ArrowComponent.h"
#include "Net/UnrealNetwork.h"

ABChestInteractable::ABChestInteractable()
{
	SpawnSocketPos = CreateDefaultSubobject<UArrowComponent>("Spawn Socket Position");
	SpawnSocketPos->SetupAttachment(RootComponent);
}

void ABChestInteractable::Interact_Implementation(AActor* InstigatorActor)
{
	Super::Interact_Implementation(InstigatorActor);

	UE_LOG(LogTemp, Warning, TEXT("chest interacted"));

	SpawnRandomObjFromDTTable();
	
}



void ABChestInteractable::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ABChestInteractable,SpawnObjectDataTable);
}

void ABChestInteractable::SpawnRandomObjFromDTTable()
{
	TArray<FChestSpawnObjects*> Rows;
	SpawnObjectDataTable->GetAllRows("",Rows);
	if (Rows.Num()>0)
	{
		int RandomIndex = FMath::RandRange(0,Rows.Num() - 1 );
		TSubclassOf<AActor> ActorToSpawnClass = Rows[RandomIndex]->SpawnActorClass;
		GetWorld()->SpawnActor<AActor>(ActorToSpawnClass,SpawnSocketPos->GetComponentLocation(),FRotator::ZeroRotator);
		UE_LOG(LogTemp, Warning, TEXT("spawneddd"));
	}
}
