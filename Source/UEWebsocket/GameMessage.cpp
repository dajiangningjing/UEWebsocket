#include "UEWebSocket.h"
#include "GameMessage.h"
#include "Engine.h"
#include "Kismet/BlueprintFunctionLibrary.h"


int UGameMessagecommandBlueprintLibrary::CMD_LOGIN(){
	return 1;
}

int UGameMessagecommandBlueprintLibrary::CMD_REGISTER(){
	return 2;
}

int UGameMessagecommandBlueprintLibrary::CMD_GAMELIST(){
	return 3;
}

int UGameMessagecommandBlueprintLibrary::CMD_SERVERLIST(){
	return 4;
}

int UGameMessagecommandBlueprintLibrary::CMD_CREATE_ROOM(){
	return 5;
}

int UGameMessagecommandBlueprintLibrary::CMD_JOIN_ROOM(){
	return 6;
}

int UGameMessagecommandBlueprintLibrary::CMD_GAME_REAY(){
	return 7;
}

int UGameMessagecommandBlueprintLibrary::CMD_LEAVE_ROOM(){
	return 8;
}

int UGameMessagecommandBlueprintLibrary::CMD_GAME_START(){
	return 9;
}

int UGameMessagecommandBlueprintLibrary::CMD_GAME_SENDSCENE(){
	return 10;
}

int UGameMessagecommandBlueprintLibrary::CMD_GAME_MESSAGE(){
	return 11;
}

int UGameMessagecommandBlueprintLibrary::CMD_NOTIFY_CURROOM(){
	return 12;
}

int UGameMessagecommandBlueprintLibrary::CMD_QUERY_GAMECONFIG(){
	return 13;
}

int UGameMessagecommandBlueprintLibrary::CMD_PLAYER_OFFLINE(){
	return 14;
}

int UGameMessageenGameModeBlueprintLibrary::enComsumeMode_VIP(){
	return 0;
}

int UGameMessageenGameModeBlueprintLibrary::enComsumeMode_Card(){
	return 1;
}

UCS_CMD_LOGIN::UCS_CMD_LOGIN(){
	body = CreateDefaultSubobject<UCS_CMD_LOGIN_body>(TEXT("body"));
}

UCS_CMD_LOGIN_body::UCS_CMD_LOGIN_body(){
}

UAccountBaseInfo::UAccountBaseInfo(){
}

USC_CMD_LOGIN::USC_CMD_LOGIN(){
	body = CreateDefaultSubobject<USC_CMD_LOGIN_body>(TEXT("body"));
}

USC_CMD_LOGIN_body::USC_CMD_LOGIN_body(){
	data = CreateDefaultSubobject<UAccountBaseInfo>(TEXT("data"));
}

UCS_CMD_REGISTER::UCS_CMD_REGISTER(){
	body = CreateDefaultSubobject<UCS_CMD_REGISTER_body>(TEXT("body"));
}

UCS_CMD_REGISTER_body::UCS_CMD_REGISTER_body(){
}

USC_CMD_REGISTER::USC_CMD_REGISTER(){
	body = CreateDefaultSubobject<USC_CMD_REGISTER_body>(TEXT("body"));
}

USC_CMD_REGISTER_body::USC_CMD_REGISTER_body(){
}

UGameDefineInfo::UGameDefineInfo(){
}

USC_CMD_GAMELIST::USC_CMD_GAMELIST(){
	body = CreateDefaultSubobject<USC_CMD_GAMELIST_body>(TEXT("body"));
}

USC_CMD_GAMELIST_body::USC_CMD_GAMELIST_body(){
}

UServerInfo::UServerInfo(){
}

USC_CMD_SERVERLIST::USC_CMD_SERVERLIST(){
	body = CreateDefaultSubobject<USC_CMD_SERVERLIST_body>(TEXT("body"));
}

USC_CMD_SERVERLIST_body::USC_CMD_SERVERLIST_body(){
}

UCS_CMD_QUERY_GAMECONFIG::UCS_CMD_QUERY_GAMECONFIG(){
	body = CreateDefaultSubobject<UCS_CMD_QUERY_GAMECONFIG_body>(TEXT("body"));
}

UCS_CMD_QUERY_GAMECONFIG_body::UCS_CMD_QUERY_GAMECONFIG_body(){
}

UGameConfigInfo::UGameConfigInfo(){
}

USC_CMD_QUERY_GAMECONFIG::USC_CMD_QUERY_GAMECONFIG(){
	body = CreateDefaultSubobject<USC_CMD_QUERY_GAMECONFIG_body>(TEXT("body"));
}

