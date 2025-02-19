// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "BallFallDownBall.h"
#include "UObject/ConstructorHelpers.h"
#include "Camera/CameraComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Engine/CollisionProfile.h"
#include "Engine/StaticMesh.h"

ABallFallDownBall::ABallFallDownBall()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> BallMesh(TEXT("/Game/Rolling/Meshes/BallMesh.BallMesh"));

	// Create mesh component for the ball
	Ball = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Ball0"));
	Ball->SetStaticMesh(BallMesh.Object);
	Ball->BodyInstance.SetCollisionProfileName(UCollisionProfile::PhysicsActor_ProfileName);
	Ball->SetSimulatePhysics(true);
	Ball->SetAngularDamping(0.5f);
	Ball->SetLinearDamping(0.5f);
	Ball->BodyInstance.MassScale = 3.5f;
	Ball->BodyInstance.MaxAngularVelocity = 80.0f;
	Ball->SetNotifyRigidBodyCollision(true);
	RootComponent = Ball;

	// Create a camera boom attached to the root (ball)
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm0"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->bDoCollisionTest = false;
	SpringArm->bAbsoluteRotation = true; // Rotation of the ball should not affect rotation of boom
	SpringArm->RelativeRotation = FRotator(-45.f, 0.f, 0.f);
	SpringArm->TargetArmLength = 1200.f;
	SpringArm->bEnableCameraLag = false;
	SpringArm->CameraLagSpeed = 3.f;

	// Create a camera and attach to boom
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera0"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
	Camera->bUsePawnControlRotation = false; // We don't want the controller rotating the camera

	// Set up forces
	RollTorque = 25000000.0f;
	JumpImpulse = 350000.0f;
	bCanJump = true; // Start being able to jump
	coins = 0;
	DeadTimes = 0;
}


void ABallFallDownBall::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// set up gameplay key bindings
	PlayerInputComponent->BindAxis("MoveRight", this, &ABallFallDownBall::MoveRight);
	PlayerInputComponent->BindAxis("MoveForward", this, &ABallFallDownBall::MoveForward);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ABallFallDownBall::Jump);

	// handle touch devices
	PlayerInputComponent->BindTouch(IE_Pressed, this, &ABallFallDownBall::TouchStarted);
	PlayerInputComponent->BindTouch(IE_Released, this, &ABallFallDownBall::TouchStopped);
}

void ABallFallDownBall::MoveRight(float Val)
{
	const FVector Torque = FVector(-1.f * Val * RollTorque, 0.f, 0.f);
	Ball->AddTorqueInRadians(Torque);
}

void ABallFallDownBall::MoveForward(float Val)
{
	const FVector Torque = FVector(0.f, Val * RollTorque, 0.f);
	Ball->AddTorqueInRadians(Torque);	
}

void ABallFallDownBall::Jump()
{
	if(bCanJump)
	{
		const FVector Impulse = FVector(0.f, 0.f, JumpImpulse);
		Ball->AddImpulse(Impulse);
		bCanJump = false;
	}
}

void ABallFallDownBall::NotifyHit(class UPrimitiveComponent* MyComp, class AActor* Other, class UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	Super::NotifyHit(MyComp, Other, OtherComp, bSelfMoved, HitLocation, HitNormal, NormalImpulse, Hit);

	bCanJump = true;
}

void ABallFallDownBall::TouchStarted(ETouchIndex::Type FingerIndex, FVector Location)
{
	if (bCanJump)
	{
		const FVector Impulse = FVector(0.f, 0.f, JumpImpulse);
		Ball->AddImpulse(Impulse);
		bCanJump = false;
	}

}

void ABallFallDownBall::TouchStopped(ETouchIndex::Type FingerIndex, FVector Location)
{
	if (bCanJump)
	{
		const FVector Impulse = FVector(0.f, 0.f, JumpImpulse);
		Ball->AddImpulse(Impulse);
		bCanJump = false;
	}
}

void ABallFallDownBall::BeginPlay()
{
	Super::BeginPlay();

	RecoverLocation = GetActorLocation();


}

void ABallFallDownBall::AddCoins()
{
	coins += 1;
}



bool ABallFallDownBall::DecCoins(int ConsumeAmount)
{
	if (ConsumeAmount > coins)
		return false;

	coins -= ConsumeAmount;
	return true;

}
void ABallFallDownBall::SetRecoverLocation(FVector rl)
{
	RecoverLocation = rl;
}

FVector ABallFallDownBall::GetRecoverLocation()
{

	return RecoverLocation;

}

void ABallFallDownBall::ResetDeadTimes()
{
	DeadTimes = 0;
}

