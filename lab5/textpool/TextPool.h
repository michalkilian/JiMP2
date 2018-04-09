//
// Created by Michał on 2018-04-09.
//

#ifndef JIMP_EXERCISES_TEXTPOOL_H
#define JIMP_EXERCISES_TEXTPOOL_H

#include <initializer_list>
#include <string>
#include <experimental/string_view>
#include <set>
#include <memory>
#include <iostream>

namespace pool {
    class TextPool {
    public:
        TextPool() = default;

        TextPool(TextPool &&in) = default;

        TextPool &operator=(TextPool &&in);

        TextPool &operator=(const TextPool &in) = delete;

        TextPool(std::initializer_list<std::string> in);

        std::experimental::string_view Intern(const std::string &str);

        size_t StoredStringCount() const;


    private:
        std::set<std::string> wordset_;
    };
}

#endif //JIMP_EXERCISES_TEXTPOOL_H
