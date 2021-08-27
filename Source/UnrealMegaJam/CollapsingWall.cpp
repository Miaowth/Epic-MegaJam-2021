// Fill out your copyright notice in the Description page of Project Settings.


#include "CollapsingWall.h"

// Sets default values
ACollapsingWall::ACollapsingWall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MyRootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root Component"));

	MyRootComponent->SetupAttachment(RootComponent);

	WallModel = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Wall Model"));
	WallModel->SetupAttachment(MyRootComponent);

	DestinationMarker = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Destination Marker"));
	DestinationMarker->SetupAttachment(MyRootComponent);
}

// Called when the game starts or when spawned
void ACollapsingWall::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACollapsingWall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

