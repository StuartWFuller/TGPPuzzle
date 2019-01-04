// Fill out your copyright notice in the Description page of Project Settings.


#include "CompletedLevelPickup.h"
#include "Engine/GameEngine.h"
#include "Kismet/GameplayStatics.h"



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

void ACompletedLevelPickup::NotifyActorBeginOverlap(AActor * OtherActor)
{
	OverlappingActor = OtherActor;

	if (OverlappingActor != NULL)
	{
		/*if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 4.0f, FColor::Red, TEXT("YOOO"));*/
			SwapLevel();
		/*}*/
	}


}

void ACompletedLevelPickup::NotifyActorEndOverlap(AActor * OtherActor)
{

}

void ACompletedLevelPickup::SwapLevel()
{

	UWorld* TheWorld = GetWorld();
	FString CurrentLevel = TheWorld->GetMapName();

	/*GEngine->AddOnScreenDebugMessage(-1, 4.0f, FColor::Green, CurrentLevel);*/

	if (CurrentLevel == "UEDPIE_0_ThirdPersonExampleMap")
	{
		UGameplayStatics::OpenLevel(this, "2ndLevel");
	}

	if (CurrentLevel == "UEDPIE_0_2ndLevel")
	{
		UGameplayStatics::OpenLevel(this, "3rdLevel");
	}
	
	if (CurrentLevel == "UEDPIE_0_3rdLevel")
	{
		UGameplayStatics::OpenLevel(this, "4thLevel");
	}

	if (CurrentLevel == "UEDPIE_0_4thLevel")
	{
		UGameplayStatics::OpenLevel(this, "Finish");
	}
	
	
}
