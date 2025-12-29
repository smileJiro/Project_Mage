// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/MagePlayerController.h"
#include "EnhancedInputSubsystems.h"

AMagePlayerController::AMagePlayerController()
{
#pragma region Note: bReplicates 
	// 해당 컨트롤러는 네트워크에서 복제 대상임을 명시한다.
	// bReplicates는 해당 Actor가 서버 -> 클라이언트로 네트워크 복제될지 여부를 결정
	// Playercontroller는 서버 + 자기 자신 클라이언트에 존재
	// 서버에는 다른 모든 Playercontroller가 존재
	// 각 클라이언트에는 자기 Playercontroller만 존재
	// 다른 플레이어의 Playercontroller는 보이지 않는다.
	// 해당 코드의 의미: 이 Playercontroller는 서버에 생성되고, 해당 플레이어의 클라에도 복제된다.
	// 사실 bReplicates = true는 기본값이다 -> 그러나 명시적으로 작성해주는 것
#pragma endregion
	bReplicates = true;
}

void AMagePlayerController::BeginPlay()
{
	Super::BeginPlay();

	check(MageContext); // check -> assert

	// Subsystem 연결
#pragma region Note: Subsystem
	// UE Subsystem: 엔진이 관리하는 전역/범위 기반 서비스 객체로 이해
	// Subsystem은 수명이 명확한 서비스 객체이다 -> 어디까지 살아있는가로 구분
	// LocalPlayerSubsystem은 수명이 LocalPlayer의 수명을 따르는거지
	// 정리: 지정한 범위(Scope)안에서 하나이며, 엔진이 책임지고 관리해주는 싱글톤의 보완
#pragma endregion
#pragma region Note: ULocalPlayer::GetSubsystem
	// ULocalPlayer::GetSubsystem -> 존재하면 반환, 없으면 생성해서 반환 (일반적인 싱글톤처럼 보이지만 조금 다르다.)
	// 각각의 LocalPlayer마다 SubsystemCollection을 하나씩 개별 소유한다.
	// SubsystemCollection은 서브시스템을 TMap으로 관리하는 컨테이너 객체이다.
#pragma endregion
	UEnhancedInputLocalPlayerSubsystem* Subsystem =
		ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(Subsystem);
	Subsystem->AddMappingContext(MageContext, 0);


	// Mouse Cursor에 대한 InputMode 설정
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;
	FInputModeGameAndUI InputmodeData;
	InputmodeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputmodeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputmodeData);
}
