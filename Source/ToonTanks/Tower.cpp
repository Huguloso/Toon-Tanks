// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower.h"
#include "Tank.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"

void ATower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Tank)
	{
		FVector TankLocation = Tank->GetActorLocation();
		if (IsInFireRange())
		{
			RotateTurret(TankLocation);
		}
	}
}

void ATower::HandleDestruction()
{
	Super::HandleDestruction();

	Destroy();
}

void ATower::BeginPlay()
{
	Super::BeginPlay();
	Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));

	GetWorldTimerManager().SetTimer(FireRateTimerHandle, this, &ATower::CheckFireCondition, FireRate, true);
}

void ATower::CheckFireCondition()
{
	if (IsInFireRange() && Tank->GetIsAlive())
	{
		Fire();
	}
}

bool ATower::IsInFireRange()
{
	if (Tank)
	{
		float Distance = FVector::Dist(GetActorLocation(), Tank->GetActorLocation());
		return Distance <= FireRange;
	}

	return false;
}
