#include "08_Skill/DestorySkill.h"

ADestorySkill::ADestorySkill()
{
    Root = CreateDefaultSubobject<USceneComponent>("Root");
    Niagara = CreateDefaultSubobject<UNiagaraComponent>("Niagara");
    Niagara->SetupAttachment(Root);
}

void ADestorySkill::BeginPlay()
{
    Super::BeginPlay();
 
    FTransform transform = ActionEffectTransform;

    FVector location = GetActorLocation();
    location += GetActorRotation().RotateVector(transform.GetLocation());
    transform.SetLocation(location);
    SetActorLocation(location);

    FRotator rotation = GetActorRotation();
    rotation += FRotator(transform.GetRotation());
    transform.SetRotation(FQuat(rotation));
    SetActorRotation(FQuat(rotation));

    SetLifeSpan(0.3f);
}
