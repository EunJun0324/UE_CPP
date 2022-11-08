#include "08_Skill/SkillComponent.h"
#include "Player/CPlayer.h"
#include "07_TPS/C_Rifle.h"
#include "Skill.h"
#include "Kismet/GameplayStatics.h"
#include "AttachSkill.h"


USkillComponent::USkillComponent()
{

}


void USkillComponent::BeginPlay()
{
	Super::BeginPlay();
	
	owner = Cast<ACPlayer>(GetOwner());
}

void USkillComponent::OnDestorySkill()
{ 
	owner->PlayAnimMontage(DestorySkillMontage);
}

// ���� �ð��� ������ �ִ� ��ų
void USkillComponent::Begin_DestorySkill()
{
	FTransform transform = owner->GetMesh()->GetSocketTransform("EjectBullet");
	ASkill* skill = owner->GetWorld()->SpawnActorDeferred<ASkill>(DestorySkill, transform ,owner);
	UGameplayStatics::FinishSpawningActor(skill, transform);
}

// ���Ͽ� ���� �Ǿ� �ִ� ��ų
void USkillComponent::Begin_AttachSkill()
{
	FTransform transform = FTransform();
	AAttachSkill* skill = owner->GetWorld()->SpawnActorDeferred<AAttachSkill>(AttachSkill, transform, owner);
	skill->ActionPlayEffect(owner->GetRifle()->GetMesh(), FName("MuzzleFlash"));
	UGameplayStatics::FinishSpawningActor(skill, transform);
}

// Ư�� ��ġ���� �߻��Ǵ� ��ų
void USkillComponent::Begin_LocationSkill()
{
	FTransform transform = owner->GetMesh()->GetSocketTransform("EjectBullet");
	ASkill* skill = owner->GetWorld()->SpawnActorDeferred<ASkill>(LocationSkill, transform, owner);
	skill->ActionPlayEffect(owner->GetWorld(), owner);
	UGameplayStatics::FinishSpawningActor(skill, transform);
}




