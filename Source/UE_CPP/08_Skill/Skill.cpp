#include "08_Skill/Skill.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystem.h"
#include "Particles/ParticleSystemComponent.h"

#include "NiagaraSystem.h"
#include "NiagaraFunctionLibrary.h"

void ASkill::ActionPlayEffect(UWorld* InWorld, ACharacter* InOwner)
{
	if (!ActionEffect) return;

	FTransform transform = ActionEffectTransform;

	FVector ownerLocation = InOwner->GetActorLocation();
	ownerLocation += InOwner->GetActorRotation().RotateVector(transform.GetLocation());
	transform.SetLocation(ownerLocation);

	FRotator rotation = InOwner->GetActorRotation();
	rotation += FRotator(transform.GetRotation());
	transform.SetRotation(FQuat(rotation));

	UParticleSystem* particle = Cast<UParticleSystem>(ActionEffect);
	UNiagaraSystem* niagara = Cast<UNiagaraSystem>(ActionEffect);

	if (particle)
		UGameplayStatics::SpawnEmitterAtLocation(InWorld, particle, transform);
	if (niagara)
		UNiagaraFunctionLibrary::SpawnSystemAtLocation(
			InWorld,
			niagara, 
			transform.GetLocation(), 
			FRotator(transform.GetRotation()), 
			transform.GetScale3D());
}

void ASkill::ActionPlayEffect(USkeletalMeshComponent* mesh, FName InSocketName)
{
	if (!ActionEffect) return;

	if (!mesh) return;

	AActor* owner = mesh->GetOwner();
	UWorld* world = owner->GetWorld();

	UParticleSystem* particle = Cast<UParticleSystem>(ActionEffect);
	UNiagaraSystem*  niagara = Cast<UNiagaraSystem>(ActionEffect);

	if (particle)
		UGameplayStatics::SpawnEmitterAttached(
			particle, 
			mesh, 
			InSocketName, 
			ActionEffectTransform.GetLocation(),
			FRotator(ActionEffectTransform.GetRotation()),
			ActionEffectTransform.GetScale3D());

	if (niagara)
		UNiagaraFunctionLibrary::SpawnSystemAttached(
			niagara,
			mesh,
			InSocketName,
			ActionEffectTransform.GetLocation(),
			FRotator(ActionEffectTransform.GetRotation()),
			ActionEffectTransform.GetScale3D(),
			EAttachLocation::KeepRelativeOffset,
			true,
			ENCPoolMethod::None);
}

void ASkill::HitPlayEffect(UWorld* InWorld, ACharacter* InOwner)
{
	if (!HitEffect) return;

	FTransform transform = HitEffectTransform;

	FVector ownerLocation = InOwner->GetActorLocation();
	ownerLocation += InOwner->GetActorRotation().RotateVector(transform.GetLocation());
	transform.SetLocation(ownerLocation);

	FRotator rotation = InOwner->GetActorRotation();
	rotation += FRotator(transform.GetRotation());
	transform.SetRotation(FQuat(rotation));

	UParticleSystem* particle = Cast<UParticleSystem>(HitEffect);
	UNiagaraSystem* niagara = Cast<UNiagaraSystem>(HitEffect);

	if (particle)
		UGameplayStatics::SpawnEmitterAtLocation(InWorld, particle, transform);
	if (niagara)
		UNiagaraFunctionLibrary::SpawnSystemAtLocation(
			InWorld,
			niagara,
			transform.GetLocation(),
			FRotator(transform.GetRotation()),
			transform.GetScale3D());
}

void ASkill::HitPlayEffect(USkeletalMeshComponent* mesh, FName InSocketName)
{
	if (!HitEffect) return;

	if (!mesh) return;

	AActor* owner = mesh->GetOwner();
	UWorld* world = owner->GetWorld();

	UParticleSystem* particle = Cast<UParticleSystem>(HitEffect);
	UNiagaraSystem* niagara = Cast<UNiagaraSystem>(HitEffect);

	if (particle)
		UGameplayStatics::SpawnEmitterAttached(
			particle,
			mesh,
			InSocketName,
			HitEffectTransform.GetLocation(),
			FRotator(HitEffectTransform.GetRotation()),
			HitEffectTransform.GetScale3D());

	if (niagara)
		UNiagaraFunctionLibrary::SpawnSystemAttached(
			niagara,
			mesh,
			InSocketName,
			HitEffectTransform.GetLocation(),
			FRotator(HitEffectTransform.GetRotation()),
			HitEffectTransform.GetScale3D(),
			EAttachLocation::KeepRelativeOffset,
			true,
			ENCPoolMethod::None);
}

void ASkill::SendDamage(ACharacter* InAttacker, AActor* InAttackCursor, ACharacter* InOtherCharacter)
{
}

ASkill::ASkill()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ASkill::BeginPlay()
{
	Super::BeginPlay();
	SetLifeSpan(0.5f);
}

void ASkill::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

