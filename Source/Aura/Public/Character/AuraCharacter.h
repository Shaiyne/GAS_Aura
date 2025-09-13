// Copyrights for GEAGM

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "GameFramework/Character.h"
#include "AuraCharacter.generated.h"

UCLASS()
class AURA_API AAuraCharacter : public AAuraCharacterBase
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAuraCharacter();

	virtual void PossessedBy(AController* NewController) override;
	
	virtual void OnRep_PlayerState() override;

	/* Combat Interface*/

	virtual int32 GetPlayerLevel() override;

	/* End Combat Interface*/
private:

	virtual void InitAbilityActorInfo() override;
};
