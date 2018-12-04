// Fill out your copyright notice in the Description page of Project Settings.

#include "DoorBase.h"
#include "Engine/GameEngine.h"


// Sets default values
ADoorBase::ADoorBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	IsOpen = false;
	ReadyState = true;

	DoorCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("DoorCollisionComp"));
	RootComponent = DoorCollision;

	Door1Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Door1Mesh"));
	Door1Mesh->SetupAttachment(RootComponent);

	Door2Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Door2Mesh"));
	Door2Mesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ADoorBase::BeginPlay()
{
	Super::BeginPlay();

	RotateValue = 1.0f;

	if (DoorCurve)
	{
		FOnTimelineFloat TimelineCallback;
		FOnTimelineEventStatic TimelineFinishedCallback;

		TimelineCallback.BindUFunction(this, FName("ControlDoor"));
		TimelineFinishedCallback.BindUFunction(this, FName("SetState"));

		MyTimeline.AddInterpFloat(DoorCurve, TimelineCallback);
		MyTimeline.SetTimelineFinishedFunc(TimelineFinishedCallback);
	}
	
}

// Called every frame
void ADoorBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MyTimeline.TickTimeline(DeltaTime);

}

void ADoorBase::ControlDoor()
{
	
	TimelineValue = MyTimeline.GetPlaybackPosition();
	CurveFloatValue = RotateValue * DoorCurve->GetFloatValue(TimelineValue);

	FQuat NewRotation = FQuat(FRotator(0.0f, CurveFloatValue, 0.0f));

	Door1Mesh->SetRelativeRotation(NewRotation);
	Door2Mesh->SetRelativeRotation(NewRotation);
}

void ADoorBase::SetState()
{
	ReadyState = true;
}

void ADoorBase::ToggleDoor()
{
	if (ReadyState)
	{
		
		IsOpen = !IsOpen;
	
		if (IsOpen)
		{
			
			RotateValue = 1.0f;
			ReadyState = false;
			MyTimeline.PlayFromStart();
		}
	}
}