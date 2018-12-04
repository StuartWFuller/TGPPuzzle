// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DoorBase.h"
#include "SwitchBase.generated.h"

class USphereComponent;
UCLASS()
class TGPPUZZLE_API ASwitchBase : public AActor
{
	
	GENERATED_BODY()
	
	
public:	
	// Sets default values for this actor's properties
	ASwitchBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	USphereComponent* SphereComp;



public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void NotifyActorBeginOverlap(AActor * OtherActor);

	void NotifyActorEndOverlap(AActor * OtherActor);

	UFUNCTION(BlueprintImplementableEvent, Category = "Pickup")
	void OnActivate(AActor* collidedActor);

	UFUNCTION(BlueprintImplementableEvent, Category = "Pickup")
	void OnDeactivate(AActor* collidedActor);

	UFUNCTION(BlueprintImplementableEvent, Category = "Interact")
	void Interact();

	UFUNCTION(BlueprintCallable)
	void OnInteract(AActor* OtherActor);

	ADoorBase* _door;
};
