// Fill out your copyright notice in the Description page of Project Settings.


#include "CompletedLevelPickup.h"
#include "Engine/GameEngine.h"



// Sets default values
ACompletedLevelPickup::ACompletedLevelPickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));


}

// Called when the game starts or when spawned
void ACompletedLevelPickup::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACompletedLevelPickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//void NotifyActorBeginOverlap(AActor * OtherActor)
//{
//	/*OverlappingActor;
//
//	if (OverlappedActor != NULL)
//	{
//		if (GEngine)
//		{
//			GEngine->AddOnScreenDebugMessage(-1, 4.0f, FColor::Red, TEXT("YOOO"));
//		}
//	}*/
//
//
//}
//
//void NotifyActorEndOverlap(AActor * OtherActor)
//{
//
//}
