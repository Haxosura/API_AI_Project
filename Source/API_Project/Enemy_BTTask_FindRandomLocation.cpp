// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy_BTTask_FindRandomLocation.h"

#include "AIController.h"
#include "NavigationSystem.h"
#include "BehaviorTree/BlackboardComponent.h"


UEnemy_BTTask_FindRandomLocation::UEnemy_BTTask_FindRandomLocation(FObjectInitializer const& ObjectInitializer) : UBTTask_BlackboardBase{ ObjectInitializer }
{
    NodeName = TEXT("Find Random Location");

    // Accept Only Vector
    BlackboardKey.AddVectorFilter(this, GET_MEMBER_NAME_CHECKED(
        UEnemy_BTTask_FindRandomLocation, BlackboardKey));
}

EBTNodeResult::Type UEnemy_BTTask_FindRandomLocation::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    FNavLocation Location{};

    // Get AI Pawn
    AAIController* AIController{ OwnerComp.GetAIOwner() };
    const APawn* AIPawn{ AIController->GetPawn() };

    // Get Pawn Origin
    const FVector Origin{ AIPawn->GetActorLocation() };

    // Obatin Navigation System and Find A Random Location
    const UNavigationSystemV1* NavSystem{ UNavigationSystemV1::GetCurrent(GetWorld()) };
    if (IsValid(NavSystem) && NavSystem->GetRandomPointInNavigableRadius(Origin, SearchRaduis, Location))
    {
        AIController->GetBlackboardComponent()->SetValueAsVector(BlackboardKey.SelectedKeyName, Location.Location);
    }

    // Signal The BehaviorTreeComponent That The With A Success
    FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
    return EBTNodeResult::Succeeded;

}

FString UEnemy_BTTask_FindRandomLocation::GetStaticDescription() const
{
    return FString::Printf(TEXT("Vector: %s"), *BlackboardKey.SelectedKeyName.ToString());
}