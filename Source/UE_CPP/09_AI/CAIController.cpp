#include "09_AI/CAIController.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Player/CPlayer.h"
#include "AICharacter.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"


ACAIController::ACAIController()
{
    Perception= CreateDefaultSubobject<UAIPerceptionComponent>("Perception");
    SightSense = CreateDefaultSubobject<UAISenseConfig_Sight>("Sight");

    SightSense->SightRadius = 800;
    SightSense->LoseSightRadius = 1000;
    SightSense->PeripheralVisionAngleDegrees = 45;
    SightSense->SetMaxAge(2);

    SightSense->DetectionByAffiliation.bDetectEnemies    = true;
    SightSense->DetectionByAffiliation.bDetectNeutrals   = false;
    SightSense->DetectionByAffiliation.bDetectFriendlies = false;

    SightSense->AutoSuccessRangeFromLastSeenLocation = 3;

    Perception->ConfigureSense(*SightSense);
    Perception->SetDominantSense(*SightSense->GetSenseImplementation());
}

void ACAIController::BeginPlay()
{
    Super::BeginPlay();

    Perception->OnPerceptionUpdated.AddDynamic(this, &ACAIController::OnPerceptiongUpdated);
}

void ACAIController::OnPossess(APawn* InPawn)
{
    Super::OnPossess(InPawn);
    Owner = Cast<AAICharacter>(InPawn);
    SetGenericTeamId(Owner->GetTeamID());

    UseBlackboard(Owner->GetBehaviorTree()->BlackboardAsset, Blackboard);

    RunBehaviorTree(Owner->GetBehaviorTree());
}

void ACAIController::OnUnPossess()
{
    Super::OnUnPossess();
}

void ACAIController::OnPerceptiongUpdated(const TArray<AActor*>& UpdateActors)
{
    TArray<AActor*> actors;
    Perception->GetCurrentlyPerceivedActors(NULL, actors);

    ACPlayer* player = nullptr;

    for (AActor* actor : actors)
    {
        player = Cast<ACPlayer>(actor);
        if (player) break;
    }

    Blackboard->SetValueAsObject("Player", player);
}

void ACAIController::ChanageType(EBehaviorType InType)
{ Blackboard->SetValueAsEnum("Behavior", (uint8)InType); }

ACPlayer* ACAIController::GetTargetPlayer()
{
    return Cast<ACPlayer>(Blackboard->GetValueAsObject("Player"));
}
