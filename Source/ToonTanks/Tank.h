// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tank.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATank : public ABasePawn
{
	GENERATED_BODY()
public:
	ATank();

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void Tick(float DeltaTime) override;

	void HandleDestruction();

	APlayerController* GetTankPlayerController() const { return TankPlayerController; }
	bool GetIsAlive() const { return Alive; }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private: 
	UPROPERTY(VisibleAnywhere, Category="Components")
	class USpringArmComponent* SpringArm;
	UPROPERTY(VisibleAnywhere, Category = "Components")
	class UCameraComponent* Camera;

	APlayerController* TankPlayerController;

	UPROPERTY(EditAnywhere, Category = "Movement")
	int Speed = 500;
	UPROPERTY(EditAnywhere, Category = "Movement")
	int TurnSpeed = 180;

	bool Alive = true;

	void Move(float value);
	void Turn(float value);
};
