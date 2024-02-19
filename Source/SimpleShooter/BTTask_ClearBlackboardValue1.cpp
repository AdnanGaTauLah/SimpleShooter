// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_ClearBlackboardValue1.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_ClearBlackboardValue1::UBTTask_ClearBlackboardValue1()
{
	NodeName = TEXT("Clear Blackboard Value");
}

EBTNodeResult::Type UBTTask_ClearBlackboardValue1::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	OwnerComp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());
	return EBTNodeResult::Succeeded;
}