USC_CMD_QUERY_GAMECONFIG_body::USC_CMD_QUERY_GAMECONFIG_body(){
}

UCS_CMD_CREATE_ROOM::UCS_CMD_CREATE_ROOM(){
	body = CreateDefaultSubobject<UCS_CMD_CREATE_ROOM_body>(TEXT("body"));
}

UCS_CMD_CREATE_ROOM_body::UCS_CMD_CREATE_ROOM_body(){
}

URoomMember::URoomMember(){
}

URoomDetail::URoomDetail(){
}

USC_CMD_CREATE_ROOM::USC_CMD_CREATE_ROOM(){
	body = CreateDefaultSubobject<USC_CMD_CREATE_ROOM_body>(TEXT("body"));
}

USC_CMD_CREATE_ROOM_body::USC_CMD_CREATE_ROOM_body(){
	roominfo = CreateDefaultSubobject<URoomDetail>(TEXT("roominfo"));
}

UCS_CMD_JOIN_ROOM::UCS_CMD_JOIN_ROOM(){
	body = CreateDefaultSubobject<UCS_CMD_JOIN_ROOM_body>(TEXT("body"));
}

UCS_CMD_JOIN_ROOM_body::UCS_CMD_JOIN_ROOM_body(){
}

USC_CMD_JOIN_ROOM::USC_CMD_JOIN_ROOM(){
	body = CreateDefaultSubobject<USC_CMD_JOIN_ROOM_body>(TEXT("body"));
}

USC_CMD_JOIN_ROOM_body::USC_CMD_JOIN_ROOM_body(){
	roominfo = CreateDefaultSubobject<URoomDetail>(TEXT("roominfo"));
}

UCS_CMD_LEAVE_ROOM::UCS_CMD_LEAVE_ROOM(){
}

USC_CMD_LEAVE_ROOM::USC_CMD_LEAVE_ROOM(){
	body = CreateDefaultSubobject<USC_CMD_LEAVE_ROOM_body>(TEXT("body"));
}

USC_CMD_LEAVE_ROOM_body::USC_CMD_LEAVE_ROOM_body(){
}

UCS_CMD_GAME_REAY::UCS_CMD_GAME_REAY(){
}

USC_CMD_GAME_REAY::USC_CMD_GAME_REAY(){
	body = CreateDefaultSubobject<USC_CMD_GAME_REAY_body>(TEXT("body"));
}

USC_CMD_GAME_REAY_body::USC_CMD_GAME_REAY_body(){
}

USC_CMD_GAME_START::USC_CMD_GAME_START(){
	body = CreateDefaultSubobject<USC_CMD_GAME_START_body>(TEXT("body"));
}

USC_CMD_GAME_START_body::USC_CMD_GAME_START_body(){
}

USC_CMD_GAME_SENDSCENE::USC_CMD_GAME_SENDSCENE(){
	body = CreateDefaultSubobject<USC_CMD_GAME_SENDSCENE_body>(TEXT("body"));
}

USC_CMD_GAME_SENDSCENE_body::USC_CMD_GAME_SENDSCENE_body(){
}

UCS_CMD_GAME_MESSAGE::UCS_CMD_GAME_MESSAGE(){
	body = CreateDefaultSubobject<UCS_CMD_GAME_MESSAGE_body>(TEXT("body"));
}

UCS_CMD_GAME_MESSAGE_body::UCS_CMD_GAME_MESSAGE_body(){
}

USC_CMD_GAME_MESSAGE::USC_CMD_GAME_MESSAGE(){
	body = CreateDefaultSubobject<USC_CMD_GAME_MESSAGE_body>(TEXT("body"));
}

USC_CMD_GAME_MESSAGE_body::USC_CMD_GAME_MESSAGE_body(){
}

USC_CMD_NOTIFY_CURROOM::USC_CMD_NOTIFY_CURROOM(){
	body = CreateDefaultSubobject<USC_CMD_NOTIFY_CURROOM_body>(TEXT("body"));
}

USC_CMD_NOTIFY_CURROOM_body::USC_CMD_NOTIFY_CURROOM_body(){
}

USC_CMD_PLAYER_OFFLINE::USC_CMD_PLAYER_OFFLINE(){
	body = CreateDefaultSubobject<USC_CMD_PLAYER_OFFLINE_body>(TEXT("body"));
}

USC_CMD_PLAYER_OFFLINE_body::USC_CMD_PLAYER_OFFLINE_body(){
}

