// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}


struct start :public FVector2D {
	

	float ddistance;
	int count=0;

	float distance(FVector2D first, FVector2D second)
	{
		float dx = first.X - second.X;
		float dy = first.Y - second.Y;
		return FMath::Sqrt(dx * dx + dy * dy);
	}

	void TriggerEventWithProbability(float Probability)
	{
		int32 RandomValue = FMath::RandRange(1, 100); // 1 ~ 100의 난수 생성
		if (RandomValue <= Probability)
		{
			UE_LOG(LogTemp, Error, TEXT("Event Triggered! ##One More Step##"));
			count--;
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("Event Not Triggered"));
		}
	}

	void step() {

		FVector2D first(X, Y);
		
		X += FMath::RandRange(0, 1);
		Y += FMath::RandRange(0, 1);
		FVector2D second(X,Y);
		ddistance=distance(first, second);
		TriggerEventWithProbability(50);

	}

	void move() {
		for (count = 0; count < 10; count++) {

			
			step();
			
		

			UE_LOG(LogTemp, Warning, TEXT("X:%f Y:%f"),X,Y);
			UE_LOG(LogTemp, Display, TEXT("distance:%f"), ddistance);
		}
		}

	


	
};



// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Hello2"));
	
	struct start s;
	s.move();
	
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

