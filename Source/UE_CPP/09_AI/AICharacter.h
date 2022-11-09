#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AICharacter.generated.h"

UCLASS()
class UE_CPP_API AAICharacter : public ACharacter
{
	GENERATED_BODY()

protected :
	UPROPERTY(VisibleDefaultsOnly)
		class UWidgetComponent* AIWidget;

private :
	class AAIWeapon* Weapon;

public:
	AAICharacter();

protected:
	virtual void BeginPlay() override;

};
