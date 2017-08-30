#include "MessageProto.h"
#include "Engine.h"
#include "Kismet/BlueprintFunctionLibrary.h"


int UMessageProtocommandBlueprintLibrary::CMD_TEST(){
	return 1;
}

UTestInfo::UTestInfo(){
}

UCS_CMD_TEST::UCS_CMD_TEST(){
	testinfo = CreateDefaultSubobject<UTestInfo>(TEXT("testinfo"));
	body = CreateDefaultSubobject<UCS_CMD_TEST_body>(TEXT("body"));
}

UCS_CMD_TEST_body::UCS_CMD_TEST_body(){
}

