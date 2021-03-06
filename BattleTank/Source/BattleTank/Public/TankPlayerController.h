// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATank;

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	virtual void Tick(float DeltaTime) override;
	virtual void ATankPlayerController::BeginPlay() override;
	ATank* ATankPlayerController::GetControlledTank() const;

private:
	UPROPERTY(EditDefaultsOnly)
	float SightingRange = 1000.f;

	UPROPERTY(EditDefaultsOnly)
	float CrosshairXLocation = 0.5f;

	UPROPERTY(EditDefaultsOnly)
	float CrosshairYLocation = 0.5f;

	UPROPERTY(EditDefaultsOnly)
	float LineTraceRange = 10000000.f; // 10km

	FVector CameraViewPointLocation;
	FRotator CameraViewPointRotation;

	void AimAtCrosshair();

	bool GetSightRayHitLocation(FVector& out_HitLocation) const;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	FVector2D GetScreenLocation(int32 ViewportSizeX, int32 ViewportSizeY) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;
};
