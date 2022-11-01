#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SkillComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UE_CPP_API USkillComponent : public UActorComponent
{
	GENERATED_BODY()

private :
	UPROPERTY(EditAnywhere)
		class UAnimMontage* DestorySkillMontage;

	UPROPERTY(EditAnywhere)
		TSubclassOf<class ASkill> DestorySkill;

private :
	class ACPlayer* owner;

public:	
	USkillComponent();
	
protected:
	virtual void BeginPlay() override;

public :
	void OnDestorySkill();

	UFUNCTION()
	void Begin_DestorySkill();
};
