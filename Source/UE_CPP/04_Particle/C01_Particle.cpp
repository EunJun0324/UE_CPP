#include "04_Particle/C01_Particle.h"
#include "Particles/ParticleSystemComponent.h"


AC01_Particle::AC01_Particle()
{
	Particle = CreateDefaultSubobject<UParticleSystemComponent>("Particle");
	// ParticleSystemComponent 를 추가합니다.
	
	// 재생할 Particle 에셋을 로드합니다.
	ConstructorHelpers::FObjectFinder<UParticleSystem> particle(L"ParticleSystem'/Game/Particles/P_Explosion.P_Explosion'");
	if (particle.Succeeded())
	{
		// ParticleSystemComponent 에 재생할 Particle을 설정합니다.
		Particle->SetTemplate(particle.Object);
		// Particle 이 자동으로 재생되지 않도록 설정합니다.
		Particle->bAutoActivate = false;
	}
}

void AC01_Particle::BeginPlay()
{
	Super::BeginPlay();
	
}

void AC01_Particle::ActorBeginOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	Particle->ResetParticles(); // Particle 을 리셋합니다.
	Particle->SetActive(true); // Particle 을 활성화합니다.
}


