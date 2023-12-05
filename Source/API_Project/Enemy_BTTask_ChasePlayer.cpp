// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy_BTTask_ChasePlayer.h"
#include "EnemyAIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include <Blueprint/AIBlueprintHelperLibrary.h>

UEnemy_BTTask_ChasePlayer::UEnemy_BTTask_ChasePlayer(FObjectInitializer const& ObjectInitializer)
{
	NodeName = TEXT("Chase Player");
}

EBTNodeResult::Type UEnemy_BTTask_ChasePlayer::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	// Get Target Location From Blackboard Via The Enemy's Controller
	if (auto* const cont = Cast<AEnemyAIController>(OwnerComp.GetAIOwner()))
	{
		auto const PlayerLocation = OwnerComp.GetBlackboardComponent()->GetValueAsVector(GetSelectedBlackboardKey());

		// Move To The Player's Location
		UAIBlueprintHelperLibrary::SimpleMoveToLocation(cont, PlayerLocation);

		// Finish With Success
		FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
		return EBTNodeResult::Succeeded;

	}
	return EBTNodeResult::Failed;
}
