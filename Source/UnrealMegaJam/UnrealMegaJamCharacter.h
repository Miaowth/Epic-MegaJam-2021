//Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CameraPawn.h"

#include "UnrealMegaJamCharacter.generated.h"

UCLASS(config=Game)
class AUnrealMegaJamCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AUnrealMegaJamCharacter();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		ACameraPawn* CameraReference;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool IsHolding = false;

protected:

public:
	virtual void Tick(float DeltaTime) override;
	virtual void BeginPlay() override;
	//void Jump();
	//void StopJumping();

	UFUNCTION(BlueprintNativeEvent)
		void Pickup();
};

