#include "09_AI/EndAttack.h"
#include "AICharacter.h"

FString UEndAttack::GetNotifyName_Implementation() const
{
	return "EndAttack";
}

void UEndAttack::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	Super::Notify(MeshComp, Animation);

	if (!MeshComp) return;
	if (!MeshComp->GetOwner()) return;

	AAICharacter* ai = Cast<AAICharacter>(MeshComp->GetOwner());

	if (ai) ai->EndAttack();
}