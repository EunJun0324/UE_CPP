#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AIArrow.generated.h"

UCLASS()
class UE_CPP_API AAIArrow : public AActor
{
	GENERATED_BODY()
	
private:
	UPROPERTY(VisibleDefaultsOnly)
		class UCapsuleComponent* Capsule;

	UPROPERTY(VisibleDefaultsOnly)
		class UStaticMeshComponent* Mesh;

	UPROPERTY(EditDefaultsOnly)
		class UProjectileMovementComponent* Projectile;

public:	
	AAIArrow();

protected:
	virtual void BeginPlay() override;

private:
	UFUNCTION()
		void OnBeginOverlap(AActor* OverlappedActor, AActor* OtherActor);

public:
	void Shoot(const FVector& InDirection);
};
