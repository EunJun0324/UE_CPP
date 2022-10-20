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

	OnTimelineFloat.BindUFunction(this, "Zooming");
	Timeline.AddInterpFloat(Curve, OnTimelineFloat);
	Timeline.SetPlayRate(200);
}

void AC_Rifle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Timeline.TickTimeline(DeltaTime);

	if (!bAiming) return;
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
	UCameraComponent* camera = Cast<UCameraComponent>(Owner->GetComponentByClass(UCameraComponent::StaticClass()));
	camera->FieldOfView = Output;
}

void AC_Rifle::Firing()
{

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
{ bEquipping = false; }

bool AC_Rifle::IsAvalibaleAim()
{
	USpringArmComponent* springArm = Cast<USpringArmComponent>(Owner->GetComponentByClass(USpringArmComponent::StaticClass()));
	UCameraComponent*       camera = Cast<UCameraComponent>   (Owner->GetComponentByClass(UCameraComponent::StaticClass()));

	APlayerController* controller = Owner->GetController<APlayerController>();

	return springArm && camera && controller;
}

void AC_Rifle::Begin_Aim()
{
	if (!bEquipped) return;
	if (bEquipping) return;
	if (!IsAvalibaleAim()) return;

	bAiming = true;

	// controller �� z ȸ������ ����մϴ�.
	Owner->bUseControllerRotationYaw = true;
	// ĳ������ �̵� ���⿡ ���� ȸ������ �ʽ��ϴ�.
	Owner->GetCharacterMovement()->bOrientRotationToMovement = false;

	USpringArmComponent* springArm = Cast<USpringArmComponent>(Owner->GetComponentByClass(USpringArmComponent::StaticClass()));

	springArm->TargetArmLength = 100;
	springArm->SocketOffset = FVector(0, 30, 10);

	Timeline.PlayFromStart();

	Owner->GetController<APlayerController>()->GetHUD<ACHUD>()->Visible();
}

void AC_Rifle::End_Aim()
{
	if (!bAiming) return;

	bAiming = false;

	Owner->bUseControllerRotationYaw = false;
	Owner->GetCharacterMovement()->bOrientRotationToMovement = true;

	USpringArmComponent* springArm = Cast<USpringArmComponent>(Owner->GetComponentByClass(USpringArmComponent::StaticClass()));

	springArm->TargetArmLength = 200;
	springArm->SocketOffset = FVector(0, 60, 0);

	Timeline.ReverseFromEnd();

	Owner->GetController<APlayerController>()->GetHUD<ACHUD>()->InVisible();
}

void AC_Rifle::Begin_Fire()
{
	if (!bEquipped) return;
	if (bEquipping) return;
	if (!bAiming)   return;
	if (bFiring)    return;

	bFiring = true;

	// ���� ���� ���¶��
	if (bAutoFiring)
	{
		// Ű�� �� ������ Firing �� 0.1�ʸ��� �����ϵ��� �����մϴ�.
		GetWorld()->GetTimerManager().SetTimer(AutoFireHandle, this,
			&AC_Rifle::Firing, 0.1, true, 0);

		return;
	}
	Firing();
}

void AC_Rifle::End_Fire()
{
	bFiring = false;

	if (bAutoFiring)
		GetWorld()->GetTimerManager().ClearTimer(AutoFireHandle);
}

void AC_Rifle::ToggleAutoFire()
{ if (!bFiring) bAutoFiring = !bAutoFiring; }

