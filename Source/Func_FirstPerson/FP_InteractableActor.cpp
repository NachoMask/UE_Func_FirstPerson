// Fill out your copyright notice in the Description page of Project Settings.


#include "FP_InteractableActor.h"

AFP_InteractableActor::AFP_InteractableActor()
{
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);
}

void AFP_InteractableActor::ShowOutline()
{
}

void AFP_InteractableActor::HideOutline()
{
}

void AFP_InteractableActor::Interact()
{
	GEngine->AddOnScreenDebugMessage(-1, 0.5f, FColor::Green, TEXT("Interact"));
}