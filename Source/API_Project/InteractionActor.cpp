// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractionActor.h"
#include "API_ProjectCharacter.h"

// Sets default values
AInteractionActor::AInteractionActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	InteractionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("Interaction Sphere"));

	InteractionSphere->SetSphereRadius(SphereRaduis);
	InteractionSphere->SetHiddenInGame(false);
	InteractionSphere->SetCollisionProfileName("Trigger");

	RootComponent = InteractionSphere;

	InteractionSphere->OnComponentBeginOverlap.AddDynamic(this, &AInteractionActor::OnBeginOverlap);

}

void AInteractionActor::OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, 
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (auto* const ch = Cast<AAPI_ProjectCharacter>(OtherActor))
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Purple, TEXT("Actor Hit"));
	}
}

// Called when the game starts or when spawned
void AInteractionActor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AInteractionActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}