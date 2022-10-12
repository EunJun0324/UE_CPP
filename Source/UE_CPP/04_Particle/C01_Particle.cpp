#include "04_Particle/C01_Particle.h"
#include "Particles/ParticleSystemComponent.h"


AC01_Particle::AC01_Particle()
{
	Particle = CreateDefaultSubobject<UParticleSystemComponent>("Particle");
	// ParticleSystemComponent �� �߰��մϴ�.
	
	// ����� Particle ������ �ε��մϴ�.
	ConstructorHelpers::FObjectFinder<UParticleSystem> particle(L"ParticleSystem'/Game/Particles/P_Explosion.P_Explosion'");
	if (particle.Succeeded())
	{
		// ParticleSystemComponent �� ����� Particle�� �����մϴ�.
		Particle->SetTemplate(particle.Object);
		// Particle �� �ڵ����� ������� �ʵ��� �����մϴ�.
		Particle->bAutoActivate = false;
	}
}

void AC01_Particle::BeginPlay()
{
	Super::BeginPlay();
	
}

void AC01_Particle::ActorBeginOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	Particle->ResetParticles(); // Particle �� �����մϴ�.
	Particle->SetActive(true); // Particle �� Ȱ��ȭ�մϴ�.
}


