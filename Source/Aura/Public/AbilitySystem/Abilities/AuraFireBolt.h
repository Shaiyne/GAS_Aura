// Copyrights for GEAGM

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/AuraProjectileSpell.h"
#include "AuraFireBolt.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API UAuraFireBolt : public UAuraProjectileSpell
{
	GENERATED_BODY()
	
public:

	virtual FString GetDesription(int32 Level) override;

	virtual FString GetNextLevelDesription(int32 Level) override;
};
