#pragma once
#include "Engine.h"
#include "GameMessage.generated.h"
UCLASS()
class  UGameMessagecommandBlueprintLibrary : public UBlueprintFunctionLibrary{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category = "GameMessage")
	static int CMD_LOGIN();
	UFUNCTION(BlueprintPure, Category = "GameMessage")
	static int CMD_REGISTER();
	UFUNCTION(BlueprintPure, Category = "GameMessage")
	static int CMD_GAMELIST();
	UFUNCTION(BlueprintPure, Category = "GameMessage")
	static int CMD_SERVERLIST();
	UFUNCTION(BlueprintPure, Category = "GameMessage")
	static int CMD_CREATE_ROOM();
	UFUNCTION(BlueprintPure, Category = "GameMessage")
	static int CMD_JOIN_ROOM();
	UFUNCTION(BlueprintPure, Category = "GameMessage")
	static int CMD_GAME_REAY();
	UFUNCTION(BlueprintPure, Category = "GameMessage")
	static int CMD_LEAVE_ROOM();
	UFUNCTION(BlueprintPure, Category = "GameMessage")
	static int CMD_GAME_START();
	UFUNCTION(BlueprintPure, Category = "GameMessage")
	static int CMD_GAME_SENDSCENE();
	UFUNCTION(BlueprintPure, Category = "GameMessage")
	static int CMD_GAME_MESSAGE();
	UFUNCTION(BlueprintPure, Category = "GameMessage")
	static int CMD_NOTIFY_CURROOM();
	UFUNCTION(BlueprintPure, Category = "GameMessage")
	static int CMD_QUERY_GAMECONFIG();
	UFUNCTION(BlueprintPure, Category = "GameMessage")
	static int CMD_PLAYER_OFFLINE();
};

UCLASS()
class  UGameMessageenGameModeBlueprintLibrary : public UBlueprintFunctionLibrary{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category = "GameMessage")
	static int enComsumeMode_VIP();
	UFUNCTION(BlueprintPure, Category = "GameMessage")
	static int enComsumeMode_Card();
};

UCLASS(BlueprintType, Blueprintable)
class UCS_CMD_LOGIN_body:public UObject {
GENERATED_BODY()
public:
	UCS_CMD_LOGIN_body();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	FString account;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	FString password;
};

UCLASS(BlueprintType, Blueprintable)
class UCS_CMD_LOGIN:public UObject {
GENERATED_BODY()
public:
	UCS_CMD_LOGIN();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	int cmd;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	UCS_CMD_LOGIN_body* body;
};

UCLASS(BlueprintType, Blueprintable)
class UAccountBaseInfo:public UObject {
GENERATED_BODY()
public:
	UAccountBaseInfo();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	FString account;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	FString name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	FString id;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	FString icon;
};

UCLASS(BlueprintType, Blueprintable)
class USC_CMD_LOGIN_body:public UObject {
GENERATED_BODY()
public:
	USC_CMD_LOGIN_body();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	bool result;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	UAccountBaseInfo* data;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	FString errmsg;
};

UCLASS(BlueprintType, Blueprintable)
class USC_CMD_LOGIN:public UObject {
GENERATED_BODY()
public:
	USC_CMD_LOGIN();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	int cmd;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	USC_CMD_LOGIN_body* body;
};

UCLASS(BlueprintType, Blueprintable)
class UCS_CMD_REGISTER_body:public UObject {
GENERATED_BODY()
public:
	UCS_CMD_REGISTER_body();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	FString account;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	FString password;
};

UCLASS(BlueprintType, Blueprintable)
class UCS_CMD_REGISTER:public UObject {
GENERATED_BODY()
public:
	UCS_CMD_REGISTER();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	int cmd;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	UCS_CMD_REGISTER_body* body;
};

UCLASS(BlueprintType, Blueprintable)
class USC_CMD_REGISTER_body:public UObject {
GENERATED_BODY()
public:
	USC_CMD_REGISTER_body();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	bool result;
};

UCLASS(BlueprintType, Blueprintable)
class USC_CMD_REGISTER:public UObject {
GENERATED_BODY()
public:
	USC_CMD_REGISTER();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	int cmd;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	USC_CMD_REGISTER_body* body;
};

UCLASS(BlueprintType, Blueprintable)
class UGameDefineInfo:public UObject {
GENERATED_BODY()
public:
	UGameDefineInfo();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	FString gameid;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	FString name;
};

UCLASS(BlueprintType, Blueprintable)
class USC_CMD_GAMELIST_body:public UObject {
GENERATED_BODY()
public:
	USC_CMD_GAMELIST_body();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	TArray<UGameDefineInfo*> gamelist;
};

UCLASS(BlueprintType, Blueprintable)
class USC_CMD_GAMELIST:public UObject {
GENERATED_BODY()
public:
	USC_CMD_GAMELIST();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	int cmd;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	USC_CMD_GAMELIST_body* body;
};

