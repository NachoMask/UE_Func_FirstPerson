// Fill out your copyright notice in the Description page of Project Settings.


#include "FP_Character.h"

#include "Camera\CameraComponent.h"

// Sets default values
AFP_Character::AFP_Character()
{
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComponent->SetupAttachment(RootComponent);
	CameraComponent->bUsePawnControlRotation = true;
}

void AFP_Character::MoveAction(FVector2D Value)
{
	float Forward = Value.Y;
	float Right = Value.X;

	AddMovementInput(GetActorForwardVector(), Forward);
	AddMovementInput(GetActorRightVector(), Right);
}

void AFP_Character::CameraAction(FVector2D Value)
{
	float Right = Value.X;
	float Up = Value.Y;

	AddControllerYawInput(Right);
	AddControllerPitchInput(Up);
}