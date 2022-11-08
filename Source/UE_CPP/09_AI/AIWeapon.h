#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AIWeapon.generated.h"

UCLASS()
class UE_CPP_API AAIWeapon : public AActor
{
	GENERATED_BODY()
	
private:
	UPROPERTY(VisibleDefaultsOnly)
		class USkeletalMeshComponent* Mesh;

private:
	class ACharacter* Owner;

public:	
	AAIWeapon();

protected:
	virtual void BeginPlay() override;

public :
	static AAIWeapon* Spawn(UWorld* InWorld, ACharacter* InOwner);
};
