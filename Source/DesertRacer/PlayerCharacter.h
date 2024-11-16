// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "PaperSpriteComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Components/InputComponent.h"
#include "InputActionValue.h"
#include "GameFramework/Controller.h"

#include "PlayerCharacter.generated.h"


UCLASS()
class DESERTRACER_API APlayerCharacter : public APawn
{

    GENERATED_BODY()

public:

	/**
     * @brief Constructs new APlayerCharacter by creating the UActorComponents
     * @param none
     * @return ACharacter
     */
	APlayerCharacter();

	// Hold the UCapsuleComponent for the collision
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    UCapsuleComponent* CapsuleComp;

    // Hold the USpringArmComponent for the camera
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    USpringArmComponent* SpringArm;

	// Hold the UCameraComponent for the player to see the character
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    UCameraComponent* Camera;

    // Hold the UPaperSpriteComponent to render the car
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    UPaperSpriteComponent* CarSprite;

	// Hold the UInputMappingContext for the APlayerChracter's Input Actions
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UInputMappingContext* InputMappingContext;

	// Hold the UInputAction for moving
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UInputAction* MoveAction;

	// Hold the character's movement speed
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MovementSpeed = 1000.0f;

	// Hold the character's rotation speed
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float RotationSpeed = 100.0f;

	// Hold true if the user can move
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool CanMove = true;

	/**
	 * @brief Configure BeginPlay to add the UInputMappingContext to the 
	 * player controller's EnhancedInputLocalPlayerSubsystem
	 * @param none
	 * @return void
	 */
	virtual void BeginPlay() override;

	/**
	 * @brief Configure SetupPlayerInputComponent to bind the UInputActions to the
	 * UEnhancedInputComponent
	 * @param UInputComponent* PlayerInputComponent a pointer to the 
	 * character's input component
	 * @return void
	 */
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	/**
	 * @brief Handle the character's movement 
	 * @param FInputActionValue value the value of the UInputAction
	 * @return void
	 */
	void Move(const FInputActionValue& Value);
};


