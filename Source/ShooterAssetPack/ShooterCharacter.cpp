// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterCharacter.h"

// Sets default values
AShooterCharacter::AShooterCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AShooterCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}
// Called every frame
void AShooterCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AShooterCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent ->BindAxis("MoveForward",this,&AShooterCharacter::MoveForward);
	PlayerInputComponent ->BindAxis("LookUp",this,&AShooterCharacter::LookUp);
	
	PlayerInputComponent ->BindAxis("MoveRight",this,&AShooterCharacter::MoveRight);
	PlayerInputComponent ->BindAxis("LookRight",this,&AShooterCharacter::LookRight);
	PlayerInputComponent ->BindAction("Jump",IE_Pressed,this,&ACharacter::Jump);
}

void AShooterCharacter::MoveForward(float AxisValue)
{
	AddMovementInput(GetActorForwardVector()*AxisValue);
}
inline void AShooterCharacter::LookUp(float AxisValue)
{
	AddControllerPitchInput(AxisValue);
}
inline void AShooterCharacter::MoveRight(float AxisValue)
{
	AddMovementInput(GetActorRightVector()*AxisValue);

}

inline void AShooterCharacter::LookRight(float AxisValue)
{
	AddControllerYawInput(AxisValue);
}
