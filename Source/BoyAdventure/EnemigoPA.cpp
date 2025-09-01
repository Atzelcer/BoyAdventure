// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemigoPA.h"
#include "UObject/ConstructorHelpers.h"
#include "Materials/MaterialInterface.h"

AEnemigoPA::AEnemigoPA()
{
    static ConstructorHelpers::FObjectFinder<UStaticMesh> m(TEXT("/Game/StarterContent/Shapes/Shape_Trim_90_In.Shape_Trim_90_In"));
    if (m.Succeeded()) mesh->SetStaticMesh(m.Object);

    static ConstructorHelpers::FObjectFinder<UMaterialInterface> mat(TEXT("/Game/StarterContent/Materials/M_Metal_Gold.M_Metal_Gold"));
    if (mat.Succeeded()) mesh->SetMaterial(0, mat.Object);

    mesh->SetWorldScale3D(FVector(3.f));
}

void AEnemigoPA::BeginPlay()
{
	Super::BeginPlay();
}

void AEnemigoPA::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AEnemigoPA::setMove(FVector newDir, float newSpeed)
{
	Super::setMove(newDir, newSpeed);
}

void AEnemigoPA::stopMove()
{
	Super::stopMove();
}
