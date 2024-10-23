// Copyrights for GEAGM


#include "Character/AuroEnemy.h"
#include <Aura/Aura.h>
#include <AbilitySystem/AuraAbilitySystemComponent.h>
#include <AbilitySystem/AuraAttributeSet.h>



AAuroEnemy::AAuroEnemy()
{

	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);

	AbilitySystemComponent = CreateDefaultSubobject<UAuraAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

	AttributeSet = CreateDefaultSubobject<UAuraAttributeSet>("AttributeSet");

}

void AAuroEnemy::HighlightActor()
{

	GetMesh()->SetRenderCustomDepth(true);

	GetMesh()->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);

	Weapon->SetRenderCustomDepth(true);

	Weapon->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);

}

void AAuroEnemy::UnHighlightActor()
{

	GetMesh()->SetRenderCustomDepth(false);

	Weapon->SetRenderCustomDepth(false);
}

void AAuroEnemy::BeginPlay()
{
	Super::BeginPlay();

	AbilitySystemComponent->InitAbilityActorInfo(this, this);
}
