// Copyrights for GEAGM

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include <UI/WidgetController/AuraWidgetController.h>
#include "AuraHUD.generated.h"


class UAuraUserWidget;
class UOverlayWidgetController;
struct FWidgetControllerParams;


UCLASS()
class AURA_API AAuraHUD : public AHUD
{
	GENERATED_BODY()
	

public:

	UPROPERTY()
	TObjectPtr<UAuraUserWidget> OverlayWidget;


	UFUNCTION()
	UOverlayWidgetController* GetOverlayWidgetController(const FWidgetControllerParams& WCParams);


	void InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS);

private:

	UPROPERTY(EditAnywhere)
	TSubclassOf<UAuraUserWidget> OverlayWidgetClass;

	TObjectPtr<UOverlayWidgetController> OverlayWidgetController;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UOverlayWidgetController> OverlayWidgetControllerClass;

};
