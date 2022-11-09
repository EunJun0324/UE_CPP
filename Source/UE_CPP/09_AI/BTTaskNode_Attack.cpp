#include "09_AI/BTTaskNode_Attack.h"
#include "AICharacter.h"
#include "CAIController.h"

UBTTaskNode_Attack::UBTTaskNode_Attack()
{
    bNotifyTick = true;
    NodeName = "Attack";
}

EBTNodeResult::Type UBTTaskNode_Attack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    Super::ExecuteTask(OwnerComp, NodeMemory);

    ACAIController* controller = Cast<ACAIController>(OwnerComp.GetOwner());
    AAICharacter* ai = Cast<AAICharacter>(controller->GetPawn());

    return EBTNodeResult::InProgress;
}

EBTNodeResult::Type UBTTaskNode_Attack::AbortTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    Super::AbortTask(OwnerComp, NodeMemory);

    ACAIController* controller = Cast<ACAIController>(OwnerComp.GetOwner());
    AAICharacter* ai = Cast<AAICharacter>(controller->GetPawn());

    return EBTNodeResult::Succeeded;
}

void UBTTaskNode_Attack::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
    Super::TickTask(OwnerComp, NodeMemory, DeltaSeconds);

    ACAIController* controller = Cast<ACAIController>(OwnerComp.GetOwner());
    AAICharacter* ai = Cast<AAICharacter>(controller->GetPawn());
}
