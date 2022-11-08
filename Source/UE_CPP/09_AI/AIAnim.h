#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "AIAnim.generated.h"

UCLASS()
class UE_CPP_API UAIAnim : public UAnimInstance
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Animation")
		float Speed;

private:
	class ACharacter* Owner;

public:
	virtual void NativeBeginPlay() override;
	virtual void NativeUpdateAnimation(float DelatSeconds) override;
};
