// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "UnrealMegaJamCharacter.h"

#include "MyPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class UNREALMEGAJAM_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()
	
	AMyPlayerController();

	UPROPERTY(EditAnywhere)
	AUnrealMegaJamCharacter* PlayerCharacter;
private:

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, Category = Camera)
		float BaseTurnRate = 45.f;

	/** Turn rate for left stick navigation. */
	UPROPERTY(VisibleAnywhere, Category = Camera)
		float AutoTurnRate = 22.5f;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, Category = Camera)
		float BaseLookUpRate = 45.f;

	virtual void Tick(float DeltaSeconds) override;

	//Setting up the camera possession
	UFUNCTION(BlueprintCallable)
		virtual void OnPossess(APawn* InPawn) override;

	//DEFAULT INPUTS
	virtual void SetupInputComponent() override;

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	/**
	* Called via input to turn at a given rate.
	* @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	*/
	void TurnAtRate(float Rate);

	/**
	* Called via input to turn look up/down at a given rate.
	* @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	*/
	void LookUpAtRate(float Rate);

	/**
	 *Does Jump
	 *
	 */
	void Jump();

	/**
	 *Stops Jump
	 *
	 */
	void StopJumping();

	FVector2D MoveDir;

	void Pickup();
	void Pause();

protected:
	//END DEFAULT INPUTS


};
