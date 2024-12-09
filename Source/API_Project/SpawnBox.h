
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "SpawnBox.generated.h"

UCLASS()
class API_PROJECT_API ASpawnBox : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnBox();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called when actoer has stopped playing
	void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	bool SpawnActor();

	void ScheduleActorSpawn();

	int ActorNumer = 0;

private:
	UFUNCTION()
	void SpawnActorScheduled();

public:

	// Actor Class
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AActor> ActorClassToSpawn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool ShouldSpawn = true;

	// Average Spawn Time (Witout Random)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float AvgSpawnTime = 5.f;

	//RAndom Offset Spawn Time
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float RandomSpawnTimeOffset = 1.f;

private:

	// Box we will spawn the actor
	UPROPERTY(EditDefaultsOnly)
	UBoxComponent* SpawnBox;

	// Helper for timing
	FTimerHandle SpawnTimerHandle;
};
