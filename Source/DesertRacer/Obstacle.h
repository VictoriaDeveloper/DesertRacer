// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/CapsuleComponent.h"
#include "PaperSpriteComponent.h"
#include "Obstacle.generated.h"


UCLASS()
class DESERTRACER_API AObstacle : public AActor
{
  
    GENERATED_BODY()

public:
    
    // Hold the UCapsuleComponent for the collision
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    UCapsuleComponent* CapsuleComp;

    // Hold the UPaperSpriteComponent to render the obstacle
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    UPaperSpriteComponent* ObstacleSprite;

    /**
     * @brief Constructs new AObstacle by creating the UActorComponents
     * @param none
     * @return AObstacle 
     */
    AObstacle();
};

