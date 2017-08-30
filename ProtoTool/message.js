var MessageProto = {
    command:{
        enum:1,
        CMD_TEST:1,
    },

    TestInfo:{
        name:"string",
        score:":int",
    },
    
    CS_CMD_TEST:{
        name:"string",
        age:"int",
        testinfo:"TestInfo",
        body:{
            address:"string",
            test:"int"
        }
    }
}

global.MessageProto = MessageProto
exports.MessageProto = MessageProto