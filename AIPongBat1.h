// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePongBat.h"
#include "AIPongBat1.generated.h"

/**
 * 
 */
UCLASS()
class PONG_API AAIPongBat1 : public ABasePongBat
{
	GENERATED_BODY()
private:
	UPROPERTY(VisibleAnywhere, Category = "ReferencedActor")
	class AActor* TheBall;

public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	
	
};
