//Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "UnrealMegaJamCharacter.generated.h"

UCLASS(config=Game)
class AUnrealMegaJamCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AUnrealMegaJamCharacter();

	void Jump();
	void StopJumping();

protected:

public:
	virtual void Tick(float DeltaTime) override;
};

