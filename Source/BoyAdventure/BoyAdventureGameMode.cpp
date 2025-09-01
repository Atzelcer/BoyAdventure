// Copyright Epic Games, Inc. All Rights Reserved.

#include "BoyAdventureGameMode.h"
#include "BoyAdventureCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/World.h"
#include "BolaFuego.h"
#include "TrampaHielo.h"
#include "Kismet/KismetMathLibrary.h"
#include "EnemigoP.h"
#include "EnemigoPA.h"
#include "EnemigoPB.h"
#include "EnemigoPC.h"
#include "TimerManager.h"

ABoyAdventureGameMode::ABoyAdventureGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	spawnCount = 6;
	spawnRadius = 600.f;
	nextKey = 1;
}

void ABoyAdventureGameMode::BeginPlay()
{
	Super::BeginPlay();

	// Configurar timer para crear trampas cada 5 segundos
	GetWorld()->GetTimerManager().SetTimer(
		TimerHandle_Trampas,
		this,
		&ABoyAdventureGameMode::CrearTrampas,
		5.0f, 
		true,  
		2.0f  
	);

	spawnEnemies();

	GetWorldTimerManager().SetTimer(
		timerHandleKill, this,
		&ABoyAdventureGameMode::killNextFromArray,
		3.0f, true, 2.0f
	);
}

void ABoyAdventureGameMode::CrearTrampas()
{
	if (GetWorld())
	{
		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = this;


		TrampaHieloObject = GetWorld()->SpawnActor<ATrampaHielo>(
			ATrampaHielo::StaticClass(),
			FVector(FMath::RandRange(-500.f, 500.f), FMath::RandRange(-500.f, 500.f), 50.f),
			FRotator::ZeroRotator,
			SpawnParams
		);


		BolaFuegoObject = GetWorld()->SpawnActor<ABolaFuego>(
			ABolaFuego::StaticClass(),
			FVector(FMath::RandRange(-500.f, 500.f), FMath::RandRange(-500.f, 500.f), 50.f),
			FRotator::ZeroRotator,
			SpawnParams
		);
	}
}

void ABoyAdventureGameMode::spawnEnemies()
{
    UWorld* w = GetWorld();
    if (!w) return;

    FVector baseLoc = FVector::ZeroVector;
    FRotator rot = FRotator::ZeroRotator;

    // TArray
    for (int32 i = 0; i < 3; i++)
    {
        FVector loc = baseLoc + FVector(i * 250.f, 0, 120.f);

        AEnemigoP* e = nullptr;
        if (i == 0) e = w->SpawnActor<AEnemigoPA>(AEnemigoPA::StaticClass(), loc, rot);
        if (i == 1) e = w->SpawnActor<AEnemigoPB>(AEnemigoPB::StaticClass(), loc, rot);
        if (i == 2) e = w->SpawnActor<AEnemigoPC>(AEnemigoPC::StaticClass(), loc, rot);

        if (e)
        {
            FVector dir = UKismetMathLibrary::RandomUnitVector();
            dir.Z = 0.f;
            e->setMove(dir, 180.f);
            enemiesArr.Add(e);
        }
    }

    // Tmap
    for (int32 i = 0; i < 3; i++)
    {
        FVector loc = baseLoc + FVector(i * -250.f, 300.f, 120.f);

        AEnemigoP* e = nullptr;
        if (i == 0) e = w->SpawnActor<AEnemigoPB>(AEnemigoPB::StaticClass(), loc, rot);
        if (i == 1) e = w->SpawnActor<AEnemigoPC>(AEnemigoPC::StaticClass(), loc, rot);
        if (i == 2) e = w->SpawnActor<AEnemigoPA>(AEnemigoPA::StaticClass(), loc, rot);

        if (e)
        {
            FVector dir = UKismetMathLibrary::RandomUnitVector();
            dir.Z = 0.f;
            e->setMove(dir, 200.f);
            enemiesMap.Add(nextKey++, e);
        }
    }
}

void ABoyAdventureGameMode::killNextFromArray()
{
    for (AEnemigoP* e : enemiesArr)
    {
        if (IsValid(e))
        {
            e->morir();

            int32 removeKey = 0;
            for (auto& kv : enemiesMap)
            {
                if (kv.Value == e)
                {
                    removeKey = kv.Key;
                    break;
                }
            }
            if (removeKey != 0)
            {
                enemiesMap.Remove(removeKey);
            }

            enemiesArr.RemoveSingle(e);
            return;
        }
    }

    GetWorldTimerManager().ClearTimer(timerHandleKill);
}