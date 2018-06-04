//
// Created by Michał on 2018-06-04.
//

#ifndef JIMP_EXERCISES_SEQUENTIALGENERATOR_H
#define JIMP_EXERCISES_SEQUENTIALGENERATOR_H

#include <iostream>

template<class T, class U>

class SequentialIdGenerator {
    U id;
    bool first;
public:
    SequentialIdGenerator() {
        id = 0;
        first = true;
    };

    ~SequentialIdGenerator() {};

    SequentialIdGenerator(U id) : id{id}, first{true} {};

    operator int() {
        return int(id);
    }

    int NextValue() {
        if (first) {
            first = false;
            return int(id);
        } else {
            ++id;
            return int(id);
        }
    }
};

#endif //JIMP_EXERCISES_SEQUENTIALGENERATOR_H
