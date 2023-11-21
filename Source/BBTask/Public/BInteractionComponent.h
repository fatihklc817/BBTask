// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BInteractionComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BBTASK_API UBInteractionComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UBInteractionComponent();

	UFUNCTION(Server,Reliable)
	void InteractWithItem();

		
};
