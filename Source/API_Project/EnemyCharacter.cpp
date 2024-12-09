// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyCharacter.h"
#include "API_ProjectCharacter.h"

// Called when the game starts or when spawned
void AEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AEnemyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AEnemyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

APatrolPath* AEnemyCharacter::GetPatrolPath() const
{
	return PatrolPath;
}