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
		class UAnimMontage* SkillMontage;

	UPROPERTY(EditAnywhere)
		TSubclassOf<class ASkill> Skill;

private :
	class ACPlayer* owner;

public:	
	USkillComponent();
	
protected:
	virtual void BeginPlay() override;

public :
	void OnSkill();

	UFUNCTION(BlueprintCallable)
	void Begin_Skill();
};
