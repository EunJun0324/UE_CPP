#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "CAIController.generated.h"

UENUM(BlueprintType)
enum class EBehaviorType : uint8
{
	Wait, Attack, Hitted, Approach, Max,
};

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

public :
	void ChanageType(EBehaviorType InType);

	class ACPlayer* GetTargetPlayer();

private :
	class AAICharacter* Owner;
	class UAISenseConfig_Sight* SightSense;
};
