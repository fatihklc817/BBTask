// Fill out your copyright notice in the Description page of Project Settings.


#include "BBTask/Public/BBaseInteractableItem.h"

// Sets default values
ABBaseInteractableItem::ABBaseInteractableItem()
{
 	//PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	RootComponent = Mesh;

}

void ABBaseInteractableItem::Interact_Implementation(AActor* InstigatorActor)
{
	
}




