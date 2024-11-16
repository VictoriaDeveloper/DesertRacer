// Fill out your copyright notice in the Description page of Project Settings.


#include "Obstacle.h"
#include "PlayerCharacter.h"

AObstacle::AObstacle()
{
    
    // Enable tick 
    PrimaryActorTick.bCanEverTick = true;

    // Set and create the capsule component
    CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComp"));

    // Set the capsule component as the root component
    SetRootComponent(CapsuleComp);

    // Set and create the obstacle sprite
    ObstacleSprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("ObstacleSprite"));

    // Attach the obstacle sprite to the root component
    ObstacleSprite->SetupAttachment(RootComponent);
}




