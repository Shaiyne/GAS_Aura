// Copyrights for GEAGM


#include "Character/AuroEnemy.h"
#include <Aura/Aura.h>



AAuroEnemy::AAuroEnemy()
{

	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
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
