// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemigoP.h"
#include "EnemigoPA.generated.h"

UCLASS()
class BOYADVENTURE_API AEnemigoPA : public AEnemigoP
{
	GENERATED_BODY()
	
public:
	AEnemigoPA();

	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void setMove(FVector newDir, float newSpeed) override;
	virtual void stopMove() override;
};
