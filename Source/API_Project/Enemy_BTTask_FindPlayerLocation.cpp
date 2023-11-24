// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy_BTTask_FindPlayerLocation.h"

#include "NavigationSystem.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"

UEnemy_BTTask_FindPlayerLocation::UEnemy_BTTask_FindPlayerLocation(FObjectInitializer const& ObjectInitializer)
{
	NodeName = TEXT("Find Player Location");
}

EBTNodeResult::Type UEnemy_BTTask_FindPlayerLocation::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	// Get Player Character
	if (auto* const Player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))
	{
		// Get Player Location To Use As An Origin
		auto const PlayerLocation = Player->GetActorLocation();

		if (SearchRandom)
		{
			FNavLocation Loc;

			// Get the Navigagtion System To Generate A Random Location Around The Player For The Enemy
			if (auto* const NavSys = UNavigationSystemV1::GetCurrent(GetWorld()))
			{
				// Enenmy Tries To Get to Location Near Player
				if (NavSys->GetRandomPointInNavigableRadius(PlayerLocation, SearchRadius, Loc))
				{
					OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(), Loc.Location);
					FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
					return EBTNodeResult::Succeeded;
				}
			}
		}

		else
		{
			OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(), PlayerLocation);
			FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
			return EBTNodeResult::Succeeded;
		}

	}

	return EBTNodeResult::Failed;
}
