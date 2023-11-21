// Fill out your copyright notice in the Description page of Project Settings.


#include "BBTask/Public/BInteractionComponent.h"

#include "BBTask/BBTaskCharacter.h"
#include "BBTask/Public/BBaseInteractableItem.h"
#include "Camera/CameraComponent.h"


UBInteractionComponent::UBInteractionComponent()
{
	
	//PrimaryComponentTick.bCanEverTick = true;

	
}

void UBInteractionComponent::InteractWithItem_Implementation()
{
	ABBTaskCharacter* MyCharacter = Cast<ABBTaskCharacter>(GetOwner());

	FVector StartPos = MyCharacter->GetFollowCamera()->GetComponentLocation();
	FRotator Rotation = MyCharacter->GetControlRotation();
	FVector EndPos = StartPos + Rotation.Vector() * 1000;

	FHitResult HitResult;
	FCollisionQueryParams params;
	params.AddIgnoredActor(MyCharacter);
	if( GetWorld()->LineTraceSingleByChannel(HitResult,StartPos,EndPos,ECC_Visibility,params))
	{
		if (ABBaseInteractableItem* Item = Cast<ABBaseInteractableItem>(HitResult.GetActor()))
		{
			if (Item->Implements<UInteractInterface>())
			{
				IInteractInterface::Execute_Interact(Item,MyCharacter);
			}
		}
	}
	DrawDebugLine(GetWorld(),StartPos,EndPos,FColor::Red,false,5,0,5);
}





