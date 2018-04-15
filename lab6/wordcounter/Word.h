//
// Created by Michał on 2018-04-15.
//

#ifndef JIMP_EXERCISES_WORD_H
#define JIMP_EXERCISES_WORD_H

#include <ostream>
#include <string>
#include <utility>

namespace datastructures {
    class Word {
    public:
        Word() = default;

        Word(std::string in);

        bool Empty();

        const std::string GetWord() const;

        friend std::ostream &operator<<(std::ostream &os, const Word &wout);

        friend std::istream &operator>>(std::istream &is, Word &obj);

    private:
        std::string word_;

    };

    std::ostream &operator<<(std::ostream &os, const Word &wout);

    std::istream &operator>>(std::istream &is, Word &obj);

    bool operator==(const Word &one, const Word &two);

    bool operator<(const Word &one, const Word &two);

    bool operator>(const Word &one, const Word &two);
}


#endif //JIMP_EXERCISES_WORD_H
