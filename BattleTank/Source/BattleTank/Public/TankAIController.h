// Copyright 2017 Thomas Gijsbers

#pragma once

#include "Engine/World.h"
#include "Tank.h"
#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"


UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

private:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	ATank* GetControlledTank() const;

	ATank* GetPlayerTank() const;
};
