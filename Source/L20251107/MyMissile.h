// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyMissile.generated.h"

class UBoxComponent;
class UStaticMeshComponent;

UCLASS()
class L20251107_API AMyMissile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyMissile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Components")
	UBoxComponent* Box;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* Mesh;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	float Speed = 1000.0f;

	UFUNCTION(BlueprintCallable)
	void CosmeticFunc();
};
