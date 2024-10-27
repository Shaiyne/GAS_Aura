// Copyrights for GEAGM


#include "UI/WidgetController/AuraWidgetController.h"
#include <AttributeSet.h>

void UAuraWidgetController::SetWidgetControllerParams(const FWidgetControllerParams& WCParams)
{
	PlayerController = WCParams.PlayerController;
	PlayerState = WCParams.PlayerState;
	AbilitySystemComponent = WCParams.AbilitySystemComponent;
	AttributeSet = WCParams.AttributeSet;

}

void UAuraWidgetController::BroadcastInitialValues()
{

}

void UAuraWidgetController::BindCallbacksToDependencies()
{

}
