"use strict";
/// <reference path="../typings/index.d.ts" />
/// <reference path="ProtoGenerate.d.ts" />
Object.defineProperty(exports, "__esModule", { value: true });
var fs = require("fs");
var CsGenerate = (function () {
    function CsGenerate() {
    }
    CsGenerate.prototype.Generate = function (moduleName, protoObj) {
        var fileheader = "";
        var body = "";
        var end = "";
        fileheader = "using UnityEngine; \nusing System; \nnamespace " + moduleName + "{\n";
        body += this.exportEnum(protoObj, 1);
        delete protoObj.command;
        body += this.exportTypes(protoObj, 1);
        end = "\n}";
        fs.writeFileSync(moduleName + ".cs", fileheader + body + end);
    };
    CsGenerate.prototype.exportEnum = function (protoObj, tabCount) {
        var keys = Object.keys(protoObj);
        var ret = "";
        for (var i = 0; i < keys.length; i++) {
            var defObj = protoObj[keys[i]];
            ret += this.exportCommand(keys[i], defObj, tabCount);
        }
        return ret;
    };
    CsGenerate.prototype.exportCommand = function (key, defObj, tabCount) {
        if (defObj.enum != 1) {
            return "";
        }
        var ret = this.tab(tabCount) + "public enum " + key + " {\n";
        var keys = Object.keys(defObj);
        for (var i = 0; i < keys.length; i++) {
            if (keys[i] == "enum") {
                continue;
            }
            ret += this.tab(tabCount + 1) + keys[i] + "=" + defObj[keys[i]] + ",\n";
        }
        ret += this.tab(tabCount) + "}\n";
        return ret;
    };
    CsGenerate.prototype.exportTypes = function (protoObj, tabCount) {
        var keys = Object.keys(protoObj);
        var ret = "";
        for (var i = 0; i < keys.length; i++) {
            var defObj = protoObj[keys[i]];
            ret += this.exportType(keys[i], defObj, tabCount, protoObj);
        }
        return ret;
    };
    CsGenerate.prototype.exportType = function (tyname, defObj, tabCount, protoObj) {
        if (defObj.enum == 1) {
            return "";
        }
        var ret = this.tab(tabCount) + "[Serializable]\n";
        ret += this.tab(tabCount) + "public class " + tyname + "{\n";
        var preDefClass = "";
        var keys = Object.keys(defObj);
        for (var i = 0; i < keys.length; i++) {
            if (typeof (defObj[keys[i]]) == "string") {
                ret += this.tab(tabCount + 1) + this.convertType(defObj[keys[i]]) + " " + keys[i] + ";\n";
            }
            else {
                preDefClass += this.exportType(tyname + "_" + keys[i], defObj[keys[i]], tabCount, protoObj);
                ret += this.tab(tabCount + 1) + "public " + tyname + "_" + keys[i] + " " + keys[i] + ";\n";
            }
        }
        ret += this.tab(tabCount) + "}\n";
        return preDefClass + ret;
    };
    CsGenerate.prototype.convertType = function (tpname) {
        var arrayflag = "";
        if (tpname[0] == ':') {
            arrayflag = "[]";
            tpname = tpname.substr(1);
        }
        if (tpname == "int") {
            return "public int" + arrayflag;
        }
        else if (tpname == "string") {
            return "public string" + arrayflag;
        }
        else if (tpname == "float") {
            return "public float" + arrayflag;
        }
        else if (tpname == "bool") {
            return "public bool" + arrayflag;
        }
        else {
            return "public " + tpname + arrayflag;
        }
    };
    CsGenerate.prototype.tab = function (count) {
        var ret = "";
        for (var i = 0; i < count; i++) {
            ret = ret + "\t";
        }
        return ret;
    };
    return CsGenerate;
}());
exports.CsGenerate = CsGenerate;
global.language = new CsGenerate();
//# sourceMappingURL=ProtoGeneratecs.js.map