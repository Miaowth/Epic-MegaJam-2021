// Fill out your copyright notice in the Description page of Project Settings.

#include "MyPlayerController.h"

AMyPlayerController::AMyPlayerController()
{
	SetTickableWhenPaused(true);
}

void AMyPlayerController::OnPossess(APawn* InPawn) {
	Super::OnPossess(InPawn);
	if (InPawn->IsA(AUnrealMegaJamCharacter::StaticClass())) {
		PlayerCharacter = Cast<AUnrealMegaJamCharacter>(InPawn);
	}

}

void AMyPlayerController::Tick(float DeltaSeconds) {

}
///////////////////////////INPUT/////////////////////////////////////

void AMyPlayerController::SetupInputComponent()
{
	// Set up gameplay key bindings
	Super::SetupInputComponent();
	InputComponent->BindAction("Jump", IE_Pressed, this, &AMyPlayerController::Jump);
	InputComponent->BindAction("Jump", IE_Released, this, &AMyPlayerController::StopJumping);

	InputComponent->BindAxis("MoveForward", this, &AMyPlayerController::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AMyPlayerController::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	InputComponent->BindAxis("Turn", this, &APlayerController::AddYawInput);
	InputComponent->BindAxis("TurnRate", this, &AMyPlayerController::TurnAtRate);
	InputComponent->BindAxis("LookUp", this, &APlayerController::AddPitchInput);
	InputComponent->BindAxis("LookUpRate", this, &AMyPlayerController::LookUpAtRate);

}

void AMyPlayerController::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	if (PlayerCharacter) {
		AddYawInput((FMath::Pow(Rate, 2) * FMath::Sign(Rate)) * BaseTurnRate * GetWorld()->GetDeltaSeconds());
	}
}

void AMyPlayerController::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	if (PlayerCharacter) {
		AddPitchInput((FMath::Pow(Rate, 2) * FMath::Sign(Rate)) * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
	}
}

void AMyPlayerController::MoveForward(float Value)
{
	if (PlayerCharacter)
	{
		MoveDir.Y = Value;
		if (Value != 0.0f)
		{
			// find out which way is forward
			const FRotator Rotation = GetControlRotation();
			const FRotator YawRotation(0, Rotation.Yaw, 0);

			// get forward vector
			const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
			PlayerCharacter->AddMovementInput(Direction, Value);
		}
	}
}

void AMyPlayerController::MoveRight(float Value)
{
	if (PlayerCharacter)
	{
		MoveDir.X = Value;
		if (Value != 0.0f)
		{
			// find out which way is right
			const FRotator Rotation = GetControlRotation();
			const FRotator YawRotation(0, Rotation.Yaw, 0);

			// get right vector 
			const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
			// add movement in that direction
			PlayerCharacter->AddMovementInput(Direction, Value);

			//Do Turning for left stick movement
			AddYawInput((FMath::Pow(Value, 2) * FMath::Sign(Value)) * AutoTurnRate * GetWorld()->GetDeltaSeconds());

		}
	}
}

void AMyPlayerController::Jump()
{
	if (PlayerCharacter)
	{
		PlayerCharacter->Jump();
	}
}

void AMyPlayerController::StopJumping()
{
	if (PlayerCharacter)
	{
		PlayerCharacter->StopJumping();
	}
}