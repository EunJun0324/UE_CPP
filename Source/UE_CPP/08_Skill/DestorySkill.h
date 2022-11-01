#pragma once

#include "CoreMinimal.h"
#include "08_Skill/Skill.h"
#include "NiagaraComponent.h"
// #include "Particles/ParticleSystemComponent.h"
#include "DestorySkill.generated.h"

UCLASS()
class UE_CPP_API ADestorySkill : public ASkill
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleDefaultsOnly)
		class USceneComponent* Root;

	UPROPERTY(EditDefaultsOnly)
		class UNiagaraComponent* Niagara;

	// UPROPERTY(EditDefaultsOnly)
	// 	class UParticleSystemComponent* Particle;

public :
	ADestorySkill();

protected :
	virtual void BeginPlay() override;
};
