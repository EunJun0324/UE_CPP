#include "09_AI/AICharacter.h"
#include "AIWeapon.h"

AAICharacter::AAICharacter()
{
	ConstructorHelpers::FObjectFinder<USkeletalMesh> mesh(L"SkeletalMesh'/Game/Skeleton_archer/mesh/SK_Skeleton_archer.SK_Skeleton_archer'");
	GetMesh()->SetSkeletalMesh(mesh.Object);
	GetMesh()->SetRelativeLocation(FVector(0, 0, -90));
	GetMesh()->SetRelativeRotation(FRotator(0, -90, 0));

	ConstructorHelpers::FClassFinder<UAnimInstance> anim(L"AnimBlueprint'/Game/Blueprints/09_AI/ABP_AI.ABP_AI_C'");
	GetMesh()->SetAnimClass(anim.Class);
}

void AAICharacter::BeginPlay()
{
	Super::BeginPlay();

	Weapon = AAIWeapon::Spawn(GetWorld(), this);
}



