// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CollapsingWall.generated.h"

UCLASS()
class UNREALMEGAJAM_API ACollapsingWall : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACollapsingWall();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FTransform StartingPoint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FTransform TargetPoint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Speed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 DamagePower;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USceneComponent* MyRootComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* WallModel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* DestinationMarker;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
