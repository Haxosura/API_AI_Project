// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "Enemy_BTTask_FindPathPoint.generated.h"

/**
 * 
 */
UCLASS()
class API_PROJECT_API UEnemy_BTTask_FindPathPoint : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
	
public:

	explicit UEnemy_BTTask_FindPathPoint(FObjectInitializer const& ObjectInitializer);

private:

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	virtual FString GetStaticDescription() const override;

	UPROPERTY(EditAnywhere, Category = "Blackbaord", meta = (AllowPrivateAccess = "true"))
	FBlackboardKeySelector PatrolPathVectorKey;

};