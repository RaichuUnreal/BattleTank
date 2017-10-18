// Copyright 2017 Thomas Gijsbers

#include "TankTurret.h"

void UTankTurret::Azimuth(float RelativeSpeed)
{
	// Move the turret the right amount this frame
	// Given a max azimuth speed, and the frame time
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	auto AzimuthChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewAzimuth = RelativeRotation.Pitch + AzimuthChange;
	auto Azimuth = FMath::Clamp<float>(RawNewAzimuth, MinAzimuthDegrees, MaxAzimuthDegrees);

	SetRelativeRotation(FRotator(0, 0, Azimuth));
}


