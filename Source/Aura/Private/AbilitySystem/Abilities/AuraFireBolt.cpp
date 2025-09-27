// Copyrights for GEAGM


#include "AbilitySystem/Abilities/AuraFireBolt.h"
#include "AuraGameplayTags.h"

FString UAuraFireBolt::GetDesription(int32 Level)
{
	const int32 ScaledDamage = Damage.GetValueAtLevel(Level);
	const float ManaCost = FMath::Abs(GetManaCost(Level));
	const float Cooldown = GetCooldown(Level);
	if (Level == 1)
	{
		return FString::Printf(
			TEXT(
				// Title
				"<Title> FIRE BOLT </>\n\n"

				// Level
				"<Small>Level: </> <Level> %d </> \n"

				// Mana Cost
				"<Small>Mana Cost: </> <ManaCost> %.1f </> \n "

				// Cooldown
				"<Small>Cooldown: </> <Cooldown> %.1f </> \n\n"

				// Description
				"<Default> Launches a bolt of fire , exploding on impact and dealing: </> "
				"<Damage> %d </> "
				"<Default> fire damage with a chance to burn </> "
			),
			Level, ManaCost, Cooldown, ScaledDamage);
	}
	else
	{
		return FString::Printf(
			TEXT(
				// Title
				"<Title> FIRE BOLT </>\n\n"

				// Level
				"<Small>Level: </> <Level> %d </> \n\n"

				// Mana Cost
				"<Small> Mana Cost: </> <ManaCost> %.1f </> \n "

				// Cooldown
				"<Small>Cooldown: </> <Cooldown> %.1f </> \n\n"

				// Number of Projectiles
				"<Default> Launches %d a bolt of fire , exploding on impact and dealing: </> "

				// Description
				"<Damage> %d </> "
				"<Default> fire damage with a chance to burn </> "
			),
			Level, ManaCost, Cooldown, FMath::Min(Level, NumProjectiles), ScaledDamage);
	}
}

FString UAuraFireBolt::GetNextLevelDesription(int32 Level)
{
	const int32 ScaledDamage = Damage.GetValueAtLevel(Level);
	const float ManaCost = FMath::Abs(GetManaCost(Level));
	const float Cooldown = GetCooldown(Level);
	return FString::Printf(
		TEXT(
			// Title
			"<Title> NEXT LEVEL </> \n\n "

			// Level
			"<Small>Level: </> <Level> %d </> \n\n"

			// Mana Cost
			"<Small> Mana Cost: </> <ManaCost> %.1f </> \n "

			// Cooldown
			"<Small>Cooldown: </> <Cooldown> %.1f </> \n\n"

			// Number of Projectiles
			"<Default> Launches %d a bolt of fire , exploding on impact and dealing: </> "

			// Description
			"<Damage> %d </> "
			"<Default> fire damage with a chance to burn </> "
		),
		Level, ManaCost, Cooldown, FMath::Min(Level, NumProjectiles), ScaledDamage);
}