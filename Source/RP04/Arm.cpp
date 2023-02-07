// Fill out your copyright notice in the Description page of Project Settings.


#include "Arm.h"

#include "Common/UdpSocketBuilder.h"
#include "Interfaces/IPv4/IPv4Address.h"
#include "Interfaces/IPv4/IPv4Endpoint.h"

// Sets default values
AArm::AArm()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AArm::BeginPlay()
{
	Super::BeginPlay();

	// Try to open a UDP socket to receive input from tracking system

	FIPv4Address IPAddress;
	FIPv4Address::Parse(FString("localhost"), IPAddress);
	FIPv4Endpoint Endpoint(IPAddress, (uint16)8000);

	ListenSocket = FUdpSocketBuilder(TEXT("UDPSocket")).AsReusable();
	ISocketSubsystem* SocketSubsystem = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM);
	ListenSocket->Bind(*SocketSubsystem->CreateInternetAddr(Endpoint.Address.Value, Endpoint.Port));
	ListenSocket->Listen(2);
	
}

// Called every frame
void AArm::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// Receive input from listen socket every frame

}

// Called to bind functionality to input
void AArm::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	// Translate input to movement
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

