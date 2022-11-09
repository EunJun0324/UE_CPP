#include "09_AI/BTServiceAI.h"
#include "Player/CPlayer.h"
#include "AICharacter.h"
#include "CAIController.h"
#include "BehaviorTree/BehaviorTreeComponent.h"

UBTServiceAI::UBTServiceAI()
{ NodeName = "AI"; }

void UBTServiceAI::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
    Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

    ACAIController* controller = Cast<ACAIController>(OwnerComp.GetOwner());
    AAICharacter* ai = Cast<AAICharacter>(controller->GetPawn());
}
