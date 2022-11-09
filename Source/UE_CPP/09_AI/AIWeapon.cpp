#include "09_AI/AIWeapon.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/Character.h"
#include "AIArrow.h"


AAIWeapon::AAIWeapon()
{
	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(L"Mesh");

	ConstructorHelpers::FObjectFinder<USkeletalMesh> mesh(L"SkeletalMesh'/Game/Skeleton_archer/mesh/weapon/SK_bow.SK_bow'");
	if (mesh.Succeeded()) Mesh->SetSkeletalMesh(mesh.Object);

	ConstructorHelpers::FClassFinder<AAIArrow> aiArrow(L"Blueprint'/Game/Blueprints/09_AI/BP_AIArrow.BP_AIArrow_C'");
	if (aiArrow.Succeeded()) ArrowClass = aiArrow.Class;
}

void AAIWeapon::BeginPlay()
{
	Super::BeginPlay();
	
	Owner = Cast<ACharacter>(GetOwner());
	// 소유주의 메시의 HolsterSocket 에 해당 액터를 
	// 상대 트랜스폼을 유지한 채 장착합니다.
	AttachToComponent(Owner->GetMesh(), FAttachmentTransformRules(EAttachmentRule::KeepRelative, true), L"WeaponSocket");
}


AAIWeapon* AAIWeapon::Spawn(UWorld* InWorld, ACharacter* InOwner)
{
	FActorSpawnParameters params; // 액터 스폰에 대한 매개변수 목록입니다.
	params.Owner = InOwner; // 매개변수로 들어온 InOwner 를 소유주로 설정합니다.

	// 매개변수로 들어온 InWorld 에 AC_Rifle 을 생성하고 주소값을 반환합니다.
	return InWorld->SpawnActor<AAIWeapon>(params);
}

void AAIWeapon::Begin_Fire()
{
	if (ArrowClass)
	{
		FVector arrowLocation = Mesh->GetSocketLocation("Fire");
		FVector spawnLocation = arrowLocation + Owner->GetActorForwardVector();
		FRotator spawnRotation = Owner->GetActorRotation() + FRotator(0, 180, 0);
		AAIArrow* arrow = GetWorld()->SpawnActor<AAIArrow>(
			ArrowClass, arrowLocation, spawnRotation);
		arrow->Shoot(Owner->GetActorForwardVector());
	}
}

void AAIWeapon::End_Fire()
{
}
