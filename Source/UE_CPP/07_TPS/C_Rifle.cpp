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

}

void AC_Rifle::BeginPlay()
{
	Super::BeginPlay();
	
}

void AC_Rifle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

AC_Rifle* AC_Rifle::Spawn(UWorld* InWorld, ACharacter* InOwner)
{
	return nullptr;
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
}

void AC_Rifle::Begin_Equip()
{
}

void AC_Rifle::End_Equip()
{
}

void AC_Rifle::UnEquip()
{
}

void AC_Rifle::Begin_UnEquip()
{
}

void AC_Rifle::End_UnEquip()
{
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
