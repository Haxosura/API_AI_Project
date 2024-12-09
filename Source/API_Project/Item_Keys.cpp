// Fill out your copyright notice in the Description page of Project Settings.


#include "Item_Keys.h"
#include "API_ProjectCharacter.h"

// Called when the game starts or when spawned
void AItem_Keys::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AItem_Keys::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AItem_Keys::OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (auto* const ch = Cast<AAPI_ProjectCharacter>(OtherActor))
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Purple, TEXT("Key Hit"));
	}
}

