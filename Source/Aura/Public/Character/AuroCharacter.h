// Copyrights for GEAGM

#pragma once

#include "CoreMinimal.h"
#include "Character/AuroCharacterBase.h"
#include "GameFramework/Character.h"
#include "AuroCharacter.generated.h"

UCLASS()
class AURA_API AAuroCharacter : public AAuroCharacterBase
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAuroCharacter();

	virtual void PossessedBy(AController* NewController) override;
	
	virtual void OnRep_PlayerState() override;

private:

	void InitAbilityActorInfo();
};
