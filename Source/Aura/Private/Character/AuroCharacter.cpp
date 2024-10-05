// Copyrights for GEAGM


#include "Character/AuroCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"



AAuroCharacter::AAuroCharacter()
{

	PrimaryActorTick.bCanEverTick = true;

	GetCharacterMovement()->bOrientRotationToMovement = true;

	GetCharacterMovement()->RotationRate = FRotator(0.f, 400.f, 0.f);

	GetCharacterMovement()->bConstrainToPlane = true;

	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;


}

