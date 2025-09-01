// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemigoP.h"
#include "EnemigoPB.generated.h"


UCLASS()
class BOYADVENTURE_API AEnemigoPB : public AEnemigoP
{
	GENERATED_BODY()

public:
	AEnemigoPB();

	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void setMove(FVector newDir, float newSpeed) override;
	virtual void stopMove() override;
};