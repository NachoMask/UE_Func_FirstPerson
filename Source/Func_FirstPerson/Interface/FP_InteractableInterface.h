// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "FP_InteractableInterface.generated.h"

UINTERFACE(MinimalAPI)
class UFP_InteractableInterface : public UInterface
{
	GENERATED_BODY()
};

class FUNC_FIRSTPERSON_API IFP_InteractableInterface
{
	GENERATED_BODY()

public:
	virtual void ShowOutline() = 0;
	virtual void HideOutline() = 0;
	virtual void Interact() = 0;
};
