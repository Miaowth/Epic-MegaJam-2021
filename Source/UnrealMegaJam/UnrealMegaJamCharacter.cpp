//Copyright Epic Games, Inc. All Rights Reserved.

#include "UnrealMegaJamCharacter.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"

////////////////////////////////////////////////////////////////////////
//AUnrealMegaJamCharacter

AUnrealMegaJamCharacter::AUnrealMegaJamCharacter()
{
	//Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);


	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;
	
	//	 //Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	//	 //are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)
}

void AUnrealMegaJamCharacter::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}
void AUnrealMegaJamCharacter::Jump()
{
}

void AUnrealMegaJamCharacter::StopJumping()
{
}