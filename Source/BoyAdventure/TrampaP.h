// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TrampaP.generated.h"

UCLASS()
class BOYADVENTURE_API ATrampaP : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATrampaP();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Trampa")
	class UStaticMeshComponent* TrampaMesh;

protected:
	virtual void MoverTrampa(float DeltaTime);

};
