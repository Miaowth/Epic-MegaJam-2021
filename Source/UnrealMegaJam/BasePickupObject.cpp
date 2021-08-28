// Fill out your copyright notice in the Description page of Project Settings.

#include "Engine/EngineTypes.h"
#include "BasePickupObject.h"

// Sets default values
ABasePickupObject::ABasePickupObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MyRootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root Component"));

	MyRootComponent->SetupAttachment(RootComponent);

	ObjectMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Object Model"));
	ObjectMesh->SetupAttachment(MyRootComponent);
	ObjectMesh->SetSimulatePhysics(true);
	//ObjectMesh->SetMobility(EComponentMobility::Movable);
}

// Called when the game starts or when spawned
void ABasePickupObject::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABasePickupObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

