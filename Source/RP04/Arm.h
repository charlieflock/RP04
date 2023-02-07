// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Arm.generated.h"

UCLASS()
class RP04_API AArm : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AArm();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	FSocket* ListenSocket;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
