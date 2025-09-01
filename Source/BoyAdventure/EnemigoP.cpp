// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemigoP.h"
#include "Components/StaticMeshComponent.h"
#include "Components/AudioComponent.h"
#include "Particles/ParticleSystem.h"
#include "Sound/SoundBase.h"
#include "Kismet/GameplayStatics.h"

AEnemigoP::AEnemigoP()
{
    PrimaryActorTick.bCanEverTick = true;

    mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("mesh"));
    SetRootComponent(mesh);

    audio = CreateDefaultSubobject<UAudioComponent>(TEXT("audio"));
    audio->SetupAttachment(RootComponent);
    audio->bAutoActivate = false;

    speed = 0.f;
    dir = FVector::ZeroVector;

    // set assets directamente
    explosionFx = LoadObject<UParticleSystem>(nullptr, TEXT("/Game/StarterContent/Particles/P_Explosion.P_Explosion"));
    explosionSound = LoadObject<USoundBase>(nullptr, TEXT("/Game/StarterContent/Audio/Explosion02.Explosion02"));
}

void AEnemigoP::BeginPlay()
{
    Super::BeginPlay();
}

void AEnemigoP::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (speed > 0.f)
    {
        FVector step = dir * speed * DeltaTime;
        AddActorWorldOffset(step, false);
    }
}

void AEnemigoP::setMove(FVector newDir, float newSpeed)
{
    dir = newDir;
    speed = newSpeed;
}


void AEnemigoP::stopMove()
{
    dir = FVector::ZeroVector;
    speed = 0.f;
}

void AEnemigoP::morir()
{
    if (explosionFx)
        UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), explosionFx, GetActorTransform());

    if (explosionSound)
        UGameplayStatics::PlaySoundAtLocation(GetWorld(), explosionSound, GetActorLocation());

    Destroy();
}

