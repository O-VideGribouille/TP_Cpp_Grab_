// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
//#include "PhysicsEngine/PhysicsHandleComponent.h" // pas besoin d'autre bibliothèque
#include "OpenTheDoor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDoorEvent);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYPROJECT4_API UOpenTheDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenTheDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(BlueprintAssignable)
		FDoorEvent OpenDoorRequest;

	UPROPERTY(BlueprintAssignable)
		FDoorEvent CloseDoorRequest;

	void OpenDoor();

	void Closedoor();

	float flt_GetToMass();


private :
	UPROPERTY(EditAnywhere)
		ATriggerVolume* Atggr_Trigger = nullptr;

	UPROPERTY(EditAnywhere)
		float flt_MaxMass;
	
		
};
