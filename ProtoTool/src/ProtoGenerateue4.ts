/// <reference path="../typings/index.d.ts" />
/// <reference path="ProtoGenerate.d.ts" />

import * as fs from 'fs'

export class Ue4Generate implements ProtoGenerate.IProtoGenerate{
    moduleName:string;
    cppString:{[key:string]:string} = {};
    cppDepend:string = "";
    
    Generate(moduleName:string, protoObj:any){
        this.moduleName = moduleName;
        var fileheader = "";
        var body = ""
        var end = ""

        fileheader = "#pragma once\n";
        fileheader += "#include \"Engine.h\"\n";
        fileheader += "#include \"" + moduleName + ".generated.h\"\n";
        
        body +=  this.exportEnum(protoObj, 0);
        


        delete protoObj.command;
        body += this.exportTypes(protoObj, 0);

        //end = "\n}"

        fs.writeFileSync(moduleName + ".h", fileheader + body + end)

        var cppContent = "#include \"" + moduleName + ".h\"\n"
        cppContent += "#include \"Engine.h\"\n"
        cppContent += "#include \"Kismet/BlueprintFunctionLibrary.h\"\n\n\n"
        

        cppContent += this.cppDepend;

        var keys = Object.keys(this.cppString)
        for(var i = 0; i < keys.length; i++){
            cppContent += this.cppString[keys[i]]
        }

        fs.writeFileSync(moduleName + ".cpp", cppContent)
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
        
        var ret = this.tab(tabCount) + "UCLASS()\n"
        ret += this.tab(tabCount) + "class  U" + this.moduleName + key + "BlueprintLibrary : public UBlueprintFunctionLibrary{\n"
        ret += this.tab(tabCount+1) + "GENERATED_BODY()\n\n"
        ret += this.tab(tabCount) + "public:\n"

        var keys = Object.keys(defObj)
        for (var i = 0; i < keys.length; i++){
            if(keys[i] == "enum"){
                continue;
            }

            ret += this.tab(tabCount + 1) + "UFUNCTION(BlueprintPure, Category = \""+ this.moduleName+ "\")\n";
            ret += this.tab(tabCount+1) + "static int " + keys[i] + "();\n"

            this.cppDepend += "int U" + this.moduleName + key + "BlueprintLibrary::" + keys[i] + "(){\n"
            this.cppDepend += this.tab(1) + "return " + defObj[keys[i]] + ";\n"
            this.cppDepend += "}\n\n"
        }

        ret += this.tab(tabCount) + "};\n\n"

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
            return ""
        }

        var ret = this.tab(tabCount) + "UCLASS(BlueprintType, Blueprintable)\n"
        ret += this.tab(tabCount) + "class U"+tyname + ":public UObject {\n";
        ret += this.tab(tabCount) + "GENERATED_BODY()\n";
        ret += this.tab(tabCount) + "public:\n"
        
        var preDefClass = "";
        var body = "";
        var constructorFunction = this.tab(tabCount+1) + "U" + tyname + "();\n";

        this.cppString["U" + tyname] = "U" + tyname + "::" + "U" + tyname + "(){\n"
        
        var keys = Object.keys(defObj)
        for(var i = 0; i < keys.length; i++){
            if(typeof(defObj[keys[i]]) == "string"){
                body += this.tab(tabCount + 1) + "UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = "+this.moduleName + ")\n"
                body += this.tab(tabCount + 1) + this.convertType(defObj[keys[i]]) + " " + keys[i] + ";\n"

                if(this.isArrayType(defObj[keys[i]]) == false && this.isObjectType(defObj[keys[i]]) ){
                    this.cppString["U" + tyname] += this.tab(1) + keys[i] + " = " + "CreateDefaultSubobject<"+ this.getoriginType(defObj[keys[i]]) + ">(TEXT(\""+ keys[i] +"\"));\n";
                }
            }
            else{
                preDefClass += this.exportType(tyname+"_" + keys[i], defObj[keys[i]], tabCount, protoObj);

                body += this.tab(tabCount + 1) + "UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn=true), Category = "+this.moduleName + ")\n"
                body += this.tab(tabCount + 1) + "U" + tyname+"_" + keys[i] + "* " + keys[i] + ";\n"

                this.cppString["U" + tyname] += this.tab(1) + keys[i] + " = " + "CreateDefaultSubobject<"+ "U" + tyname+"_" + keys[i] + ">(TEXT(\""+ keys[i] + "\"));\n";
            }
        }

        this.cppString["U" + tyname] += "}\n\n"

        ret += constructorFunction
        ret += body
        ret += this.tab(tabCount) + "};\n\n"

        return preDefClass + ret;
    }

    arraytype(tyname, isArray, isclass?:boolean):string{
        
        if(!isArray){
            if(isclass){
                return tyname + "*";
            }
            return tyname;
        }

        if(isclass){
            return "TArray<" + tyname + "*>";
        }

        return "TArray<" + tyname + ">";
    }

    isObjectType(tpname:string):boolean{
        var arrayflag = false;
        if(tpname[0] == ':'){
            arrayflag = true;
            tpname = tpname.substr(1)
        }

        if(tpname == "int"){
            return false;
        }
        else if (tpname == "string"){
            return false;
        }
        else if(tpname == "float"){
            return false;
        }
        else if(tpname == "bool"){
            return false;
        }
        else{
            return true;
        }
    }

    isArrayType(tpname:string):boolean{
        var arrayflag = false;
        if(tpname[0] == ':'){
            return true;
        }

        return false;
    }

    getoriginType(tpname:string):string{
        var arrayflag = false;
        if(tpname[0] == ':'){
            arrayflag = true;
            tpname = tpname.substr(1)
        }

        if(tpname == "int"){
            return "int";
        }
        else if (tpname == "string"){
            return "FString"
        }
        else if(tpname == "float"){
            return "float"
        }
        else if(tpname == "bool"){
            return "bool"
        }
        else{
            return "U" + tpname        
        }
    }

    convertType(tpname:string):string{
        var arrayflag = false;
        if(tpname[0] == ':'){
            arrayflag = true;
            tpname = tpname.substr(1)
        }

        if(tpname == "int"){
            return this.arraytype("int", arrayflag)
        }
        else if (tpname == "string"){
            return this.arraytype("FString", arrayflag)
        }
        else if(tpname == "float"){
            return this.arraytype("float", arrayflag)
        }
        else if(tpname == "bool"){
            return this.arraytype("bool", arrayflag)
        }
        else{
            return this.arraytype("U" + tpname, arrayflag, true)
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
global.language = new Ue4Generate()