// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPawn.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/ArrowComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/FloatingPawnMovement.h"

// Sets default values
AMyPawn::AMyPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	RootComponent = Box;
	Box->SetBoxExtent(FVector(50.f, 68.f, 10.f));

	Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body"));
	Body->SetupAttachment(Box);
	Body->SetRelativeLocation(FVector(0, 0, -4.f));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_Body(TEXT("/Script/Engine.StaticMesh'/Game/StaticMeshes/SM_P38_Body.SM_P38_Body'"));
	if (SM_Body.Succeeded())
	{
		Body->SetStaticMesh(SM_Body.Object);
	}

	LeftPropel = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LeftPropel"));
	LeftPropel->SetupAttachment(Body);
	LeftPropel->SetRelativeLocation(FVector(37.5f, -21.f, 1.5f));

	RightPropel = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RightPropel"));
	RightPropel->SetupAttachment(Body);
	RightPropel->SetRelativeLocation(FVector(37.5f, 21.f, 1.5f));
	RightPropel->SetRelativeScale3D(FVector(1.f, -1.f, 1.f));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_Propel(TEXT("/Script/Engine.StaticMesh'/Game/StaticMeshes/SM_P38_Propeller.SM_P38_Propeller'"));
	if (SM_Propel.Succeeded())
	{
		LeftPropel->SetStaticMesh(SM_Propel.Object);
		RightPropel->SetStaticMesh(SM_Propel.Object);
	}

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(Box);
	SpringArm->TargetArmLength = 200.0f;
	SpringArm->SocketOffset = FVector(0, 0, 50.f);
	SpringArm->bDoCollisionTest = true;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);

	Arrow = CreateDefaultSubobject<UArrowComponent>(TEXT("Arrow"));
	Arrow->SetupAttachment(Body);
	Arrow->SetRelativeLocation(FVector(70.f, 0, -14.f));

	Movement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("Movement"));
	Movement->MaxSpeed = 2000.f;
}

// Called when the game starts or when spawned
void AMyPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddMovementInput( GetActorForwardVector() );

	LeftPropel->AddRelativeRotation(FRotator(0, 0, -1 * PropelRotationSpeed * DeltaTime));
	RightPropel->AddRelativeRotation(FRotator(0, 0, PropelRotationSpeed * DeltaTime));

}

// Called to bind functionality to input
void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

