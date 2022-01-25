// Fill out your copyright notice in the Description page of Project Settings.


#include "Grabber.h"
#include "DrawDebugHelpers.h"
#include "GameFramework/Actor.h"


// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...

	flt_Distance = 500;
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	// ...

	PHC_T = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
	
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...

	if (PHC_T)
	{
		if (PHC_T->GrabbedComponent)
		{
			PHC_T->SetTargetLocation(FV_returnEnd());
		}
	}
}

void UGrabber::Grab()
{
	UE_LOG(LogTemp, Warning, TEXT("GRAB"));
	//FVector Start = GetOwner()->GetActorLocation();
	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;

	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(OUT PlayerViewPointLocation, OUT PlayerViewPointRotation);
	FVector Start = PlayerViewPointLocation;
	FVector End = FV_returnEnd();


	DrawDebugLine(GetWorld(), Start, End, FColor::Blue, false, 2.0, 0, 10);

	FHitResult Hit;
	FCollisionQueryParams TraceParams(FName(TEXT("")), false, GetOwner());

	GetWorld()->LineTraceSingleByObjectType(Hit, Start, End, ECollisionChannel::ECC_PhysicsBody, TraceParams);

	AActor* ActorCollision = Hit.GetActor();

	if (ActorCollision)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s"), *ActorCollision->GetName());
		
		if (PHC_T)
		{
			PHC_T->GrabComponentAtLocation(Hit.GetComponent(), NAME_None, End);
		}
		
	}

	
}

void UGrabber::Release()
{
	UE_LOG(LogTemp, Warning, TEXT("RELEASE"));

	if (PHC_T)
	{
		PHC_T->ReleaseComponent();
	}
}

FVector UGrabber::FV_returnEnd()
{
	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;

	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(OUT PlayerViewPointLocation, OUT PlayerViewPointRotation);

	return PlayerViewPointLocation + PlayerViewPointRotation.Vector() * flt_Distance;
	//return GetOwner()->GetActorForwardVector() * flt_Distance + GetOwner()->GetActorLocation();
}

