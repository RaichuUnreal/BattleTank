// Copyright 2017 Thomas Gijsbers

#include "TankTrack.h"

void UTankTrack::SetThrottle(float Throttle)
{
	// TODO clamp actual throttle value so player can't over-drive
	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied,ForceLocation);
}


