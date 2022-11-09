#include "09_AI/BTTaskNode_Hitted.h"
#include "AICharacter.h"
#include "CAIController.h"

UBTTaskNode_Hitted::UBTTaskNode_Hitted()
{
    bNotifyTick = true;
    NodeName = "Hitted";
}

EBTNodeResult::Type UBTTaskNode_Hitted::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    Super::ExecuteTask(OwnerComp, NodeMemory);

    ACAIController* controller = Cast<ACAIController>(OwnerComp.GetOwner());
    AAICharacter* ai = Cast<AAICharacter>(controller->GetPawn());

    return EBTNodeResult::InProgress;
}

void UBTTaskNode_Hitted::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
    Super::TickTask(OwnerComp, NodeMemory, DeltaSeconds);

    ACAIController* controller = Cast<ACAIController>(OwnerComp.GetOwner());
    AAICharacter* ai = Cast<AAICharacter>(controller->GetPawn());
}
