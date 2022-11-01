#include "08_Skill/SkillComponent.h"
#include "Player/CPlayer.h"
#include "07_TPS/C_Rifle.h"
#include "Skill.h"
#include "Kismet/GameplayStatics.h"


USkillComponent::USkillComponent()
{

}


void USkillComponent::BeginPlay()
{
	Super::BeginPlay();
	
	owner = Cast<ACPlayer>(GetOwner());
}

void USkillComponent::OnSkill()
{ 
	owner->PlayAnimMontage(SkillMontage); 
}

void USkillComponent::Begin_Skill()
{
	FTransform transform = owner->GetMesh()->GetSocketTransform("EjectBullet");

	ASkill* skill = owner->GetWorld()->SpawnActorDeferred<ASkill>(Skill, transform ,owner);
	skill->ActionPlayEffect(owner->GetWorld(), owner);
	UGameplayStatics::FinishSpawningActor(skill, transform);
}




