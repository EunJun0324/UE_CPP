#include "01_Spawn/C02_Mesh.h"

AC02_Mesh::AC02_Mesh()
{
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");

	ConstructorHelpers::FObjectFinder<UStaticMesh> mesh(L"StaticMesh'/Game/Mesh/SM_Cube.SM_Cube'");
	if (mesh.Succeeded()) Mesh->SetStaticMesh(mesh.Object);
}

void AC02_Mesh::BeginPlay()
{
	Super::BeginPlay();
	
}

void AC02_Mesh::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

