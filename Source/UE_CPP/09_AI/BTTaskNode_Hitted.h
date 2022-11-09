#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTaskNode_Hitted.generated.h"

UCLASS()
class UE_CPP_API UBTTaskNode_Hitted : public UBTTaskNode
{
	GENERATED_BODY()
	
public:
	UBTTaskNode_Hitted();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	virtual void TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
};
