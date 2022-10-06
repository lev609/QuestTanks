// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ControllerTank.generated.h"

/**
 * 
 */
UCLASS()
class TANKS_API AControllerTank : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void SetPawn(APawn* InPawn) override;

protected:
	virtual void SetupInputComponent() override;

private:
	class APawnTank* TankPawn;

	void MoveForward(float Value);

	void MoveRight(float Value);
};
