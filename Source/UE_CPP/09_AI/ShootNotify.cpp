#include "09_AI/ShootNotify.h"
#include "AICharacter.h"

FString UShootNotify::GetNotifyName_Implementation() const
{
	return "ArrowShoot";
}

void UShootNotify::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	Super::Notify(MeshComp, Animation);

	if (!MeshComp) return;
	if (!MeshComp->GetOwner()) return;

	AAICharacter* ai = Cast<AAICharacter>(MeshComp->GetOwner());

	if (ai) ai->ShootArrow();
}