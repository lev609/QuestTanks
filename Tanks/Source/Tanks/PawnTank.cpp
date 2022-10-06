// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnTank.h"
#include "Components/BoxComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values
APawnTank::APawnTank()
{
	PrimaryActorTick.bCanEverTick = true;

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	RootComponent = BoxCollision;

	BodyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BodyMesh"));
	BodyMesh->SetupAttachment(BoxCollision);

	TurretMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TurretMesh"));
	TurretMesh->SetupAttachment(BodyMesh);

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(BoxCollision);
	SpringArm->bDoCollisionTest = false;
	SpringArm->bInheritPitch = false;
	SpringArm->bInheritRoll = false;
	SpringArm->bInheritYaw = false;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);
}

void APawnTank::BeginPlay()
{
	Super::BeginPlay();
	
}

void APawnTank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//MoveForward
	FVector CurrentLocation = GetActorLocation(); //Позиция игрока
	FVector ForwardVector = GetActorForwardVector(); 
	FVector MovePosition = CurrentLocation + ForwardVector * MovementSpeed * ForwardMoveAxisValue * DeltaTime;
	SetActorLocation(MovePosition);

	FVector CurrentLocation2 = GetActorLocation();
	FVector RightVector = GetActorRightVector();
	FVector MovePosition2 = CurrentLocation2 + RightVector * RightSpeed * RightMoveAxisValue * DeltaTime;
	SetActorLocation(MovePosition2);
}



void APawnTank::MoveForward(float Value)
{
	ForwardMoveAxisValue = Value;
}

void APawnTank::MoveRight(float Value)
{
	RightMoveAxisValue = Value;
}

