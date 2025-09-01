// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemigoP.generated.h"

class UStaticMeshComponent;
class UAudioComponent;
class UParticleSystem;
class USoundBase;

UCLASS(Abstract)
class BOYADVENTURE_API AEnemigoP : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemigoP();

    virtual void Tick(float DeltaTime) override;

    void morir();

    virtual void setMove(FVector newDir, float newSpeed);
    virtual void stopMove();


protected:
    virtual void BeginPlay() override;

    UPROPERTY(VisibleAnywhere)
    UStaticMeshComponent* mesh;

    UPROPERTY(VisibleAnywhere)
    UAudioComponent* audio;

    UPROPERTY(VisibleAnywhere)
    UParticleSystemComponent* fxLoop;

    UPROPERTY()
    UParticleSystem* explosionFx;

    UPROPERTY()
    USoundBase* explosionSound;

    UPROPERTY(EditAnywhere)
    float speed;

    UPROPERTY(EditAnywhere)
    FVector dir;

    UPROPERTY(VisibleAnywhere)
    int32 enemyId;

};