UCLASS(BlueprintType, Blueprintable)
class UServerInfo:public UObject {
GENERATED_BODY()
public:
	UServerInfo();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	FString id;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	FString host;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	int port;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	TArray<UGameDefineInfo*> gamelist;
};

UCLASS(BlueprintType, Blueprintable)
class USC_CMD_SERVERLIST_body:public UObject {
GENERATED_BODY()
public:
	USC_CMD_SERVERLIST_body();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	TArray<UServerInfo*> serverlist;
};

UCLASS(BlueprintType, Blueprintable)
class USC_CMD_SERVERLIST:public UObject {
GENERATED_BODY()
public:
	USC_CMD_SERVERLIST();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	int cmd;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	USC_CMD_SERVERLIST_body* body;
};

UCLASS(BlueprintType, Blueprintable)
class UCS_CMD_QUERY_GAMECONFIG_body:public UObject {
GENERATED_BODY()
public:
	UCS_CMD_QUERY_GAMECONFIG_body();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	FString gameid;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	int mode;
};

UCLASS(BlueprintType, Blueprintable)
class UCS_CMD_QUERY_GAMECONFIG:public UObject {
GENERATED_BODY()
public:
	UCS_CMD_QUERY_GAMECONFIG();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	int cmd;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	UCS_CMD_QUERY_GAMECONFIG_body* body;
};

UCLASS(BlueprintType, Blueprintable)
class UGameConfigInfo:public UObject {
GENERATED_BODY()
public:
	UGameConfigInfo();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	int gamecount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	int cost;
};

UCLASS(BlueprintType, Blueprintable)
class USC_CMD_QUERY_GAMECONFIG_body:public UObject {
GENERATED_BODY()
public:
	USC_CMD_QUERY_GAMECONFIG_body();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	bool result;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	int minplayercnt;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	int maxplayercnt;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	TArray<UGameConfigInfo*> configList;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	FString errmsg;
};

UCLASS(BlueprintType, Blueprintable)
class USC_CMD_QUERY_GAMECONFIG:public UObject {
GENERATED_BODY()
public:
	USC_CMD_QUERY_GAMECONFIG();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	int cmd;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	USC_CMD_QUERY_GAMECONFIG_body* body;
};

UCLASS(BlueprintType, Blueprintable)
class UCS_CMD_CREATE_ROOM_body:public UObject {
GENERATED_BODY()
public:
	UCS_CMD_CREATE_ROOM_body();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	FString gameid;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	int mode;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	int gamecount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	int playercount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	FString privaterule;
};

UCLASS(BlueprintType, Blueprintable)
class UCS_CMD_CREATE_ROOM:public UObject {
GENERATED_BODY()
public:
	UCS_CMD_CREATE_ROOM();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	int cmd;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	UCS_CMD_CREATE_ROOM_body* body;
};

UCLASS(BlueprintType, Blueprintable)
class URoomMember:public UObject {
GENERATED_BODY()
public:
	URoomMember();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	FString name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	FString id;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	FString ip;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	int chair;
};

UCLASS(BlueprintType, Blueprintable)
class URoomDetail:public UObject {
GENERATED_BODY()
public:
	URoomDetail();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	TArray<URoomMember*> memberlist;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	FString ownerid;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	FString gameid;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	FString roomid;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	int playercount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	int gamecount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	FString privaterule;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	bool isstarted;
};

UCLASS(BlueprintType, Blueprintable)
class USC_CMD_CREATE_ROOM_body:public UObject {
GENERATED_BODY()
public:
	USC_CMD_CREATE_ROOM_body();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	bool result;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	URoomDetail* roominfo;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	FString error;
};

UCLASS(BlueprintType, Blueprintable)
class USC_CMD_CREATE_ROOM:public UObject {
GENERATED_BODY()
public:
	USC_CMD_CREATE_ROOM();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	int cmd;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	USC_CMD_CREATE_ROOM_body* body;
};

UCLASS(BlueprintType, Blueprintable)
class UCS_CMD_JOIN_ROOM_body:public UObject {
GENERATED_BODY()
public:
	UCS_CMD_JOIN_ROOM_body();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	FString roomid;
};

UCLASS(BlueprintType, Blueprintable)
class UCS_CMD_JOIN_ROOM:public UObject {
GENERATED_BODY()
public:
	UCS_CMD_JOIN_ROOM();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	int cmd;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	UCS_CMD_JOIN_ROOM_body* body;
};

UCLASS(BlueprintType, Blueprintable)
class USC_CMD_JOIN_ROOM_body:public UObject {
GENERATED_BODY()
public:
	USC_CMD_JOIN_ROOM_body();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	bool result;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	URoomDetail* roominfo;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	FString error;
};

UCLASS(BlueprintType, Blueprintable)
class USC_CMD_JOIN_ROOM:public UObject {
GENERATED_BODY()
public:
	USC_CMD_JOIN_ROOM();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	int cmd;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	USC_CMD_JOIN_ROOM_body* body;
};

