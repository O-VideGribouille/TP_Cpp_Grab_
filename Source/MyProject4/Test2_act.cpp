// Fill out your copyright notice in the Description page of Project Settings.


#include "Test2_act.h" //equivaut au MyActore.h



// Sets default values
ATest2_act::ATest2_act()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	active = true;

}

// Called when the game starts or when spawned
void ATest2_act::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATest2_act::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

