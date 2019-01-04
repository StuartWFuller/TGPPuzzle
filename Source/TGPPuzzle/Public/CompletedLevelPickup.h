// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "CompletedLevelPickup.generated.h"

UCLASS()
class TGPPUZZLE_API ACompletedLevelPickup : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACompletedLevelPickup();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, Category = "Components")
		class USphereComponent* SphereComp;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void NotifyActorBeginOverlap(AActor * OtherActor);

	void NotifyActorEndOverlap(AActor * OtherActor);

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "OverlappingActor")
		AActor* OverlappingActor;

	void SwapLevel();
	
};
