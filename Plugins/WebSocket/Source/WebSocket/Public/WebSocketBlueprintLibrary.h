/*
* uewebsocket - unreal engine 4 websocket plugin
*
* Copyright (C) 2017 feiwu <feixuwu@outlook.com>
*
*  This library is free software; you can redistribute it and/or
*  modify it under the terms of the GNU Lesser General Public
*  License as published by the Free Software Foundation:
*  version 2.1 of the License.
*
*  This library is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
*  Lesser General Public License for more details.
*
*  You should have received a copy of the GNU Lesser General Public
*  License along with this library; if not, write to the Free Software
*  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
*  MA  02110-1301  USA
*/

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "WebSocketBase.h"
#include "Runtime/Json/Public/Dom/JsonObject.h"
#include "Runtime/JsonUtilities/Public/JsonObjectConverter.h"
#include "Runtime/JsonUtilities/Public/JsonObjectWrapper.h"
#include "Internationalization/Culture.h"
#include "UObject/TextProperty.h"
#include "UObject/PropertyPortFlags.h"
#include "WebSocketBlueprintLibrary.generated.h"


UCLASS(BlueprintType, Blueprintable)
class UTest :public UObject
{
public:

	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Test)
	FString mName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Test)
	int mAge;
};


UCLASS(BlueprintType, Blueprintable)
class UTest2 :public UObject
{
public:

	GENERATED_BODY()

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Test)
		FString mName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Test)
		int mAge;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Test)
	UTest* mTest;
};


USTRUCT(BlueprintType)
struct FWebSocketHeaderPair
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(Category = WebSocket, EditAnywhere, BlueprintReadWrite)
	FString key;

	UPROPERTY(Category = WebSocket, EditAnywhere, BlueprintReadWrite)
	FString value;
};


/**
 * 
 */
UCLASS()
class WEBSOCKET_API UWebSocketBlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintCallable, Category = "WebSocket")
	static UWebSocketBase* Connect(const FString& url);

	UFUNCTION(BlueprintCallable, Category = "WebSocket")
	static UWebSocketBase* ConnectWithHeader(const FString& url, const TArray<FWebSocketHeaderPair>& header);

	UFUNCTION(BlueprintCallable, Category = "WebSocket")
	static UObject* JsonToObject(const FString& data, UClass * StructDefinition, bool checkAll);
	
	UFUNCTION(BlueprintCallable, Category = "WebSocket")
	static bool GetJsonIntField(const FString& data, const FString& key, int& iValue);

	UFUNCTION(BlueprintCallable, Category = "WebSocket")
	static bool ObjectToJson(UObject* Object, FString& data);


	static bool JsonValueToUProperty(TSharedPtr<FJsonValue> JsonValue, UProperty* Property, void* OutValue, int64 CheckFlags, int64 SkipFlags);
	static bool ConvertScalarJsonValueToUProperty(TSharedPtr<FJsonValue> JsonValue, UProperty* Property, void* OutValue, int64 CheckFlags, int64 SkipFlags);
	static bool JsonObjectToUStruct(const TSharedRef<FJsonObject>& JsonObject, const UStruct* StructDefinition, void* OutStruct, int64 CheckFlags, int64 SkipFlags);
	static bool JsonAttributesToUStruct(const TMap< FString, TSharedPtr<FJsonValue> >& JsonAttributes, const UStruct* StructDefinition, void* OutStruct, int64 CheckFlags, int64 SkipFlags);
	static bool UObjectToJsonObject(const UStruct* StructDefinition, const void* Struct, TSharedRef<FJsonObject> OutJsonObject, int64 CheckFlags, int64 SkipFlags);
	static bool UObjectToJsonAttributes(const UStruct* StructDefinition, const void* Struct, TMap< FString, TSharedPtr<FJsonValue> >& OutJsonAttributes, int64 CheckFlags, int64 SkipFlags);
	static TSharedPtr<FJsonValue> UPropertyToJsonValue(UProperty* Property, const void* Value, int64 CheckFlags, int64 SkipFlags);
	static TSharedPtr<FJsonValue> ConvertScalarUPropertyToJsonValue(UProperty* Property, const void* Value, int64 CheckFlags, int64 SkipFlags);
	static FString StandardizeCase(const FString &StringIn);
};
