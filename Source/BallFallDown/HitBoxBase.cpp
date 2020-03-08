// Fill out your copyright notice in the Description page of Project Settings.


//#include "HitBoxBase.h"
//#include "Components/BoxComponent.h"
//#include "BallFallDownBall.h"
//
//// Sets default values
//AHitBoxBase::AHitBoxBase()
//{
// 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
//	PrimaryActorTick.bCanEverTick = true;
//
//	HitBoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("HitBox"));
//	HitBoxComp->OnComponentBeginOverlap.AddDynamic(this, &AHitBoxBase::BeginHit);
//
//}
//
//// Called when the game starts or when spawned
//void AHitBoxBase::BeginPlay()
//{
//	Super::BeginPlay();
//	
//}
//
//// Called every frame
//void AHitBoxBase::Tick(float DeltaTime)
//{
//	Super::Tick(DeltaTime);
//
//}
//
//void AHitBoxBase::BeginHit(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
//{
//	if (Cast<ABallFallDownBall>(OtherActor))
//	{
//		ABallFallDownBall * ball = Cast<ABallFallDownBall>(OtherActor);
//
//		OnHitSphere(ball);
//	}
//
//}
//
//void AHitBoxBase::OnHitSphere(ABallFallDownBall* sphere)
//{
//
//}
