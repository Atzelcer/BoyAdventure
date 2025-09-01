// Fill out your copyright notice in the Description page of Project Settings.


#include "TrampaHielo.h"

ATrampaHielo::ATrampaHielo()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> TrampaMeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_WideCapsule.Shape_WideCapsule'"));
	if (TrampaMeshAsset.Succeeded())
	{
		TrampaMesh->SetStaticMesh(TrampaMeshAsset.Object);
		TrampaMesh->SetRelativeScale3D(FVector(1.0f, 1.0f, 1.0f));
	}
}

void ATrampaHielo::BeginPlay()
{
	Super::BeginPlay();
}

void ATrampaHielo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MoverTrampa(DeltaTime);
}

void ATrampaHielo::MoverTrampa(float DeltaTime)
{
	FVector NewLocation = GetActorLocation();
	NewLocation.X += FMath::Sin(GetGameTimeSinceCreation() * 2.0f) * 10.0f;
	NewLocation.Z += FMath::Sin(GetGameTimeSinceCreation() * 2.0f) * 10.0f;
	SetActorLocation(NewLocation);
	if (TrampaMesh)
	{
		FRotator NewRotation = TrampaMesh->GetComponentRotation();
		NewRotation.Yaw += DeltaTime * 10.0f;
		TrampaMesh->SetWorldRotation(NewRotation);
	}
}
