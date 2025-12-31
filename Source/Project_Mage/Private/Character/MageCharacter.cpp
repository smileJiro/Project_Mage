// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/MageCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

AMageCharacter::AMageCharacter()
{
	
	UCharacterMovementComponent* Movement = GetCharacterMovement();
	Movement->bOrientRotationToMovement = true;
	Movement->RotationRate = FRotator(0.f, 500.f, 0.f);
	Movement->bConstrainToPlane = true;
	Movement->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
}
