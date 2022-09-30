#include "Player/CPlayer.h"

#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

#include "Components/SkeletalMeshComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "Components/ArrowComponent.h"

#include "Camera/CameraComponent.h"


ACPlayer::ACPlayer()
{
	SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	SpringArm->SetupAttachment(GetCapsuleComponent());
	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	Camera->SetupAttachment(SpringArm);

	bUseControllerRotationYaw = false;
	// Controller �� yaw ���� ������� �ʵ��� �����մϴ�.
	GetCharacterMovement()->bOrientRotationToMovement = true;
	// Actor �� �̵��ϴ� ���� �������� ȸ���ϴ� ���� �����մϴ�.
	GetCharacterMovement()->MaxWalkSpeed = 400;
	// ĳ������ �̵��ӵ��� 400���� �����մϴ�.

	ConstructorHelpers::FObjectFinder<USkeletalMesh> mesh(L"");
	if (mesh.Succeeded()) GetMesh()->SetSkeletalMesh(mesh.Object);
	GetMesh()->SetRelativeLocation(FVector(0, 0, -90));
	GetMesh()->SetRelativeRotation(FRotator(0, -90, 0));

	SpringArm->SetRelativeLocation(FVector(0, 0, 60));
	// SpringArm �� z ��ġ�� 60 ���� �����մϴ�.
	SpringArm->TargetArmLength = 200;
	// SpringArm �� ���̸� 200���� �����մϴ�.
	SpringArm->bUsePawnControlRotation = true;
	// SpringArm �� ��Ʈ�ѷ��� ȸ������ ����ϵ��� �մϴ�.
	SpringArm->SocketOffset = FVector(0, 60, 0);
	// SpringArm �� ���� ������ y ��ġ�� 60 ���� �����մϴ�.

}

void ACPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ACPlayer::OnMoveForward(float axis)
{
}

void ACPlayer::OnMoveRight(float axis)
{
}

void ACPlayer::OnHorizontalLook(float axis)
{
}

void ACPlayer::OnVerticalLook(float axis)
{
}

