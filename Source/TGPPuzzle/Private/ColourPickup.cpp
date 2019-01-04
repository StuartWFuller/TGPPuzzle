// Fill out your copyright notice in the Description page of Project Settings.

#include "ColourPickup.h"


// Sets default values
AColourPickup::AColourPickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));

}

// Called when the game starts or when spawned
void AColourPickup::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AColourPickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AColourPickup::NotifyActorBeginOverlap(AActor * OtherActor)
{
	OnActivate(OtherActor);
}