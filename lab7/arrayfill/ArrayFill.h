//
// Created by kilimich on 18.04.18.
//

#ifndef JIMP_EXERCISES_ARRAYFILL_H
#define JIMP_EXERCISES_ARRAYFILL_H

#include <vector>
#include <iostream>
namespace arrays{
    class ArrayFill {
    public:
        virtual int ArrayFill(int index) const =0;
    };


    class UniformFill : public ArrayFill {
    public:
        virtual int ArrayFill(int index) const override;
    private:
        int value_;
    };

    class RandomFill : public ArrayFill {
    public:
        RandomFill(int value = 0) : value_{value} {}
        virtual int Value(int index) const override;
    private:
        int value_;
    };
    int RandomFill::Value(int index) const {
        return std::rand();
    }



    void FillArray(size_t size, const ArrayFill &filler, std::vector<int> *v) {
        v->clear();
        v->reserve(size);
        for (size_t i = 0; i < size; i++) {
            v->emplace_back(filler.Value(i));
        }
    }
}


#endif //JIMP_EXERCISES_ARRAYFILL_H
