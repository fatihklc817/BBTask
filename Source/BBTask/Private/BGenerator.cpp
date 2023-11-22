// Fill out your copyright notice in the Description page of Project Settings.


#include "BBTask/Public/BGenerator.h"

#include "Engine/Light.h"
#include "Net/UnrealNetwork.h"

void ABGenerator::Interact_Implementation(AActor* InstigatorActor)
{
	UE_LOG(LogTemp, Warning, TEXT("aha buraya girdim hacı"));
	OpenLights();
}

void ABGenerator::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ABGenerator,LightsList);
}

void ABGenerator::OpenLights_Implementation()
{
	if (LightsList.Num()>0)
	{
		for (auto light : LightsList)
		{
			if (light == nullptr) { continue; }
			light->SetBrightness(50);
		}
	}
}


