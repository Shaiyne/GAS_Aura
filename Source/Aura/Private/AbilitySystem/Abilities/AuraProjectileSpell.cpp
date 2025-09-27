// Copyrights for GEAGM


#include "AbilitySystem/Abilities/AuraProjectileSpell.h"
#include <Actor/AuraProjectile.h>
#include <Interaction/CombatInterface.h>
#include <AbilitySystemBlueprintLibrary.h>
#include "AbilitySystemComponent.h"
#include <AuraGameplayTags.h>
//#include <Kismet/KismetSystemLibrary.h>

void UAuraProjectileSpell::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	//UKismetSystemLibrary::PrintString(this, FString("ActivateAbility (C++)"), true, true, FLinearColor::Yellow, 3);
}

void UAuraProjectileSpell::SpawnProjectile(const FVector& ProjectileTargetLocation, const FGameplayTag& SocketTag, bool bOverridePitch, float PitchOverride)
{
	const bool bIsServer = GetAvatarActorFromActorInfo()->HasAuthority();

	if (!bIsServer) return;

	ICombatInterface* CombatInterface = Cast<ICombatInterface>(GetAvatarActorFromActorInfo());
	if (CombatInterface)
	{
		const FVector SocketLocation = ICombatInterface::Execute_GetCombatSocketLocation(GetAvatarActorFromActorInfo(), SocketTag); //= CombatInterface->GetCombatSocketLocation();

		FRotator Rotation = (ProjectileTargetLocation - SocketLocation).Rotation();
		Rotation.Pitch = bOverridePitch ? PitchOverride : Rotation.Pitch;

		FTransform SpawnTransform;
		SpawnTransform.SetLocation(SocketLocation);
		SpawnTransform.SetRotation(Rotation.Quaternion());

		AAuraProjectile* Projectile = GetWorld()->SpawnActorDeferred<AAuraProjectile>(
			ProjectileClass,
			SpawnTransform, GetOwningActorFromActorInfo(),
			Cast<APawn>(GetOwningActorFromActorInfo()),
			ESpawnActorCollisionHandlingMethod::AlwaysSpawn
		);

		/* Before FDamageEffectParams */

		//const UAbilitySystemComponent* SourceASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(GetAvatarActorFromActorInfo());
		//FGameplayEffectContextHandle EffectContextHandle = SourceASC->MakeEffectContext();
		///*  Make Effect Context new effect uretiyor fakat bazi parametreler set edilmemis halde . */
		//EffectContextHandle.SetAbility(this);
		//EffectContextHandle.AddSourceObject(Projectile);
		//TArray<TWeakObjectPtr<AActor>> Actors;
		//Actors.Add(Projectile);
		//EffectContextHandle.AddActors(Actors);
		//FHitResult HitResult;
		//HitResult.Location = ProjectileTargetLocation;
		//EffectContextHandle.AddHitResult(HitResult);
		///* END */
		//const FGameplayEffectSpecHandle SpecHandle = SourceASC->MakeOutgoingSpec(DamageEffectClass, GetAbilityLevel(), EffectContextHandle);
		//const FAuraGameplayTags GameplayTags = FAuraGameplayTags::Get();
		//const float ScaledDamage = Damage.GetValueAtLevel(GetAbilityLevel());
		//UAbilitySystemBlueprintLibrary::AssignTagSetByCallerMagnitude(SpecHandle, DamageType, ScaledDamage);
		//Projectile->DamageEffectSpecHandle = SpecHandle;

		/* End FDamageEffectParams */

		Projectile->DamageEffectParams = MakeDamageEffectParamsFromClassDefaults();

		Projectile->FinishSpawning(SpawnTransform);
	}
}
