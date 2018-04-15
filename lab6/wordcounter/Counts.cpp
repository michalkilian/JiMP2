//
// Created by Michał on 2018-04-15.
//

#include "Counts.h"


namespace datastructures {
    Counts::Counts() { count_ = 0; }

    Counts::Counts(int x) { count_ = x; }

    void Counts::SetCount(int setto) {
        count_ = setto;
    }

    const int Counts::GetCount() const {
        return count_;
    }
}

std::ostream &datastructures::operator<<(std::ostream &os, const Counts &cout) {
    os << cout.GetCount();
    return os;
}

int datastructures::operator++(Counts &counttoincrement, int zero) {
    int tmp = counttoincrement.GetCount();
    counttoincrement++;
    return tmp;
}

int datastructures::operator++(Counts &counttoincrement) {
    counttoincrement.count_++;
}

bool datastructures::operator==(const Counts &one, const Counts &two) {
    return (one.GetCount() == two.GetCount());
}

bool datastructures::operator<(const Counts &one, const Counts &two) {
    return (one.GetCount() < two.GetCount());
}

bool datastructures::operator>(const Counts &one, const Counts &two) {
    return (one.GetCount() > two.GetCount());
}