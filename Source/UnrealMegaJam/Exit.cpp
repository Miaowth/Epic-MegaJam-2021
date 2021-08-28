// Fill out your copyright notice in the Description page of Project Settings.


#include "Exit.h"

// Sets default values
AExit::AExit()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MyRootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root Component"));

	MyRootComponent->SetupAttachment(RootComponent);

	ExitModel = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Exit Model"));
	ExitModel->SetupAttachment(MyRootComponent);
}

// Called when the game starts or when spawned
void AExit::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AExit::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

