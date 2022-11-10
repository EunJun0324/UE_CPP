#include "09_AI/EndHitNotify.h"
#include "AICharacter.h"

FString UEndHitNotify::GetNotifyName_Implementation() const
{
	return "EndHit";
}

void UEndHitNotify::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	Super::Notify(MeshComp, Animation);

	if (!MeshComp) return;
	if (!MeshComp->GetOwner()) return;

	AAICharacter* ai = Cast<AAICharacter>(MeshComp->GetOwner());

	if (ai) ai->EndHitted();
}