UCLASS(BlueprintType, Blueprintable)
class UCS_CMD_LEAVE_ROOM:public UObject {
GENERATED_BODY()
public:
	UCS_CMD_LEAVE_ROOM();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	int cmd;
};

UCLASS(BlueprintType, Blueprintable)
class USC_CMD_LEAVE_ROOM_body:public UObject {
GENERATED_BODY()
public:
	USC_CMD_LEAVE_ROOM_body();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	bool result;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	FString userid;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	FString error;
};

UCLASS(BlueprintType, Blueprintable)
class USC_CMD_LEAVE_ROOM:public UObject {
GENERATED_BODY()
public:
	USC_CMD_LEAVE_ROOM();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	int cmd;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	USC_CMD_LEAVE_ROOM_body* body;
};

UCLASS(BlueprintType, Blueprintable)
class UCS_CMD_GAME_REAY:public UObject {
GENERATED_BODY()
public:
	UCS_CMD_GAME_REAY();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	int cmd;
};

UCLASS(BlueprintType, Blueprintable)
class USC_CMD_GAME_REAY_body:public UObject {
GENERATED_BODY()
public:
	USC_CMD_GAME_REAY_body();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	bool result;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	FString userid;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	FString error;
};

UCLASS(BlueprintType, Blueprintable)
class USC_CMD_GAME_REAY:public UObject {
GENERATED_BODY()
public:
	USC_CMD_GAME_REAY();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	int cmd;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	USC_CMD_GAME_REAY_body* body;
};

UCLASS(BlueprintType, Blueprintable)
class USC_CMD_GAME_START_body:public UObject {
GENERATED_BODY()
public:
	USC_CMD_GAME_START_body();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	FString privatedata;
};

UCLASS(BlueprintType, Blueprintable)
class USC_CMD_GAME_START:public UObject {
GENERATED_BODY()
public:
	USC_CMD_GAME_START();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	int cmd;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	USC_CMD_GAME_START_body* body;
};

UCLASS(BlueprintType, Blueprintable)
class USC_CMD_GAME_SENDSCENE_body:public UObject {
GENERATED_BODY()
public:
	USC_CMD_GAME_SENDSCENE_body();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	FString privatedata;
};

UCLASS(BlueprintType, Blueprintable)
class USC_CMD_GAME_SENDSCENE:public UObject {
GENERATED_BODY()
public:
	USC_CMD_GAME_SENDSCENE();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	int cmd;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	USC_CMD_GAME_SENDSCENE_body* body;
};

UCLASS(BlueprintType, Blueprintable)
class UCS_CMD_GAME_MESSAGE_body:public UObject {
GENERATED_BODY()
public:
	UCS_CMD_GAME_MESSAGE_body();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	FString privatedata;
};

UCLASS(BlueprintType, Blueprintable)
class UCS_CMD_GAME_MESSAGE:public UObject {
GENERATED_BODY()
public:
	UCS_CMD_GAME_MESSAGE();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	int cmd;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	int subcmd;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	UCS_CMD_GAME_MESSAGE_body* body;
};

UCLASS(BlueprintType, Blueprintable)
class USC_CMD_GAME_MESSAGE_body:public UObject {
GENERATED_BODY()
public:
	USC_CMD_GAME_MESSAGE_body();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	FString privatedata;
};

UCLASS(BlueprintType, Blueprintable)
class USC_CMD_GAME_MESSAGE:public UObject {
GENERATED_BODY()
public:
	USC_CMD_GAME_MESSAGE();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	int cmd;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	int subcmd;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	USC_CMD_GAME_MESSAGE_body* body;
};

UCLASS(BlueprintType, Blueprintable)
class USC_CMD_NOTIFY_CURROOM_body:public UObject {
GENERATED_BODY()
public:
	USC_CMD_NOTIFY_CURROOM_body();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	bool existroom;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	TArray<URoomDetail*> roomlist;
};

UCLASS(BlueprintType, Blueprintable)
class USC_CMD_NOTIFY_CURROOM:public UObject {
GENERATED_BODY()
public:
	USC_CMD_NOTIFY_CURROOM();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	int cmd;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	USC_CMD_NOTIFY_CURROOM_body* body;
};

UCLASS(BlueprintType, Blueprintable)
class USC_CMD_PLAYER_OFFLINE_body:public UObject {
GENERATED_BODY()
public:
	USC_CMD_PLAYER_OFFLINE_body();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	FString userid;
};

UCLASS(BlueprintType, Blueprintable)
class USC_CMD_PLAYER_OFFLINE:public UObject {
GENERATED_BODY()
public:
	USC_CMD_PLAYER_OFFLINE();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	int cmd;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = GameMessage)
	USC_CMD_PLAYER_OFFLINE_body* body;
};

