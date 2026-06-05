// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FP_Character.generated.h"

UCLASS()
class FUNC_FIRSTPERSON_API AFP_Character : public ACharacter
{
	GENERATED_BODY()

public:
	AFP_Character();

public:
	/** Input Action */
	void MoveAction(FVector2D Value);
};
