// Copyright 2017 Thomas Gijsbers

#pragma once

#include "Engine/World.h"
#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

UCLASS( meta = (BlueprintSpawnableComponent), hidecategories = ("Collision") )
class BATTLETANK_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	// -1 is max left speed, +1 is max right speed
	void Azimuth(float RelativeSpeed);

private:
	/// TODO: remove MaxAzimuthDegrees and MinAzimuthDegrees, since the turret can rotate 360 degrees
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxDegreesPerSecond = 20;

	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxAzimuthDegrees = 360;

	UPROPERTY(EditAnywhere, Category = Setup)
	float MinAzimuthDegrees = 0;
	
};