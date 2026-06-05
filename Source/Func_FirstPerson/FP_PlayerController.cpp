// Fill out your copyright notice in the Description page of Project Settings.


#include "FP_PlayerController.h"

#include "InputMappingContext.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "FP_Character.h"

void AFP_PlayerController::OnPossess(APawn* aPawn)
{
	Super::OnPossess(aPawn);

	PossessedCharacter = Cast<AFP_Character>(aPawn);

	SetupInputs(MoveIMC);
}

void AFP_PlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);
	if (EnhancedInputComponent)
	{
		EnhancedInputComponent->ClearActionBindings();

		BindActions(MoveIMC);
	}
}

void AFP_PlayerController::BindActions(UInputMappingContext* Context)
{
	check(Context);

	const TArray<FEnhancedActionKeyMapping>& Mappings = Context->GetMappings();

	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);
	if (EnhancedInputComponent)
	{
		TSet<const UInputAction*> UniqueActions;
		for (const FEnhancedActionKeyMapping& Mapping : Mappings)
		{
			UniqueActions.Add(Mapping.Action);
		}

		for (const UInputAction* Action : UniqueActions)
		{
			EnhancedInputComponent->BindAction(
				Action,
				ETriggerEvent::Triggered,
				Cast<UObject>(this),
				Action->GetFName());
		}
	}
}

void AFP_PlayerController::SetupInputs(UInputMappingContext* Context)
{
	check(Context);
	
	if (PossessedCharacter)
	{
		UEnhancedInputLocalPlayerSubsystem* Subsystem
			= ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());

		if (Subsystem)
		{
			Subsystem->ClearAllMappings();

			FModifyContextOptions Options;
			Options.bForceImmediately = 1;

			Subsystem->AddMappingContext(Context, 0, Options);
		}
	}
}

void AFP_PlayerController::MoveAction(const FInputActionValue& Value)
{
	if (PossessedCharacter)
	{
		PossessedCharacter->MoveAction(Value.Get<FVector2D>());
	}
}

void AFP_PlayerController::CameraAction(const FInputActionValue& Value)
{
	if (PossessedCharacter)
	{
		PossessedCharacter->CameraAction(Value.Get<FVector2D>());
	}
}
