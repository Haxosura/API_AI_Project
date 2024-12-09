// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnBox.h"

// Sets default values
ASpawnBox::ASpawnBox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// Setup Memebers
	SpawnBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Spawn Box"));
	RootComponent = SpawnBox;
}

// Called when the game starts or when spawned
void ASpawnBox::BeginPlay()
{
	Super::BeginPlay();
	
	// Frist Spawn
	if (ShouldSpawn)
	{
		ScheduleActorSpawn();
	}
}

void ASpawnBox::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	GetWorld()->GetTimerManager().ClearAllTimersForObject(this);
	//GetWorld()->GetTimerManager().ClearTimer(SpawnTimerHandle);
}

// Called every frame
void ASpawnBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (ActorNumer <= 3)
	{
		ShouldSpawn = false;
	}
}

bool ASpawnBox::SpawnActor()
{
	bool SpawnedActor = false;

	if (ActorClassToSpawn)
	{
		// Calculate the extands of the box
		FBoxSphereBounds BoxBounds = SpawnBox->CalcBounds(GetActorTransform());

		// Compute a Random Postion Within The box Bounds
		FVector SpawnLocation = BoxBounds.Origin;
		SpawnLocation.X += -BoxBounds.BoxExtent.X + 2 * BoxBounds.BoxExtent.X * FMath::FRand();
		SpawnLocation.Y += -BoxBounds.BoxExtent.Y + 2 * BoxBounds.BoxExtent.Y * FMath::FRand();
		SpawnLocation.Z += -BoxBounds.BoxExtent.Z + 2 * BoxBounds.BoxExtent.Z * FMath::FRand();

		// Spawn Actor
		SpawnedActor = GetWorld()->SpawnActor(ActorClassToSpawn, &SpawnLocation) != nullptr;
		ActorNumer += 1;

	}

	return SpawnedActor;
}

void ASpawnBox::ScheduleActorSpawn()
{	
	// Compute time offset to spawn
	float DetlaToNextSpawn = AvgSpawnTime + (-RandomSpawnTimeOffset + 2 * RandomSpawnTimeOffset * FMath::FRand());
	
	// Schedule Spawning
	GetWorld()->GetTimerManager().SetTimer(SpawnTimerHandle, this, &ASpawnBox::SpawnActorScheduled, DetlaToNextSpawn, false);
}

void ASpawnBox::SpawnActorScheduled()
{
	// Spawn and Reschedule if Need
	if (SpawnActor())
	{
		if (ShouldSpawn)
		{
			ScheduleActorSpawn();
		}
	}
}
