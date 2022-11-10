#include "09_AI/BTServiceAI.h"
#include "Player/CPlayer.h"
#include "AICharacter.h"
#include "CAIController.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "Kismet/KismetMathLibrary.h"

UBTServiceAI::UBTServiceAI()
{ NodeName = "AI"; }

void UBTServiceAI::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
    Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

    ACAIController* controller = Cast<ACAIController>(OwnerComp.GetOwner());
    AAICharacter* ai = Cast<AAICharacter>(controller->GetPawn());

    if (ai->GetIsHitted())
    {
        controller->ChanageType(EBehaviorType::Hitted);
        return;
    }

    ACPlayer* player = controller->GetTargetPlayer();

    if (!player)
    {
        controller->ChanageType(EBehaviorType::Wait);
        return;
    }

    float distance = ai->GetDistanceTo(player);

    if (distance < AttackRange)
    {
        FRotator rot = UKismetMathLibrary::FindLookAtRotation(ai->GetActorLocation(), player->GetActorLocation());
        ai->SetActorRotation(rot);
        controller->ChanageType(EBehaviorType::Attack);
        return;
    }

    controller->ChanageType(EBehaviorType::Approach);
}
