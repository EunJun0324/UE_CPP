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
	
	UPROPERTY(EditDefaultsOnly)
		FString Name;

	UPROPERTY(EditDefaultsOnly)
		float MaxHp;
	
	float Hp;


private :
	class AAIWeapon* Weapon;

public:
	AAICharacter();

public :
	virtual float TakeDamage(
		float DamageAmount, 
		struct FDamageEvent const & DamageEvent, 
		class AController* EventIstigator,
		AActor* DamgeCauser) override;

protected:
	virtual void BeginPlay() override;

};
