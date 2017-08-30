"use strict";
/// <reference path="../typings/index.d.ts" />
/// <reference path="ProtoGenerate.d.ts" />
Object.defineProperty(exports, "__esModule", { value: true });
var fs = require("fs");
var TsGenerate = (function () {
    function TsGenerate() {
    }
    TsGenerate.prototype.Generate = function (moduleName, protoObj) {
        var fileheader = "";
        var body = "";
        var end = "";
        fileheader = "declare namespace " + moduleName + "{\n";
        body += this.exportEnum(protoObj, 1);
        delete protoObj.command;
        body += this.exportTypes(protoObj, 1);
        end = "\n}";
        fs.writeFileSync(moduleName + ".d.ts", fileheader + body + end);
    };
    TsGenerate.prototype.exportEnum = function (protoObj, tabCount) {
        var keys = Object.keys(protoObj);
        var ret = "";
        for (var i = 0; i < keys.length; i++) {
            var defObj = protoObj[keys[i]];
            ret += this.exportCommand(keys[i], defObj, tabCount);
        }
        return ret;
    };
    TsGenerate.prototype.exportCommand = function (key, defObj, tabCount) {
        if (defObj.enum != 1) {
            return "";
        }
        var ret = this.tab(tabCount) + "enum " + key + " {\n";
        var keys = Object.keys(defObj);
        for (var i = 0; i < keys.length; i++) {
            ret += this.tab(tabCount + 1) + keys[i] + "=" + defObj[keys[i]] + ",\n";
        }
        ret += this.tab(tabCount) + "}\n";
        return ret;
    };
    TsGenerate.prototype.exportTypes = function (protoObj, tabCount) {
        var keys = Object.keys(protoObj);
        var ret = "";
        for (var i = 0; i < keys.length; i++) {
            var defObj = protoObj[keys[i]];
            ret += this.exportType(keys[i], defObj, tabCount, protoObj);
        }
        return ret;
    };
    TsGenerate.prototype.exportType = function (tyname, defObj, tabCount, protoObj) {
        if (defObj.enum == 1) {
            return "";
        }
        var ret = this.tab(tabCount) + "export interface " + tyname + "{\n";
        var preDefClass = "";
        var keys = Object.keys(defObj);
        for (var i = 0; i < keys.length; i++) {
            if (typeof (defObj[keys[i]]) == "string") {
                ret += this.tab(tabCount + 1) + keys[i] + ":" + this.convertType(defObj[keys[i]]) + ";\n";
            }
            else {
                preDefClass += this.exportType(tyname + "_" + keys[i], defObj[keys[i]], tabCount, protoObj);
                ret += this.tab(tabCount + 1) + keys[i] + ":" + tyname + "_" + keys[i] + ";\n";
            }
        }
        ret += this.tab(tabCount) + "}\n";
        return preDefClass + ret;
    };
    TsGenerate.prototype.convertType = function (tpname) {
        var arrayflag = "";
        if (tpname[0] == ':') {
            arrayflag = "[]";
            tpname = tpname.substr(1);
        }
        if (tpname == "int") {
            return "number" + arrayflag;
        }
        else if (tpname == "string") {
            return "string" + arrayflag;
        }
        else if (tpname == "float") {
            return "number" + arrayflag;
        }
        else if (tpname == "bool") {
            return "boolean" + arrayflag;
        }
        else {
            return tpname + arrayflag;
        }
    };
    TsGenerate.prototype.tab = function (count) {
        var ret = "";
        for (var i = 0; i < count; i++) {
            ret = ret + "\t";
        }
        return ret;
    };
    return TsGenerate;
}());
exports.TsGenerate = TsGenerate;
global.language = new TsGenerate();
//# sourceMappingURL=ProtoGeneratets.js.map