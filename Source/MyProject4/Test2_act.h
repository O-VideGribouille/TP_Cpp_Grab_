// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/staticMeshComponent.h"
#include "Test2_act.generated.h"

UCLASS()
class MYPROJECT4_API ATest2_act : public AActor
{
	GENERATED_BODY()
	
public :
	//pour définir dans l'éditeur
	//UPROPERTY(EditAnywhere)
		//mettre en dessous la déclaration de propriété

		//UPROPERTY(EditAnywhere, Category= "Damage")
		// int 32 TotalDamage //exemple

		//même propriété avec Blueprint
		//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Damage")
		//int 32 TotalDamage // exemple nont retenu pour l'exercice
public:	

	
	// Sets default values for this actor's properties
	ATest2_act();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	void Interacted();
	bool GetActive();

	void TraceObjects();
	void GrabObject();
	void DropObject();

private :
	UPROPERTY()
		bool active;

	UPROPERTY(VisibleAnywhere, Category = "Mesh")
		class UStaticMeshComponent* mesh;

};
