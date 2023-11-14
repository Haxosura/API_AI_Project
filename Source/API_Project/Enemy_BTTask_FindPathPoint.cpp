// Fill out your copyright notice in the Description page of Project Settings.

#include "Enemy_BTTask_FindPathPoint.h"

#include "EnemyCharacter.h"
#include "EnemyAIController.h"
#include "BehaviorTree/BlackboardComponent.h"

UEnemy_BTTask_FindPathPoint::UEnemy_BTTask_FindPathPoint(FObjectInitializer const& ObjectInitializer)
{
	NodeName = TEXT("Find Path Point");
}

EBTNodeResult::Type UEnemy_BTTask_FindPathPoint::ExecuteTasK(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	// Attempt to get the enmey's controller
	if (auto* const cont = Cast<AEnemyAIController>(OwnerComp.GetAIOwner()))
	{
		// Attempt to get the blackboard component from the behavior tree

		if (auto* const bc = OwnerComp.GetBlackboardComponent())
		{
			// Get the current patrol path index from the blackboard
			auto const index = bc->GetValueAsInt((GetSelectedBlackboardKey()));

			// Get the NPC
			if (auto* enemy = Cast<AEnemyCharacter>(cont->GetPawn()))
			{
				// Get the current patrol path vector from the enemy - This is local to the patrol path actor
				auto const Point = enemy->GetPatrolPath()->GetPatrolPoint(index);

				// Convert the local vector to a gloobal point
				auto const GlobalPoint = enemy->GetPatrolPath()->GetActorTransform().TransformPosition(Point);
				bc->SetValueAsVector(PatrolPathVectorKey.SelectedKeyName, GlobalPoint);

				// Finish with Success
				FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
				return EBTNodeResult::Succeeded;
			}
		}
	}

	return EBTNodeResult::Failed;
}
