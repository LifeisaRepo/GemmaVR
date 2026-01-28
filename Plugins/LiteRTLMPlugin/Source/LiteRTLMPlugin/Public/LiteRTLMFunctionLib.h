// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "LiteRTLMFunctionLib.generated.h"

// Add a dynamic delegate so Blueprints can "bind" to the AI's response
DECLARE_DYNAMIC_DELEGATE_OneParam(FLiteRTResponseDelegate, FString, Response);

/**
 * 
 */
UCLASS()
class LITERTLMPLUGIN_API ULiteRTLMFunctionLib : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
    // Expose this to Blueprints so you can trigger it from your UI/PlayerController
    UFUNCTION(BlueprintCallable, Category = "LiteRTLM")
    static void InitializeLM(FString ModelPath);

    // This is the function you call from Blueprints
    UFUNCTION(BlueprintCallable, Category = "LiteRTLM")
    static void GenerateLMResponseAsync(FString Prompt, FLiteRTResponseDelegate OnComplete);

    UFUNCTION(BlueprintCallable, Category = "LiteRTLM")
    static void SubmitToolResult(FString FunctionName, FString JsonResults);

    UFUNCTION(BlueprintCallable, Category = "LiteRTLM")
    static void ResetConversation();

    UFUNCTION(BlueprintCallable, Category = "LiteRTLM")
    static bool ParseFunctionCall(FString RawResponse, FString PrefixToChop, FString& OutFunctionName, TMap<FString, FString>& OutParameters);

    UFUNCTION(BlueprintCallable, Category = "LiteRTLM")
    static void ShutdownLM();
	
};
