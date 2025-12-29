// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MagePlayerController.generated.h"

// Forward Declarations
class UInputMappingContext;

// 플레이어 기본 입력 로직을 처리하는 클래스
UCLASS(Blueprintable)
class PROJECT_MAGE_API AMagePlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AMagePlayerController();

protected:
	void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputMappingContext> MageContext;
};
