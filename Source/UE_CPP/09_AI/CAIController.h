#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "CAIController.generated.h"

UCLASS()
class UE_CPP_API ACAIController : public AAIController
{
	GENERATED_BODY()
	
private :
	UPROPERTY(VisibleDefaultsOnly)
		class UAIPerceptionComponent* Perception;

public :
	ACAIController();

protected :
	virtual void BeginPlay() override;

	virtual void OnPossess(APawn* InPawn) override;
	virtual void OnUnPossess() override;

private :
	UFUNCTION()
		void OnPerceptiongUpdated(const TArray<AActor*>& UpdateActors);

private :
	class AAICharacter* Owner;
	class UAISenseConfig_Sight* SightSense;
};
