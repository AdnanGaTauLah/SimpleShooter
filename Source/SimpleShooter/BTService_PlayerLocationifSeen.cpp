// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_PlayerLocationifSeen.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/Pawn.h"
#include "AIController.h"

UBTService_PlayerLocationifSeen::UBTService_PlayerLocationifSeen()
{
	NodeName = TEXT("Update Player Location If Seen");
}

void UBTService_PlayerLocationifSeen::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	// Call the parent class's TickNode function
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	// Get the AI controller
	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	if (PlayerPawn == nullptr)
	{
		return;
	}

	if (OwnerComp.GetAIOwner() == nullptr)
	{
		return;
	}

	// Get the AI controller
	AAIController* AIController = OwnerComp.GetAIOwner();
	if (AIController == nullptr)
	{
		return;
	}

	// Get the AI controller's blackboard
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (BlackboardComp == nullptr)
	{
		return;
	}

	// Check if the AI controller can see the player
	if (AIController->LineOfSightTo(PlayerPawn))
	{
		// Set the player's location in the blackboard
		BlackboardComp->SetValueAsObject(GetSelectedBlackboardKey(), PlayerPawn);
	}
	else
	{
		// Clear the player's location in the blackboard
		BlackboardComp->ClearValue(GetSelectedBlackboardKey());
	}
}