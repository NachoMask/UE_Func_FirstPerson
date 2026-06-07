// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FP_Character.generated.h"

class UCameraComponent;

UCLASS()
class FUNC_FIRSTPERSON_API AFP_Character : public ACharacter
{
	GENERATED_BODY()

public:
	AFP_Character();

protected:
	virtual void Tick(float DeltaSeconds);

public:
	/** Input Action */
	void MoveAction(FVector2D Value);
	void CameraAction(FVector2D Value);
	void InteractAction();

protected:
	void UpdateCameraFocus();
	void ChangeFocusedActor(AActor* NewActor);

protected:
	UPROPERTY(VisibleAnywhere, Category = "FP|Comp")
	TObjectPtr<UCameraComponent> CameraComponent;

	/** Interact */
	UPROPERTY(VisibleAnywhere, Category = "FP|Interact")
	TObjectPtr<AActor> FocusedActor = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "FP|Interact")
	float CameraFocusDistance = 200.f;
};
