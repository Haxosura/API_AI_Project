// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyCharacter.h"
#include "API_ProjectCharacter.h"

// Called when the game starts or when spawned
void AEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
}

AEnemyCharacter::AEnemyCharacter(const FObjectInitializer& objectInitializer)
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	
	DeathSphere = CreateDefaultSubobject<USphereComponent>(TEXT("Death Sphere"));

	DeathSphere->SetSphereRadius(20.f);
	DeathSphere->SetHiddenInGame(false);
	//DeathSphere->OnComponentBeginOverlap.AddDynamic(this, &AEnemyCharacter::OnDeathSphereBeginOverlap);

	RootComponent = DeathSphere;
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

void AEnemyCharacter::OnDeathSphereBeginOverlap(AActor* Actor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (auto* const ch = Cast<AAPI_ProjectCharacter>(Actor))
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Purple, TEXT("Player Seen"));
	}
}