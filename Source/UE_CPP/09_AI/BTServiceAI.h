#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "BTServiceAI.generated.h"

UCLASS()
class UE_CPP_API UBTServiceAI : public UBTService
{
	GENERATED_BODY()
	
private :
	UPROPERTY(EditAnywhere, Category = "Attack")
		float AttackRange = 450;

public :
	UBTServiceAI();

protected :
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
};
