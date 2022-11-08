#include "08_Skill/LocationSkillNotify.h"


#include "SkillComponent.h"
#include "GameFramework/Character.h"

FString ULocationSkillNotify::GetNotifyName_Implementation() const
{
	return "AttachSkillTest";
}

void ULocationSkillNotify::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	Super::Notify(MeshComp, Animation);

	if (!MeshComp) return;
	if (!MeshComp->GetOwner()) return;

	ACharacter* character = Cast<ACharacter>(MeshComp->GetOwner());
	if (!character) return;

	TArray<USkillComponent*> components;
	character->GetComponents<USkillComponent>(components);

	for (USkillComponent* component : components)
	{
		if (component->GetName() == "Skill")
		{
			component->Begin_LocationSkill();
			return;
		}
	}
}