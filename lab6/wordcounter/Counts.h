//
// Created by Michał on 2018-04-15.
//

#ifndef JIMP_EXERCISES_COUNTER_H
#define JIMP_EXERCISES_COUNTER_H

#include <ostream>

namespace datastructures {

    class Counts {
    public:
        Counts();

        Counts(int amount);

        void SetCount(int value);

        const int GetCount() const;

        friend std::ostream &operator<<(std::ostream &os, const Counts &cout);

        friend int operator++(Counts &counttoincrement, int zero);

        friend int operator++(Counts &counttoincrement);

    private:
        int count_;
    };

    int operator++(Counts &counttoincrement, int zero);

    int operator++(Counts &counttoincrement);

    std::ostream &operator<<(std::ostream &os, const Counts &cout);

    bool operator<(const Counts &one, const Counts &two);

    bool operator>(const Counts &one, const Counts &two);

    bool operator==(const Counts &one, const Counts &two);
}

#endif //JIMP_EXERCISES_COUNTER_H
