// Fill out your copyright notice in the Description page of Project Settings.


#include "MyMissile.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AMyMissile::AMyMissile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	RootComponent = Box;
	Box->SetBoxExtent(FVector(28.f, 8.f, 8.f));

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MESH"));
	Mesh->SetupAttachment(Box);
	Mesh->SetRelativeRotation(FRotator(-90.f, 0, 0));

	ConstructorHelpers::FObjectFinder<UStaticMesh> SM_Missile(TEXT("/Script/Engine.StaticMesh'/Game/StaticMeshes/SM_Rocket.SM_Rocket'"));
	if (SM_Missile.Succeeded())
	{
		Mesh->SetStaticMesh(SM_Missile.Object);
	}
}

// Called when the game starts or when spawned
void AMyMissile::BeginPlay()
{
	Super::BeginPlay();
	
	this->SetLifeSpan(10.f);
}

// Called every frame
void AMyMissile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddActorLocalOffset(FVector(Speed * DeltaTime, 0, 0));
}

void AMyMissile::CosmeticFunc()
{
	return;
}

