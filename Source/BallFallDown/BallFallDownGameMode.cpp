// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "BallFallDownGameMode.h"
#include "Engine.h"
#include "BallFallDownBall.h"

ABallFallDownGameMode::ABallFallDownGameMode()
{
	//// set default pawn class to our ball
	////DefaultPawnClass = ABallFallDownBall::StaticClass();
	//PrimaryActorTick.bCanEverTick = true;

	//PlayerDieNum = 0;
	//IsEnd = false;

}
//
//void ABallFallDownGameMode::BeginPlay()
//{
//	Super::BeginPlay();
//
//	ABallFallDownBall* Pawn = Cast<ABallFallDownBall>(GetWorld()->GetFirstPlayerController()->GetPawn());
//	if (Pawn)
//	{
//		PlayPawn = Pawn;
//		CurrentStart = PlayPawn->GetActorLocation();
//
//	}
//}
//
//void ABallFallDownGameMode::Tick(float DeltaTime)
//{
//	Super::Tick(DeltaTime);
//}
//
//void ABallFallDownGameMode::SetPlayerLocation()
//{
//	PlayPawn->SetActorLocation(CurrentStart);
//	PlayPawn->Ball->SetPhysicsLinearVelocity(FVector(0, 0, 0));
//	PlayPawn->Ball->SetPhysicsAngularVelocity(FVector(0, 0, 0));
//	//PlayerDieNum++;
//}
//
//void ABallFallDownGameMode::SetPlayerLocation(FVector Start)
//{
//	PlayPawn->SetActorLocation(Start);
//	PlayPawn->Ball->SetPhysicsLinearVelocity(FVector(0, 0, 0));
//	PlayPawn->Ball->SetPhysicsAngularVelocity(FVector(0, 0, 0));
//}
//
//void ABallFallDownGameMode::SetPlayerInput(bool isInput)
//{
//	PlayPawn->IsInput = isInput;
//	if (!isInput)
//	{
//		IsEnd = true;
//	}
//
//}
//
//void ABallFallDownGameMode::SetCurrentStart(FVector Location)
//{
//	if (Location != FVector(0, 0, 0))
//	{
//		CurrentStart = Location;
//
//	}
//}
