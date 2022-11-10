#include "09_AI/DeadNotify.h"
#include "AICharacter.h"

FString UDeadNotify::GetNotifyName_Implementation() const
{
	return "Dead";
}

void UDeadNotify::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	Super::Notify(MeshComp, Animation);

	if (!MeshComp) return;
	if (!MeshComp->GetOwner()) return;

	AAICharacter* ai = Cast<AAICharacter>(MeshComp->GetOwner());

	if (ai) ai->Destroy();
}