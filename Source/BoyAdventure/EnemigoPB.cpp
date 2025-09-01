// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemigoPB.h"
#include "UObject/ConstructorHelpers.h"
#include "Materials/MaterialInterface.h"

AEnemigoPB::AEnemigoPB()
{
    static ConstructorHelpers::FObjectFinder<UStaticMesh> m(TEXT("/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube"));
    if (m.Succeeded()) mesh->SetStaticMesh(m.Object);

    static ConstructorHelpers::FObjectFinder<UMaterialInterface> mat(TEXT("/Game/StarterContent/Materials/M_ColorGrid_LowSpec.M_ColorGrid_LowSpec"));
    if (mat.Succeeded()) mesh->SetMaterial(0, mat.Object);

    mesh->SetWorldScale3D(FVector(3.f));
}

void AEnemigoPB::BeginPlay()
{
	Super::BeginPlay();
}

void AEnemigoPB::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AEnemigoPB::setMove(FVector newDir, float newSpeed)
{
	Super::setMove(newDir, newSpeed);
}

void AEnemigoPB::stopMove()
{
	Super::stopMove();
}
