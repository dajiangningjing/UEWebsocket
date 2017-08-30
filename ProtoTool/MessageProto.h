#pragma once
#include "Engine.h"
#include "MessageProto.generated.h"
UCLASS()
class  UMessageProtocommandBlueprintLibrary : public UBlueprintFunctionLibrary{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category = "MessageProto")
	static int CMD_TEST();
};

UCLASS(BlueprintType, Blueprintable)
class UTestInfo:public UObject {
GENERATED_BODY()
public:
	UTestInfo();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = MessageProto)
	FString name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = MessageProto)
	TArray<int> score;
};

UCLASS(BlueprintType, Blueprintable)
class UCS_CMD_TEST_body:public UObject {
GENERATED_BODY()
public:
	UCS_CMD_TEST_body();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = MessageProto)
	FString address;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = MessageProto)
	int test;
};

UCLASS(BlueprintType, Blueprintable)
class UCS_CMD_TEST:public UObject {
GENERATED_BODY()
public:
	UCS_CMD_TEST();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = MessageProto)
	FString name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = MessageProto)
	int age;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = MessageProto)
	UTestInfo* testinfo;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = MessageProto)
	UCS_CMD_TEST_body* body;
};

