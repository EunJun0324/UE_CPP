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

// 제거 시간이 정해져 있는 스킬
void USkillComponent::Begin_DestorySkill()
{
	FTransform transform = owner->GetMesh()->GetSocketTransform("EjectBullet");
	ASkill* skill = owner->GetWorld()->SpawnActorDeferred<ASkill>(DestorySkill, transform ,owner);
	UGameplayStatics::FinishSpawningActor(skill, transform);
}

// 소켓에 장착 되어 있는 스킬
void USkillComponent::Begin_AttachSkill()
{
	FTransform transform = FTransform();
	AAttachSkill* skill = owner->GetWorld()->SpawnActorDeferred<AAttachSkill>(AttachSkill, transform, owner);
	skill->ActionPlayEffect(owner->GetRifle()->GetMesh(), FName("MuzzleFlash"));
	UGameplayStatics::FinishSpawningActor(skill, transform);
}

// 특정 위치에서 발생되는 스킬
void USkillComponent::Begin_LocationSkill()
{
	FTransform transform = owner->GetMesh()->GetSocketTransform("EjectBullet");
	ASkill* skill = owner->GetWorld()->SpawnActorDeferred<ASkill>(LocationSkill, transform, owner);
	skill->ActionPlayEffect(owner->GetWorld(), owner);
	UGameplayStatics::FinishSpawningActor(skill, transform);
}




