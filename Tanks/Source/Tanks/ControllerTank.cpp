// Fill out your copyright notice in the Description page of Project Settings.


#include "ControllerTank.h"
#include "PawnTank.h"

void AControllerTank::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);
	TankPawn = Cast<APawnTank>(InPawn);
}

void AControllerTank::SetupInputComponent()
{
	Super::SetupInputComponent();
	InputComponent->BindAxis("MoveForward", this, &AControllerTank::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AControllerTank::MoveRight);
}

void AControllerTank::MoveForward(float Value)
{
	if (TankPawn)
	{
		TankPawn->MoveForward(Value);
	}
}

void AControllerTank::MoveRight(float Value)
{
	if (TankPawn)
	{
		TankPawn->MoveRight(Value);
	}
}
