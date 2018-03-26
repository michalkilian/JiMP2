//
// Created by Michał on 2018-03-26.
//

#include "SimpleJson.h"

namespace nets {

    JsonValue::JsonValue() {}

    JsonValue::JsonValue(int value) {
        intV = value;
    }

    JsonValue::JsonValue(double value) {
        doubleV = value;
    }

    JsonValue::JsonValue(std::string value) {
        stringV = value;
    }

    JsonValue::JsonValue(bool value) {
        boolV = value;
    }

    JsonValue::JsonValue(std::vector<JsonValue> value) {
        JV = value;
    }

    JsonValue::JsonValue(std::map<std::string, JsonValue> value) {
        JMV = value;
    }

    std::string JsonValue::ToString() const {
        if (intV) {
            std::string intString = std::to_string(*intV);
            return intString;
        }
        if (doubleV) {
            std::ostringstream doubleString;
            doubleString << *doubleV;
            std::string strDouble = doubleString.str();
            return strDouble;
        }
        if (stringV) {
            std::string strString = *stringV;
            for (int i = 0; i < strString.length(); i++) {
                if (strString[i] == '\"' || strString[i] == '\\') {
                    strString.insert(i, 1, '\\');
                    i++;
                }
            }
            std::string stringWithSlash = "\"" + strString + "\"";
            return stringWithSlash;
        }
        if (boolV) {
            if (*boolV) {
                std::string trueS = "true";
                return trueS;
            } else {
                std::string falseS = "false";
                return falseS;
            }
        }
        if (JV) {
            std::string JVstring;
            bool argument = true;
            for (auto &value : *JV) {
                if (!argument) {
                    JVstring += ", ";
                } else {
                    argument = false;
                }
                JVstring += value.ToString();
            }
            JVstring = "[" + JVstring + "]";
            return JVstring;
        }
        if (JMV) {
            std::string JMVstring = "{";
            for (auto &value : *JMV) {
                std::string firstValueString = value.first;
                for (int i = 0; i < firstValueString.length(); ++i) {
                    if (firstValueString[i] == '\"' || firstValueString[i] == '\\') {
                        firstValueString.insert(i, 1, '\\');
                        ++i;
                    }
                }
                JMVstring += "\"" + firstValueString + "\": " + value.second.ToString() + ", ";
            }
            JMVstring = JMVstring.substr(0, JMVstring.length() - 2) + '}';
            return JMVstring;
        }

    }

    std::experimental::optional<JsonValue> JsonValue::ValueByName(const std::string &name) const {

    }
}