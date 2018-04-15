//
// Created by Michał on 2018-04-15.
//

#include "Word.h"

namespace datastructures {
    Word::Word(std::string in) : word_(in) {}

    bool Word::Empty() {
        return word_.empty();
    }

    const std::string Word::GetWord() const {
        return word_;
    }

    bool operator==(const Word &one, const Word &two) {
        return (one.GetWord() == two.GetWord());
    }

    bool operator<(const Word &one, const Word &two) {
        return (one.GetWord() < two.GetWord());
    }

    bool operator>(const Word &one, const Word &two) {
        return (one.GetWord() > two.GetWord());
    }

    std::ostream &operator<<(std::ostream &os, const Word &wout) {
        os << wout.GetWord();
        return os;
    }

    std::istream &operator>>(std::istream &is, Word &obj) {
        is >> obj.word_;
        return is;
    }

}
