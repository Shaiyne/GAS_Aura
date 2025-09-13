// Copyrights for GEAGM


#include "AuraAssetManager.h"
#include "AuraGameplayTags.h"
#include <AbilitySystemGlobals.h>

UAuraAssetManager& UAuraAssetManager::Get()
{
	check(GEngine);

	UAuraAssetManager* AuraAssetManager = Cast<UAuraAssetManager>(GEngine->AssetManager);
	return *AuraAssetManager;
}

void UAuraAssetManager::StartInitialLoading()
{
	Super::StartInitialLoading();
	
	FAuraGameplayTags::InitializeNativeGameplayTags();


	// This is required to use Target Data! // TargetDataUnderMouse script , For need to Clearing Cache Data 
	UAbilitySystemGlobals::Get().InitGlobalData();
}
