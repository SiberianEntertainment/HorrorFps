// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Assault.generated.h"

UCLASS()
class HORRORFPS_API AAssault : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAssault();
	FVector ForLoc;
	FVector RigLoc;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera") 
		class UCameraComponent* FirstPersonCamera;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
		class UCameraShakeSourceComponent* CameraShake;
;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	//Control Functions Definition
	UFUNCTION()
		void MoveForward(float value);
	UFUNCTION()
		void MoveRight(float value);
	UFUNCTION()
		void LookX(float value);
	UFUNCTION()
		void LookY(float value);
	UFUNCTION()
		void JumpFunction();
};
