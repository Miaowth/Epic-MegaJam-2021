// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BasePickupObject.generated.h"

UCLASS()
class UNREALMEGAJAM_API ABasePickupObject : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABasePickupObject();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USceneComponent* MyRootComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* ObjectMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsHeld;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Health = 10;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
