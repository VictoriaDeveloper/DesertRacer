// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "PaperSpriteComponent.h"
#include "PlayerCharacter.h"


APlayerCharacter::APlayerCharacter()
{
  
    // Enable tick
    PrimaryActorTick.bCanEverTick = true;

    // Set and create the capsule component
    CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComp"));

    // Set the UCapsuleComponent as the RootComponent
    SetRootComponent(CapsuleComp);

    // Set and create the USpringArmComponent
    SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
   
   // Attach the USpringArmComponent to the RootComponent
    SpringArm->SetupAttachment(RootComponent);

    // Set and create the UCameraComponent
    Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));

    // Attach the UCameraComponent to the spring arm
    Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);

    // Create and set the UPaperSpriteComponent for the car
    CarSprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("CarSprite"));

    // Attach the UPaperSpriteComponent to the root component
    CarSprite->SetupAttachment(RootComponent);
}


void APlayerCharacter::BeginPlay()
{
    // Call the parent class's BeginPlay() function 
    Super::BeginPlay();

    // Hold the character's APlayerController
    APlayerController *PlayerController = Cast<APlayerController>(Controller);

    // Check if the APlayerController is not null
    if (PlayerController != nullptr)
    {
        
        // Hold the APlayerController's UEnhancedInputLocolPlayerSubsytem 
        UEnhancedInputLocalPlayerSubsystem *Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer());

        // Check if the UEnhancedInputLocolPlayerSubsytem  is not null
        if (Subsystem != nullptr)
        {
            
            //  Add the UInptMappingContext to the APlayerController's 
            // UEnchancedInputLocalPlayerSubsytem
            Subsystem->AddMappingContext(InputMappingContext, 0);
        }
    }
}


void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    // Call the parent class's  SetupPlayerInputComponent function 
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    // Hold character's UEnchanedInputComponent
    UEnhancedInputComponent *EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent);
    
    // Check if the UEnchancedInputComponent is not null
    if (EnhancedInputComponent != nullptr)
    {
       
       // Bind the move UInputAction to the UEnchanedInputComponent
        EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &APlayerCharacter::Move);
    }
}


void APlayerCharacter::Move(const FInputActionValue& Value)
{

    // Hold the move action value that holds a FVector2d from the 
    // FInputActionValue 
    FVector2D MoveActionValue = Value.Get<FVector2D>();

    // Check if the character can move
    if (CanMove)
    {
		
        // Check if the move action has a absolute value greater than 0
		if (abs(MoveActionValue.Y) > 0.0f)
		{
		
            // Hold the delta time
			float DeltaTime = GetWorld()->DeltaTimeSeconds;

            // Check if the move action value has a positive x value
			if (abs(MoveActionValue.X) > 0.0f)
			{

                // Hold the rotation amount
				float RotationAmount = -RotationSpeed * MoveActionValue.X * DeltaTime;

                // Add the rotation to the character
				AddActorWorldRotation(FRotator(RotationAmount, 0.0f, 0.0f));
			}

            // Hold the final movement speed
			float FinalMovementSpeed = MovementSpeed;

            // Check if the move action value is less than 0
			if (MoveActionValue.Y < 0.0f)
			{

                // Set the new final speed
				FinalMovementSpeed *= 0.5f;
			}

            // Hold the current location
			FVector CurrentLocation = GetActorLocation();

            // Hold the distance to move
			FVector DistanceToMove = GetActorUpVector() * FinalMovementSpeed * MoveActionValue.Y * DeltaTime;

            // Hold the new location
			FVector NewLocation = CurrentLocation + DistanceToMove;

            // Set the actor location as the new location
			SetActorLocation(NewLocation);
		}
    }
}




