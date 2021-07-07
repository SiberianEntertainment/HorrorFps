// Fill out your copyright notice in the Description page of Project Settings.


#include "Assault.h"
#include "Camera/CameraComponent.h"
#include "Camera/CameraShakeSourceComponent.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"

// Sets default values
AAssault::AAssault()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//Camera Setup
	FirstPersonCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("First Person Camera"));
	CameraShake = CreateDefaultSubobject<UCameraShakeSourceComponent>(TEXT("Camera Shake"));
	FirstPersonCamera->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	FirstPersonCamera->SetRelativeLocation(FVector(30.0f, 0.0f, 60.0f));
}

// Called when the game starts or when spawned
void AAssault::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AAssault::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

// Called to bind functionality to input
void AAssault::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &AAssault::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &AAssault::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("LookX"), this, &AAssault::LookX);
	PlayerInputComponent->BindAxis(TEXT("LookY"), this, &AAssault::LookY);
	PlayerInputComponent->BindAction(TEXT("Jump"), IE_Pressed, this, &AAssault::Jump);

}

//Movement Functions
void AAssault::MoveForward(float value) 
{
	ForLoc = AAssault::GetActorForwardVector();
	AddMovementInput(ForLoc, value, false);
}

void AAssault::MoveRight(float value)
{
	RigLoc = AAssault::GetActorRightVector();
	AddMovementInput(RigLoc, value, false);
}

void AAssault::LookX(float value)
{
	AddControllerYawInput(value);
}

void AAssault::LookY(float value)
{
	AddControllerPitchInput(value);
}

void AAssault::JumpFunction()
{
	Jump();
}
