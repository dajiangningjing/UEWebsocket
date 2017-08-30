/// <reference path="../typings/index.d.ts" />
/// <reference path="ProtoGenerate.d.ts" />

import * as fs from 'fs'

export class TsGenerate implements ProtoGenerate.IProtoGenerate{
    Generate(moduleName:string, protoObj:any){
        var fileheader = "";
        var body = ""
        var end = ""

        fileheader = "declare namespace " + moduleName + "{\n";
        
        body +=  this.exportEnum(protoObj, 1);

        delete protoObj.command;
        body += this.exportTypes(protoObj, 1);

        end = "\n}"

        fs.writeFileSync(moduleName + ".d.ts", fileheader + body + end)
    }

    exportEnum(protoObj:any, tabCount:number):string{
        var keys = Object.keys(protoObj)

        var ret = ""
        
        for(var i = 0; i < keys.length; i++){
            var defObj = protoObj[keys[i]]
            ret += this.exportCommand(keys[i], defObj, tabCount)
        }

        return ret;
    }

    exportCommand(key:string, defObj:any, tabCount:number):string{
        if(defObj.enum != 1){
            return "";
        }

        var ret = this.tab(tabCount) + "enum "+ key + " {\n"
        
        var keys = Object.keys(defObj)
        for (var i = 0; i < keys.length; i++){
            ret += this.tab(tabCount+1) + keys[i] + "=" + defObj[keys[i]] + ",\n"
        }

        ret += this.tab(tabCount) + "}\n"

        return ret;
    }

    exportTypes(protoObj:any, tabCount:number):string{
        var keys = Object.keys(protoObj)

        var ret = ""
        
        for(var i = 0; i < keys.length; i++){
            var defObj = protoObj[keys[i]]
            ret += this.exportType(keys[i], defObj, tabCount, protoObj)
        }

        return ret;
    }

    exportType(tyname:string, defObj:any, tabCount:number, protoObj:any):string{
        if(defObj.enum == 1){
            return "";
        }

        var ret = this.tab(tabCount) + "export interface " + tyname + "{\n";
        
        var preDefClass = "";
        
        var keys = Object.keys(defObj)
        for(var i = 0; i < keys.length; i++){
            if(typeof(defObj[keys[i]]) == "string"){
                ret += this.tab(tabCount + 1) + keys[i] + ":" + this.convertType(defObj[keys[i]]) + ";\n"
            }
            else{
                preDefClass += this.exportType(tyname+"_" + keys[i], defObj[keys[i]], tabCount, protoObj);
                ret += this.tab(tabCount + 1) + keys[i] + ":" + tyname+"_" + keys[i] + ";\n"
            }
        }

        ret += this.tab(tabCount) + "}\n"

        return preDefClass + ret;
    }

    convertType(tpname:string):string{
        var arrayflag = "";
        if(tpname[0] == ':'){
            arrayflag = "[]";
            tpname = tpname.substr(1)
        }

        if(tpname == "int"){
            return "number" + arrayflag
        }
        else if (tpname == "string"){
            return "string" + arrayflag
        }
        else if(tpname == "float"){
            return "number" + arrayflag
        }
        else if(tpname == "bool"){
            return "boolean" + arrayflag
        }
        else{
            return tpname + arrayflag
        }
    }

    tab(count:number):string{
        var ret = ""
        for(var i = 0; i < count; i++){
            ret = ret + "\t"
        }

        return ret;
    }
}

declare var global:any;
global.language = new TsGenerate()