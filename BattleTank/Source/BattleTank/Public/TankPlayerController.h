// Copyright 2017 Thomas Gijsbers

#pragma once

#include "Engine/World.h"
#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"


UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
private:
	ATank* GetControlledTank() const;

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;
	
	// Start the tank moving the barrel so that a shot would hit where
	// the crosshair intersects the world
	void AimTowardsCrosshair();

	// Return an OUT parameter, true if hit landscape
	bool GetSightRayHitLocation(FVector &OutHitLocation) const;

	UPROPERTY(EditAnywhere)
	float CrosshairXLocation = .5f;
	
	UPROPERTY(EditAnywhere)
	float CrosshairYLocation = .33333f;

	UPROPERTY(EditAnywhere)
	float LineTraceRange = 1000000.f;

	bool GetLookDirection(FVector2D ScreenLocation, FVector &OutLookDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector &OutHitLocation) const;
};
