// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Components/TimelineComponent.h"
#include "DoorBase.generated.h"

UCLASS()
class TGPPUZZLE_API ADoorBase : public AActor
{
	GENERATED_BODY()

	UPROPERTY(VisibleDefaultsOnly, Category = "Door")
		UBoxComponent* DoorCollision;
	 
	


public:	
	// Sets default values for this actor's properties
	ADoorBase();

	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* Door1Mesh;

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* Door2Mesh;

	UPROPERTY(EditAnywhere)
		UCurveFloat* DoorCurve;
	
	UFUNCTION()
		void ControlDoor();

	UFUNCTION()
		void ToggleDoor();

	UFUNCTION()
		void SetState();

	
		bool IsOpen;
		bool ReadyState;
		float RotateValue;
		float CurveFloatValue;
		float TimelineValue;
		FRotator DoorRotation;
		FTimeline MyTimeline;

};

