// Fill out your copyright notice in the Description page of Project Settings.


#include "FP_InteractableActor.h"

AFP_InteractableActor::AFP_InteractableActor()
{
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);
}

void AFP_InteractableActor::ShowOutline()
{
	GEngine->AddOnScreenDebugMessage(-1, 0.5f, FColor::Yellow, TEXT("Show Outline"));
}

void AFP_InteractableActor::HideOutline()
{
	GEngine->AddOnScreenDebugMessage(-1, 0.5f, FColor::Red, TEXT("Hide Outline"));
}

void AFP_InteractableActor::Interact()
{
	GEngine->AddOnScreenDebugMessage(-1, 0.5f, FColor::Green, TEXT("Interact"));
}