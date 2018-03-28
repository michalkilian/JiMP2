//
// Created by Michał on 2018-03-26.
//

#ifndef JIMP_EXERCISES_SIMPLEJSON_H
#define JIMP_EXERCISES_SIMPLEJSON_H

#include <experimental/optional>
#include <string>
#include <vector>
#include <map>
#include <sstream>

using ::std::experimental::make_optional;

namespace nets {
    class JsonValue {
        std::experimental::optional<int> intV;
        std::experimental::optional<double> doubleV;
        std::experimental::optional<std::string> stringV;
        std::experimental::optional<bool> boolV;
        std::experimental::optional<std::vector<JsonValue>> JV;
        std::experimental::optional<std::map<std::string, JsonValue>> JMV;
    public:
        JsonValue();

        JsonValue(int value);

        JsonValue(double value);

        JsonValue(std::string value);

        JsonValue(bool value);

        JsonValue(std::vector<JsonValue> value);

        JsonValue(std::map<std::string, JsonValue> value);

        std::experimental::optional<JsonValue> ValueByName(const std::string &name) const;

        std::string ToString() const;
    };
}
#endif //JIMP_EXERCISES_SIMPLEJSON_H