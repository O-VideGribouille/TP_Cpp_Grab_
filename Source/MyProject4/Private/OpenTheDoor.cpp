// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/PrimitiveComponent.h"
#include "OpenTheDoor.h"


// Sets default values for this component's properties
UOpenTheDoor::UOpenTheDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenTheDoor::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UOpenTheDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	if(Atggr_Trigger) {

		/*for each (object var in collection_to_loop)
		{*/

		float flt_TMass = flt_GetToMass();

		UE_LOG(LogTemp, Warning, TEXT("%d"), flt_MaxMass);

			if(flt_TMass >= flt_MaxMass) {

				OpenDoor();
			}
			else
			{
				Closedoor();
			}

		//}
	}
	
}

void UOpenTheDoor::OpenDoor()
{
	OpenDoorRequest.Broadcast();
}

void UOpenTheDoor::Closedoor()
{
	CloseDoorRequest.Broadcast();
}

float UOpenTheDoor::flt_GetToMass()
{
	
	float flt_TMass = 0.0f;

	TArray<AActor*> ActorCollision;
	Atggr_Trigger->GetOverlappingActors(ActorCollision);
	
	for (AActor* Actor : ActorCollision)
	{
		flt_TMass += Actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();
	}

	return flt_TMass;
}



