// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemigoPC.h"
#include "UObject/ConstructorHelpers.h"
#include "Materials/MaterialInterface.h"

AEnemigoPC::AEnemigoPC()
{
    static ConstructorHelpers::FObjectFinder<UStaticMesh> m(TEXT("/Game/StarterContent/Shapes/Shape_Cone.Shape_Cone"));
    if (m.Succeeded()) mesh->SetStaticMesh(m.Object);

    static ConstructorHelpers::FObjectFinder<UMaterialInterface> mat(TEXT("/Game/StarterContent/Materials/M_Water_Ocean.M_Water_Ocean"));
    if (mat.Succeeded()) mesh->SetMaterial(0, mat.Object);

    mesh->SetWorldScale3D(FVector(3.f));
}

void AEnemigoPC::BeginPlay()
{
	Super::BeginPlay();
}

void AEnemigoPC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AEnemigoPC::setMove(FVector newDir, float newSpeed)
{
	Super::setMove(newDir, newSpeed);
}

void AEnemigoPC::stopMove()
{
	Super::stopMove();
}
