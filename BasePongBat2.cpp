// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePongBat2.h"

#include "Math/UnitConversion.h"

void ABasePongBat2::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	InputComponent->BindAxis("Vertical", this, &ABasePongBat2::MovePlayer);
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ABasePongBat2::MovePlayer(float input)
{
	SetActorLocation(GetActorLocation() + FVector(0, 0, 1*input));

}