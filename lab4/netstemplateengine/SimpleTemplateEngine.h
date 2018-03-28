//
// Created by Michał on 2018-03-26.
//

#ifndef JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
#define JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H

#include <string>
#include <unordered_map>
#include <regex>

namespace nets {
    class View {
    public:
        View(std::string input);

        std::string Render(const std::unordered_map<std::string, std::string> &model) const;

    private:
        std::string input_;
    };
}
#endif //JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
