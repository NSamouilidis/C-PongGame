// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePongBat.h"
#include "PaperSpriteComponent.h"
#include "Components/BoxComponent.h"



// Sets default values
ABasePongBat::ABasePongBat()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MySprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("My Image"));
	RootComponent = MySprite;
	MyCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("Ball Hit Box"));
	MyCollider->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	MyCollider->SetBoxExtent(FVector(64, 32, 128));
	MyCollider->SetupAttachment(RootComponent);


}

// Called when the game starts or when spawned
void ABasePongBat::BeginPlay()
{
	Super::BeginPlay();

	MyCollider->SetBoxExtent(MySprite->Bounds.GetBox().GetSize());
	
}

// Called every frame
void ABasePongBat::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABasePongBat::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

