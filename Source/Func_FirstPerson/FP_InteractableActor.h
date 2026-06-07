// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Interface\FP_InteractableInterface.h"

#include "FP_InteractableActor.generated.h"

UCLASS()
class FUNC_FIRSTPERSON_API AFP_InteractableActor : public AActor, public IFP_InteractableInterface
{
	GENERATED_BODY()
	
public:	
	AFP_InteractableActor();

public:
	void ShowOutline() override;

	void HideOutline() override;

	void Interact() override;

protected:
	UPROPERTY(VisibleAnywhere, Category = "FP|Mesh")
	TObjectPtr<UStaticMeshComponent> Mesh;
};
