//
// Created by Michał on 2018-03-26.
//

#include "SimpleTemplateEngine.h"

namespace nets {
    View::View(std::string input) {
        this->input_ = input;
    }

    std::string View::Render(const std::unordered_map<std::string, std::string> &model) const {
        std::string current_text = input_;
        std::regex formula(R"(\{\{\w+\}\})");
        std::smatch matchedString;


        while (std::regex_search(current_text, matchedString, formula)) {
            for (auto x:matchedString) {
                std::string matched_wo_brackets = matchedString.str().substr(2, matchedString.str().size() - 4);
                if (model.find(matched_wo_brackets) != model.end()) {
                    std::string text_to_replace = model.at(matched_wo_brackets);
                    current_text.replace(current_text.find("{{" + matched_wo_brackets + "}}"),
                                         matched_wo_brackets.length() + 4, text_to_replace);
                } else {
                    current_text.replace(current_text.find("{{" + matched_wo_brackets + "}}"),
                                         matched_wo_brackets.length() + 4, "");
                }
            }
        }
        return current_text;
    }
}