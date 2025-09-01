// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BoyAdventureGameMode.generated.h"

class AEnemigoP;
class ATrampaHielo;
class ABolaFuego;

UCLASS(minimalapi)
class ABoyAdventureGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ABoyAdventureGameMode();

protected:

	virtual void BeginPlay() override;

private:

	class ATrampaHielo* TrampaHieloObject;
	class ABolaFuego* BolaFuegoObject;


    FTimerHandle TimerHandle_Trampas;


	void CrearTrampas();

    UPROPERTY(EditAnywhere)
    TArray<TSubclassOf<AEnemigoP>> enemyTypes;

    UPROPERTY(VisibleAnywhere)
    TArray<AEnemigoP*> enemiesArr;

    UPROPERTY(VisibleAnywhere)
    TMap<int32, AEnemigoP*> enemiesMap;

    UPROPERTY(EditAnywhere)
    int32 spawnCount;

    UPROPERTY(EditAnywhere)
    float spawnRadius;

    int32 nextKey;

    void spawnEnemies();
    void killNextFromArray();
    FTimerHandle timerHandleKill;

};



