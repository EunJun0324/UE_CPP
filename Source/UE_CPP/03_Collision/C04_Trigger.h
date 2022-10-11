#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "C04_Trigger.generated.h"

/*
	1. CharacterMovementComponent 서술
	2. StaticMesh 와 SkeletalMesh 차이 서술
	3. Hit 와 Overlap 충돌 방식에 대하여 서술
	4. Actor , Pawn , Character Class 차이 서술
	5. SceneComponent 와 ActorComponent 차이 서술
*/

UCLASS()
class UE_CPP_API AC04_Trigger : public AActor
{
	GENERATED_BODY()
	
private:
	UPROPERTY(VisibleDefaultsOnly)
		class USceneComponent* Root;

	UPROPERTY(VisibleDefaultsOnly)
		class UBoxComponent* Box;

	UPROPERTY(VisibleDefaultsOnly)
		class UTextRenderComponent* TextRender;

	UPROPERTY(VisibleDefaultsOnly)
		class UStaticMeshComponent* Meshes[3];

	UPROPERTY(VisibleDefaultsOnly)
		class USpotLightComponent* SpotLights[3];

public:	
	AC04_Trigger();

protected:
	virtual void BeginPlay() override;

private:
	UFUNCTION()
		void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex,
			bool bFromSweep,
			const FHitResult& SweepResult);

private :
	// 박스들의 색상을 전환하고 낙하하도록하는 함수
	void OnPhysics(int32 index, FLinearColor color); 

	// 스포트 라이트의 색상을 전환하는 함수
	void OnLight(int32 index, FLinearColor color);

private :
	class UMaterialInstanceDynamic* Materials[3];
	FVector WorldLocations[3];	// 초기에 설정되어 있던 상자들의 위치값 저장 변수
};
