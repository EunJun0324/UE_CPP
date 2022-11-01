#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Skill.generated.h"

UCLASS()
class UE_CPP_API ASkill : public AActor
{
	GENERATED_BODY()
	
public :
	UPROPERTY(EditAnywhere)
		class UFXSystemAsset* ActionEffect;

	UPROPERTY(EditAnywhere)
		FTransform ActionEffectTransform;

	UPROPERTY(EditAnywhere)
		class UFXSystemAsset* HitEffect;

	UPROPERTY(EditAnywhere)
		FTransform HitEffectTransform;

public :
	void ActionPlayEffect(class UWorld* InWorld, class ACharacter* InOwner);
	void ActionPlayEffect(class USkeletalMeshComponent* mesh, FName InSocketName = NAME_None);
	void HitPlayEffect(class UWorld* InWorld, class ACharacter* InOwner);
	void HitPlayEffect(class USkeletalMeshComponent* mesh, FName InSocketName = NAME_None);
	void SendDamage(
		class ACharacter* InAttacker,
		class AActor* InAttackCursor,
		class ACharacter* InOtherCharacter);

public:	
	ASkill();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

};
