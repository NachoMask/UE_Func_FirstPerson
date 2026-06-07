// Fill out your copyright notice in the Description page of Project Settings.


#include "FP_Character.h"

#include "Camera\CameraComponent.h"
#include "Interface\FP_InteractableInterface.h"

// Sets default values
AFP_Character::AFP_Character()
{
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComponent->SetupAttachment(RootComponent);
	CameraComponent->bUsePawnControlRotation = true;
}

void AFP_Character::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	UpdateCameraFocus();
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

void AFP_Character::InteractAction()
{
	if (FocusedActor)
	{
		if (IFP_InteractableInterface* Interactable = Cast<IFP_InteractableInterface>(FocusedActor))
		{
			Interactable->Interact();
		}
	}
}

void AFP_Character::UpdateCameraFocus()
{
	FVector Start = CameraComponent->GetComponentLocation();
	FRotator Rot = CameraComponent->GetComponentRotation();
	FVector End = Start + (Rot.Vector() * CameraFocusDistance);

	FHitResult Result;
	FCollisionQueryParams Param;

	bool bHit = GetWorld()->LineTraceSingleByChannel(OUT Result,
		Start, End, ECollisionChannel::ECC_Visibility, Param);
	
	ChangeFocusedActor(Result.GetActor());

#if ENABLE_DRAW_DEBUG
	DrawDebugLine(GetWorld(), Start, End, FColor::Green, false, 1.f);
#endif
}

void AFP_Character::ChangeFocusedActor(AActor* NewActor)
{
	if (NewActor == nullptr)
	{
		if (IFP_InteractableInterface* OldFocused = Cast<IFP_InteractableInterface>(FocusedActor))
		{
			OldFocused->HideOutline();
		}
	}
	else if (FocusedActor != NewActor)
	{
		if (IFP_InteractableInterface* OldFocused = Cast<IFP_InteractableInterface>(FocusedActor))
		{
			OldFocused->HideOutline();
		}

		if (IFP_InteractableInterface* NewFocused = Cast<IFP_InteractableInterface>(NewActor))
		{
			NewFocused->ShowOutline();
		}
	}

	FocusedActor = NewActor;
}
