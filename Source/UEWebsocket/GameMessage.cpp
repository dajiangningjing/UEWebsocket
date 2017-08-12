#include "UEWebSocket.h"
#include "Engine.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GameMessage.h"


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

int UGameMessageenGameModeBlueprintLibrary::enComsumeMode_VIP(){
	return 0;
}

int UGameMessageenGameModeBlueprintLibrary::enComsumeMode_Card(){
	return 1;
}

UCS_CMD_LOGIN::UCS_CMD_LOGIN(){
	body = NewObject<UCS_CMD_LOGIN_body>();
}

UCS_CMD_LOGIN_body::UCS_CMD_LOGIN_body(){
}

UAccountBaseInfo::UAccountBaseInfo(){
}

USC_CMD_LOGIN::USC_CMD_LOGIN(){
	body = NewObject<USC_CMD_LOGIN_body>();
}

USC_CMD_LOGIN_body::USC_CMD_LOGIN_body(){
	data = NewObject<UAccountBaseInfo>();
}

UCS_CMD_REGISTER::UCS_CMD_REGISTER(){
	body = NewObject<UCS_CMD_REGISTER_body>();
}

UCS_CMD_REGISTER_body::UCS_CMD_REGISTER_body(){
}

USC_CMD_REGISTER::USC_CMD_REGISTER(){
	body = NewObject<USC_CMD_REGISTER_body>();
}

USC_CMD_REGISTER_body::USC_CMD_REGISTER_body(){
}

UGameDefineInfo::UGameDefineInfo(){
}

USC_CMD_GAMELIST::USC_CMD_GAMELIST(){
	body = NewObject<USC_CMD_GAMELIST_body>();
}

USC_CMD_GAMELIST_body::USC_CMD_GAMELIST_body(){
}

UServerInfo::UServerInfo(){
}

USC_CMD_SERVERLIST::USC_CMD_SERVERLIST(){
	body = NewObject<USC_CMD_SERVERLIST_body>();
}

USC_CMD_SERVERLIST_body::USC_CMD_SERVERLIST_body(){
}

UCS_CMD_CREATE_ROOM::UCS_CMD_CREATE_ROOM(){
	body = NewObject<UCS_CMD_CREATE_ROOM_body>();
}

UCS_CMD_CREATE_ROOM_body::UCS_CMD_CREATE_ROOM_body(){
}

URoomMember::URoomMember(){
}

URoomDetail::URoomDetail(){
}

USC_CMD_CREATE_ROOM::USC_CMD_CREATE_ROOM(){
	body = NewObject<USC_CMD_CREATE_ROOM_body>();
}

USC_CMD_CREATE_ROOM_body::USC_CMD_CREATE_ROOM_body(){
	roominfo = NewObject<URoomDetail>();
}

UCS_CMD_JOIN_ROOM::UCS_CMD_JOIN_ROOM(){
	body = NewObject<UCS_CMD_JOIN_ROOM_body>();
}

UCS_CMD_JOIN_ROOM_body::UCS_CMD_JOIN_ROOM_body(){
}

USC_CMD_JOIN_ROOM::USC_CMD_JOIN_ROOM(){
	body = NewObject<USC_CMD_JOIN_ROOM_body>();
}

USC_CMD_JOIN_ROOM_body::USC_CMD_JOIN_ROOM_body(){
	roominfo = NewObject<URoomDetail>();
}

UCS_CMD_LEAVE_ROOM::UCS_CMD_LEAVE_ROOM(){
}

USC_CMD_LEAVE_ROOM::USC_CMD_LEAVE_ROOM(){
	body = NewObject<USC_CMD_LEAVE_ROOM_body>();
}

USC_CMD_LEAVE_ROOM_body::USC_CMD_LEAVE_ROOM_body(){
}

UCS_CMD_GAME_REAY::UCS_CMD_GAME_REAY(){
}

USC_CMD_GAME_REAY::USC_CMD_GAME_REAY(){
	body = NewObject<USC_CMD_GAME_REAY_body>();
}

USC_CMD_GAME_REAY_body::USC_CMD_GAME_REAY_body(){
}

USC_CMD_GAME_START::USC_CMD_GAME_START(){
	body = NewObject<USC_CMD_GAME_START_body>();
}

USC_CMD_GAME_START_body::USC_CMD_GAME_START_body(){
}

USC_CMD_GAME_SENDSCENE::USC_CMD_GAME_SENDSCENE(){
	body = NewObject<USC_CMD_GAME_SENDSCENE_body>();
}

USC_CMD_GAME_SENDSCENE_body::USC_CMD_GAME_SENDSCENE_body(){
}

UCS_CMD_GAME_MESSAGE::UCS_CMD_GAME_MESSAGE(){
	body = NewObject<UCS_CMD_GAME_MESSAGE_body>();
}

UCS_CMD_GAME_MESSAGE_body::UCS_CMD_GAME_MESSAGE_body(){
}

USC_CMD_GAME_MESSAGE::USC_CMD_GAME_MESSAGE(){
	body = NewObject<USC_CMD_GAME_MESSAGE_body>();
}

USC_CMD_GAME_MESSAGE_body::USC_CMD_GAME_MESSAGE_body(){
}

USC_CMD_NOTIFY_CURROOM::USC_CMD_NOTIFY_CURROOM(){
	body = NewObject<USC_CMD_NOTIFY_CURROOM_body>();
}

USC_CMD_NOTIFY_CURROOM_body::USC_CMD_NOTIFY_CURROOM_body(){
}

