// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CharacterBase.generated.h"

UCLASS(Abstract)
class PROJECT_MAGE_API ACharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	ACharacterBase();

protected:
	virtual void BeginPlay() override;

#pragma region TObjectPtr Note
	// 원시 포인터와 동일하게 작동하지만 에디터에서 액세스 추적 및 선택 적 지연 로드 등 다양한 기능이 추가
	// 액세스 추적: 얼마나 자주 엑세스 되는지, 얼마나 자주 참조 해제되는지 추적 가능
	// 지연 로딩: 프로그램에서 실제 필요하거나 사용할 때까지 에셋을 로드하지 않음을 의미
#pragma endregion
	UPROPERTY(EditAnywhere, Category = "Combat")
	TObjectPtr<USkeletalMeshComponent> Weapon;
};
