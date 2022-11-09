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
	// �������� �޽��� HolsterSocket �� �ش� ���͸� 
	// ��� Ʈ�������� ������ ä �����մϴ�.
	AttachToComponent(Owner->GetMesh(), FAttachmentTransformRules(EAttachmentRule::KeepRelative, true), L"WeaponSocket");
}


AAIWeapon* AAIWeapon::Spawn(UWorld* InWorld, ACharacter* InOwner)
{
	FActorSpawnParameters params; // ���� ������ ���� �Ű����� ����Դϴ�.
	params.Owner = InOwner; // �Ű������� ���� InOwner �� �����ַ� �����մϴ�.

	// �Ű������� ���� InWorld �� AC_Rifle �� �����ϰ� �ּҰ��� ��ȯ�մϴ�.
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
