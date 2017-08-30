/// <reference path="../typings/index.d.ts" />
/// <reference path="./ProtoGenerate.d.ts" />


for(var i = 0; i < process.argv.length; i++){
    console.log(process.argv[i])
}

if(process.argv.length != 5){
    console.log("useage:[ProtoFileName] [language] [module]")
    process.exit(1);
}

var protofile = process.argv[2]
var language = process.argv[3]
var moduleName = process.argv[4]

var codeCreator = "ProtoGenerate" + language
require("./" + codeCreator + ".js")


var protoObj = require(protofile)
var parser:ProtoGenerate.IProtoGenerate = global["language"]

parser.Generate(moduleName, protoObj.MessageProto)

