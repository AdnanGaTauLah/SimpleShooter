// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_Fire.h"
#include "AIController.h"
#include "ShooterCharacter.h"

UBTTask_Fire::UBTTask_Fire()
{
	NodeName = "Fire";
}


EBTNodeResult::Type UBTTask_Fire::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	if (OwnerComp.GetAIOwner() == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	AShooterCharacter* Character = Cast<AShooterCharacter>(OwnerComp.GetAIOwner()->GetPawn());
	if (Character == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	Character->Fire();
	return EBTNodeResult::Succeeded;
}