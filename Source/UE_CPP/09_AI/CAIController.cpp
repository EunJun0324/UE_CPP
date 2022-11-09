#include "09_AI/CAIController.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Player/CPlayer.h"
#include "AICharacter.h"

ACAIController::ACAIController()
{
    Perception= CreateDefaultSubobject<UAIPerceptionComponent>("Perception");
    SightSense = CreateDefaultSubobject<UAISenseConfig_Sight>("Sight");

    SightSense->SightRadius = 600;
    SightSense->LoseSightRadius = 800;
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
}

void ACAIController::OnUnPossess()
{
    Super::OnUnPossess();
}

void ACAIController::OnPerceptiongUpdated(const TArray<AActor*>& UpdateActors)
{
}
