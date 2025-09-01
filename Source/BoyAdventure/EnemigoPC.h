// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemigoP.h"
#include "EnemigoPC.generated.h"


UCLASS()
class BOYADVENTURE_API AEnemigoPC : public AEnemigoP
{
	GENERATED_BODY()
	
public:
	AEnemigoPC();

protected:

	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void setMove(FVector newDir, float newSpeed) override;
	virtual void stopMove() override;
};
