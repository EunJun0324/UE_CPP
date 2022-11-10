#include "09_AI/AIArrow.h"
#include "Components/StaticMeshComponent.h"
#include "Components/CapsuleComponent.h"
#include "Gameframework/ProjectileMovementComponent.h"

AAIArrow::AAIArrow()
{
	Capsule = CreateDefaultSubobject<UCapsuleComponent>("Capsule");
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	Projectile = CreateDefaultSubobject<UProjectileMovementComponent>("Projectile");

	Capsule->SetRelativeRotation(FRotator(90, 0, 0));
	Capsule->SetCapsuleHalfHeight(30);
	Capsule->SetCapsuleRadius(2);

	ConstructorHelpers::FObjectFinder<UStaticMesh> mesh(L"StaticMesh'/Game/Skeleton_archer/mesh/SM_arrow.SM_arrow'");
	if (mesh.Succeeded()) Mesh->SetStaticMesh(mesh.Object);

	Mesh->SetupAttachment(Capsule);
	Mesh->SetRelativeLocation(FVector(0, 0, -25.f));

	Projectile->InitialSpeed = 1000; 
	Projectile->MaxSpeed = 1000;     
	Projectile->ProjectileGravityScale = 0;
}

void AAIArrow::BeginPlay()
{
	Super::BeginPlay();
	OnActorBeginOverlap.AddDynamic(this, &AAIArrow::OnBeginOverlap);
}

void AAIArrow::OnBeginOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	Destroy();
}

void AAIArrow::Shoot(const FVector& InDirection)
{
	Projectile->Velocity = InDirection * Projectile->InitialSpeed;
}

