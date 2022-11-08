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

	// ���� �ð��� ������ �ִ� ��ų
	UPROPERTY(EditAnywhere)
		TSubclassOf<class ASkill> DestorySkill;
	
	// ���Ͽ� ���� �Ǿ� �ִ� ��ų
	UPROPERTY(EditAnywhere)
		TSubclassOf<class ASkill> AttachSkill;

	// Ư�� ��ġ���� �߻��Ǵ� ��ų
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

	// ���� �ð��� ������ �ִ� ��ų
	UFUNCTION()
	void Begin_DestorySkill();

	// ���Ͽ� ���� �Ǿ� �ִ� ��ų
	UFUNCTION()
	void Begin_AttachSkill();

	// Ư�� ��ġ���� �߻��Ǵ� ��ų
	UFUNCTION()
		void Begin_LocationSkill();
};
