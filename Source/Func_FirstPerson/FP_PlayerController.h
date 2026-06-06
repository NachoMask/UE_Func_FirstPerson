// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "FP_PlayerController.generated.h"

class UInputMappingContext;
class AFP_Character;

UCLASS()
class FUNC_FIRSTPERSON_API AFP_PlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	virtual void OnPossess(APawn* aPawn) override;
	virtual void SetupInputComponent() override;

protected:
	/** Input & Key Binding */
	void BindActions(UInputMappingContext* Context);
	void SetupInputs(UInputMappingContext* Context);
	
	/** Input Actions */
	UFUNCTION()
	void MoveAction(const FInputActionValue& Value);

	UFUNCTION()
	void CameraAction(const FInputActionValue& Value);

protected:
	UPROPERTY(VisibleAnywhere, Category = "FP")
	TObjectPtr<AFP_Character> PossessedCharacter = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "FP|IMC")
	TObjectPtr<UInputMappingContext> MoveIMC = nullptr;
};
