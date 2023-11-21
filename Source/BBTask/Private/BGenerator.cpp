// Fill out your copyright notice in the Description page of Project Settings.


#include "BBTask/Public/BGenerator.h"

#include "Engine/Light.h"

void ABGenerator::Interact_Implementation(AActor* InstigatorActor)
{
	UE_LOG(LogTemp, Warning, TEXT("aha buraya girdim hacı"));
	if (LightsList.Num()>0)
	{
		for (auto light : LightsList)
		{
			if (light == nullptr) { continue; }
			light->SetBrightness(50);
		}
	}
}
