#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "SkillNotify.generated.h"

UCLASS()
class UE_CPP_API USkillNotify : public UAnimNotify
{
	GENERATED_BODY()
	
private :
	FString GetNotifyName_Implementation() const override;

	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation) override;
};
