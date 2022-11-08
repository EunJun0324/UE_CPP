#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AIWidget.generated.h"

UCLASS()
class UE_CPP_API UAIWidget : public UUserWidget
{
	GENERATED_BODY()
	
public :
	UFUNCTION(BlueprintImplementableEvent)
	void UpdateHealth(float InHealth, float InMaxHealth);
	UFUNCTION(BlueprintImplementableEvent)
	void UpdateCharacterName(const FString& InName);
};
