#include "03_Collision/C04_Trigger.h"
#include "Components/SceneComponent.h"
#include "Components/BoxComponent.h"
#include "Components/TextRenderComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInstanceConstant.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Kismet/KismetMathLibrary.h"
#include "Components/SpotLightComponent.h"

AC04_Trigger::AC04_Trigger()
{
	Root = CreateDefaultSubobject<USceneComponent>("Root");
	SetRootComponent(Root);
	Box = CreateDefaultSubobject<UBoxComponent>("Box");
	Box->SetupAttachment(Root);
	TextRender = CreateDefaultSubobject<UTextRenderComponent>("TextRender");
	TextRender->SetupAttachment(Root);

	Box->SetRelativeScale3D(FVector(3));
	Box->bHiddenInGame = false;

	TextRender->SetRelativeLocation(FVector(0, 0, 100));
	TextRender->SetRelativeRotation(FRotator(0));
	TextRender->SetRelativeScale3D(FVector(2));
	TextRender->TextRenderColor = FColor::Black;
	TextRender->Text = FText::FromString(FString("C04_Trigger"));
	TextRender->HorizontalAlignment = EHorizTextAligment::EHTA_Center;

	ConstructorHelpers::FObjectFinder<UStaticMesh> mesh(L"StaticMesh'/Game/Mesh/SM_Cube.SM_Cube'");
	
	if (mesh.Succeeded())
	{
		for (int32 i = 0; i < 3; i++)
		{
			FString str;
			str.Append("Meshes");
			str.Append(FString::FromInt(i + 1));
			Meshes[i] = CreateDefaultSubobject<UStaticMeshComponent>(FName(str));
			Meshes[i]->SetupAttachment(Root);
			// SetSimulatePhysics : 물리를 가동시킵니다.
			Meshes[i]->SetSimulatePhysics(true);
			Meshes[i]->SetRelativeLocation(FVector(0, i * 150, 250));
			Meshes[i]->SetStaticMesh(mesh.Object);
		}
	}

	for (int32 i = 0; i < 3; i++)
	{
		FString str;
		str.Append("SpotLights");
		str.Append(FString::FromInt(i + 1));
		SpotLights[i] = CreateDefaultSubobject<USpotLightComponent>(FName(str));
		SpotLights[i]->SetupAttachment(Root);

		SpotLights[i]->SetRelativeLocation(FVector(0, i * 150, 250));
		SpotLights[i]->SetRelativeRotation(FRotator(-90, 0, 0));
		SpotLights[i]->Intensity = 1e+5f;   // 밝기를 10만으로 설정합니다.
		SpotLights[i]->OuterConeAngle = 25; // 원뿔의 각도를 25도로 설정합니다.
	}
}

void AC04_Trigger::BeginPlay()
{
	Super::BeginPlay();
	

}

void AC04_Trigger::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
}

void AC04_Trigger::OnPhysics(int32 index, FLinearColor color)
{
}

void AC04_Trigger::OnLight(int32 index, FLinearColor color)
{
}


