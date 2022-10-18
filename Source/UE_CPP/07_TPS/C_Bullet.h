#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "C_Bullet.generated.h"

UCLASS()
class UE_CPP_API AC_Bullet : public AActor
{
	GENERATED_BODY()
	
public:	
	AC_Bullet();

protected:
	virtual void BeginPlay() override;
};
