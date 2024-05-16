// Fill out your copyright notice in the Description page of Project Settings.


#include "AIPongBat1.h"

#include "PongBall.h"
#include "Kismet/GameplayStatics.h"

void AAIPongBat1::BeginPlay()
{
	Super::BeginPlay();
	TheBall = UGameplayStatics::GetActorOfClass(GetWorld(), APongBall::StaticClass());

}

void AAIPongBat1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetActorLocation().Z > TheBall->GetActorLocation().Z)
	{
		SetActorLocation(GetActorLocation() +FVector(0, 0, -1));
	}
	if (GetActorLocation().Z < TheBall->GetActorLocation().Z)
	{
		SetActorLocation(GetActorLocation() +FVector(0, 0, 1));
	}
}

