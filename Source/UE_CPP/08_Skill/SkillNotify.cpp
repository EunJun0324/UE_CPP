#include "08_Skill/SkillNotify.h"
#include "SkillComponent.h"
#include "GameFramework/Character.h"

FString USkillNotify::GetNotifyName_Implementation() const
{
    return "SkillTestNotify";
}

void USkillNotify::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	Super::Notify(MeshComp, Animation);

	if(!MeshComp) return;
	if(!MeshComp->GetOwner()) return;

	ACharacter* character = Cast<ACharacter>(MeshComp->GetOwner());
	if (!character) return;

	TArray<USkillComponent*> components;
	character->GetComponents<USkillComponent>(components);

	for (USkillComponent* component : components)
	{
		if (component->GetName() == "Skill")
		{
			component->Begin_Skill();
			return;
		}
	}
}
