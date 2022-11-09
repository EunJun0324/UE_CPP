#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTaskNode_Attack.generated.h"

UCLASS()
class UE_CPP_API UBTTaskNode_Attack : public UBTTaskNode
{
	GENERATED_BODY()
	
private :
	UPROPERTY(EditAnywhere, Category = "AI")
		float Delay = 1.0f;

public :
	UBTTaskNode_Attack();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	virtual EBTNodeResult::Type AbortTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	virtual void TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

private :
	float TotalTime;
};
