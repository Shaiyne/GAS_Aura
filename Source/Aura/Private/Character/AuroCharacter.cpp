// Copyrights for GEAGM


#include "Character/AuroCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include <Player/AuraPlayerState.h>
#include <AbilitySystem/AuraAbilitySystemComponent.h>



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

void AAuroCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	//Init ability actor info for the Server

	InitAbilityActorInfo();

}

void AAuroCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	//Init ability actor info for the Client
	InitAbilityActorInfo();

}

void AAuroCharacter::InitAbilityActorInfo()
{
	AAuraPlayerState* AuraPlayerState = GetPlayerState<AAuraPlayerState>();

	check(AuraPlayerState);

	AuraPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(AuraPlayerState, this);

	AbilitySystemComponent = AuraPlayerState->GetAbilitySystemComponent();

	AttributeSet = AuraPlayerState->GetAttributeSet();
}

