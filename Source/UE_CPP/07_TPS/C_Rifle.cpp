#include "07_TPS/C_Rifle.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"

#include "Gameframework/Character.h"
#include "Gameframework/CharacterMovementComponent.h"
#include "Gameframework/PlayerController.h"
#include "Gameframework/SpringArmComponent.h"

#include "Components/SkeletalMeshComponent.h"
#include "Components/DecalComponent.h"

#include "Animation/AnimMontage.h"

#include "Camera/CameraComponent.h"

#include "Sound/SoundCue.h"

#include "Particles/ParticleSystemComponent.h"

#include "Materials/MaterialInstanceConstant.h"

#include "C_Bullet.h"
#include "CHUD.h"


AC_Rifle::AC_Rifle()
{
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(L"Mesh");

	ConstructorHelpers::FObjectFinder<USkeletalMesh> mesh(L"SkeletalMesh'/Game/Weapons/Meshes/SK_AR4.SK_AR4'");
	if (mesh.Succeeded()) Mesh->SetSkeletalMesh(mesh.Object);

	ConstructorHelpers::FObjectFinder<UAnimMontage> grabMontage(L"AnimMontage'/Game/Character/Animations/Rifle/Rifle_Grab_Montage.Rifle_Grab_Montage'");
	if (grabMontage.Succeeded()) GrabMontage = grabMontage.Object;

	ConstructorHelpers::FObjectFinder<UAnimMontage> unGrabMontage(L"AnimMontage'/Game/Character/Animations/Rifle/Rifle_UnGrab_Montage.Rifle_UnGrab_Montage'");
	if (unGrabMontage.Succeeded()) UnGrabMontage = unGrabMontage.Object;

	ConstructorHelpers::FObjectFinder<UCurveFloat> curve(L"CurveFloat'/Game/Blueprints/07_TPS/Curve_Aim.Curve_Aim'");
	if (curve.Succeeded()) Curve = curve.Object;

	ConstructorHelpers::FObjectFinder<USoundCue> sound(L"SoundCue'/Game/Sounds/S_RifleShoot_Cue.S_RifleShoot_Cue'");
	if (sound.Succeeded()) MuzzleSoundCue = sound.Object;

	ConstructorHelpers::FObjectFinder<UParticleSystem> flash(L"ParticleSystem'/Game/Particles_Rifle/Particles/VFX_Muzzleflash.VFX_Muzzleflash'");
	if (flash.Succeeded()) FlashParticle = flash.Object;

	ConstructorHelpers::FObjectFinder<UParticleSystem> eject(L"ParticleSystem'/Game/Particles_Rifle/Particles/VFX_Eject_bullet.VFX_Eject_bullet'");
	if (eject.Succeeded()) EjectParticle = eject.Object;

	ConstructorHelpers::FObjectFinder<UParticleSystem> impact(L"ParticleSystem'/Game/Particles_Rifle/Particles/VFX_Impact_Default.VFX_Impact_Default'");
	if (impact.Succeeded()) ImpactParticle = impact.Object;

	ConstructorHelpers::FObjectFinder<UMaterialInstanceConstant> decal(L"MaterialInstanceConstant'/Game/Materials/M_Decal_Inst.M_Decal_Inst'");
	if (decal.Succeeded()) ImpactDecal = decal.Object;

	ConstructorHelpers::FClassFinder<UMatineeCameraShake> cameraShake(L"Blueprint'/Game/Blueprints/07_TPS/BP_CameraShake.BP_CameraShake_C'");
	if (cameraShake.Succeeded()) CameraShake = cameraShake.Class;

	ConstructorHelpers::FClassFinder<AC_Bullet> bullet(L"Blueprint'/Game/Blueprints/07_TPS/BP_Bullet.BP_Bullet_C'");
	if (bullet.Succeeded()) BulletClass = bullet.Class;
}

void AC_Rifle::BeginPlay()
{
	Super::BeginPlay();
	
	// �����ָ� �����մϴ�.
	Owner = Cast<ACharacter>(GetOwner());
	// �������� �޽��� HolsterSocket �� �ش� ���͸� 
	// ��� Ʈ�������� ������ ä �����մϴ�.
	AttachToComponent(Owner->GetMesh(), FAttachmentTransformRules(EAttachmentRule::KeepRelative, true), HolsterSocket);
}

void AC_Rifle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

AC_Rifle* AC_Rifle::Spawn(UWorld* InWorld, ACharacter* InOwner)
{
	FActorSpawnParameters params; // ���� ������ ���� �Ű����� ����Դϴ�.
	params.Owner = InOwner; // �Ű������� ���� InOwner �� �����ַ� �����մϴ�.

	// �Ű������� ���� InWorld �� AC_Rifle �� �����ϰ� �ּҰ��� ��ȯ�մϴ�.
	return InWorld->SpawnActor<AC_Rifle>(params);
}

void AC_Rifle::Zooming(float Output)
{
}

void AC_Rifle::Firing()
{
}

bool AC_Rifle::IsAvalibaleAim()
{
	return false;
}

void AC_Rifle::Equip()
{
	// �����ϰ� �ִ� �����̶�� �Լ��� �����մϴ�.
	if (bEquipping) return;

	// �����ϴ� �ִ� �����̶�� üũ�մϴ�.
	bEquipping = true;
	
	// �������� ���¿��ٸ�
	if (bEquipped == true)
	{
		// ���� ������ �����մϴ�.
		UnEquip();
		return;
	}

	// GrabMontage �� 2�� �ӵ��� ����մϴ�.
	Owner->PlayAnimMontage(GrabMontage, 2);
}

void AC_Rifle::Begin_Equip()
{
	bEquipped = true;

	AttachToComponent(Owner->GetMesh(),
		FAttachmentTransformRules(EAttachmentRule::KeepRelative, true),
		HandSocket);
}

void AC_Rifle::End_Equip()
{ bEquipping = false; }

void AC_Rifle::UnEquip()
{
	Owner->PlayAnimMontage(UnGrabMontage, 2);
}

void AC_Rifle::Begin_UnEquip()
{
	AttachToComponent(Owner->GetMesh(),
		FAttachmentTransformRules(EAttachmentRule::KeepRelative, true),
		HolsterSocket);
	bEquipped = false;
}

void AC_Rifle::End_UnEquip()
{
	bEquipping = false;
}

void AC_Rifle::Begin_Aim()
{
}

void AC_Rifle::End_Aim()
{
}

void AC_Rifle::Begin_Fire()
{
}

void AC_Rifle::End_Fire()
{
}

void AC_Rifle::ToggleAutoFire()
{
}
