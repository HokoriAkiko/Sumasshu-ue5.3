// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintPlatformLibrary.h"
#include "MyPlatformGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class SUMASSHU_API UMyPlatformGameInstance : public UPlatformGameInstance
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	void handle_vibration();
};