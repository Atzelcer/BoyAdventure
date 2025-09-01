// Fill out your copyright notice in the Description page of Project Settings.


#include "BolaFuego.h"


ABolaFuego::ABolaFuego()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> BolaFuegoMeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	if (BolaFuegoMeshAsset.Succeeded())
	{
		TrampaMesh->SetStaticMesh(BolaFuegoMeshAsset.Object);
		TrampaMesh->SetRelativeScale3D(FVector(0.5f, 0.5f, 0.5f));
	}
}

void ABolaFuego::BeginPlay()
{
	Super::BeginPlay();
}

void ABolaFuego::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABolaFuego::MoverTrampa(float DeltaTime)
{
	Super::MoverTrampa(DeltaTime);
}
