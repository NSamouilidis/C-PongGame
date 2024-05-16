// Fill out your copyright notice in the Description page of Project Settings.


#include "PongBall.h"
#include "PaperSpriteComponent.h"
#include "Components/BoxComponent.h"
#include "Components/PrimitiveComponent.h"




// Sets default values
APongBall::APongBall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MySprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("My Image"));
	RootComponent = MySprite;
	MyCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("Ball Hit Box"));
	MyCollider->SetBoxExtent(FVector(32, 32, 32));
	MyCollider->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	MyCollider->SetupAttachment(RootComponent);
		
}

// Called when the game starts or when spawned
void APongBall::BeginPlay()
{
	Super::BeginPlay();

	MyVelocity = FVector(300, 0, 300);

	HalfPlayFieldHeight = (2048.0f / 1.777) / 2.0f;
	HalfPlayFieldWidth = (2048.0f / 2.0f);

	MyCollider->OnComponentBeginOverlap.AddDynamic(this, &APongBall::OnCollision);
	
}

// Called every frame
void APongBall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector MyUpdatedLcation = GetActorLocation() + (MyVelocity * DeltaTime);

if (MyUpdatedLcation.Z > HalfPlayFieldHeight)
	{
		MyVelocity.Z = -2.0f;
	}
	else if (MyUpdatedLcation.Z < -HalfPlayFieldHeight)
	{
		MyVelocity.Z = 2.0f;
	}

	if (MyUpdatedLcation.X > HalfPlayFieldWidth)
{
		MyVelocity.X = -2.0f;
	}

	else if (MyUpdatedLcation.X < -HalfPlayFieldWidth)
	{
		MyVelocity.X = 2.0f;
	}
	SetActorLocation(GetActorLocation() + MyVelocity);
	
	

}

void APongBall::OnCollision(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("I HIT SOMETHING"));
	FVector BatPosition = GetActorLocation();
	if (BatPosition.X > 0)
	{
		MyVelocity.X = -3.0f;
	}
	else if (BatPosition.X < 0)
	{
		MyVelocity.X = 3.0f;

	}
}