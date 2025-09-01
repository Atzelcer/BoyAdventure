// Fill out your copyright notice in the Description page of Project Settings.


#include "TrampaP.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"

// Sets default values
ATrampaP::ATrampaP()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create a Static Mesh Component and set it as the Root Component
	TrampaMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Trampa Mesh"));
	RootComponent = TrampaMesh;

}

// Called when the game starts or when spawned
void ATrampaP::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATrampaP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MoverTrampa(DeltaTime);
}

void ATrampaP::MoverTrampa(float DeltaTime)
{
	FVector NewLocation = GetActorLocation();
	NewLocation.Z += FMath::Sin(GetGameTimeSinceCreation() * 2.0f) * 10.0f;

	SetActorLocation(NewLocation);
	if (TrampaMesh)
	{
		FRotator NewRotation = TrampaMesh->GetComponentRotation();
		NewRotation.Yaw += DeltaTime * 10.0f;
		TrampaMesh->SetWorldRotation(NewRotation);
	}

}

