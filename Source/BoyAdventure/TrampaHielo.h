// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TrampaP.h"
#include "TrampaHielo.generated.h"


UCLASS()
class BOYADVENTURE_API ATrampaHielo : public ATrampaP
{
	GENERATED_BODY()

public:

	ATrampaHielo();

protected:

	virtual void BeginPlay() override;

public:

	virtual void Tick(float DeltaTime) override;

protected:

	virtual void MoverTrampa(float DeltaTime) override;
	
};
