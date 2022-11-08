#include "09_AI/AIAnim.h"
#include "GameFramework/Character.h"

void UAIAnim::NativeBeginPlay()
{
    Super::NativeBeginPlay();

    Owner = Cast<ACharacter>(TryGetPawnOwner());
}

void UAIAnim::NativeUpdateAnimation(float DelatSeconds)
{
    Super::NativeUpdateAnimation(DelatSeconds);

    if (!Owner) return;

    Speed = Owner->GetVelocity().Size2D();
}
