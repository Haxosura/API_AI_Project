// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "Enemy_BTTask_FindRandomLocation.generated.h"

/**
 *
 */
UCLASS()
class API_PROJECT_API UEnemy_BTTask_FindRandomLocation : public UBTTask_BlackboardBase
{
    GENERATED_BODY()

public:
    UEnemy_BTTask_FindRandomLocation();

private:
    virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
    virtual FString GetStaticDescription() const override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Search", meta = (AllowPrivateAccess = true))
    float SearchRaduis{ 500.f };
};