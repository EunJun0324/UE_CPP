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

	// 제거 시간이 정해져 있는 스킬
	UPROPERTY(EditAnywhere)
		TSubclassOf<class ASkill> DestorySkill;
	
	// 소켓에 장착 되어 있는 스킬
	UPROPERTY(EditAnywhere)
		TSubclassOf<class ASkill> AttachSkill;

	// 특정 위치에서 발생되는 스킬
	UPROPERTY(EditAnywhere)
		TSubclassOf<class ASkill> LocationSkill;

private :
	class ACPlayer* owner;

public:	
	USkillComponent();
	
protected:
	virtual void BeginPlay() override;

public :
	void OnDestorySkill();

	// 제거 시간이 정해져 있는 스킬
	UFUNCTION()
	void Begin_DestorySkill();

	// 소켓에 장착 되어 있는 스킬
	UFUNCTION()
	void Begin_AttachSkill();

	// 특정 위치에서 발생되는 스킬
	UFUNCTION()
		void Begin_LocationSkill();
};
