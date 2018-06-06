//
// Created by kilimich on 23.05.18.
//

#ifndef JIMP_EXERCISES_MEAN_H
#define JIMP_EXERCISES_MEAN_H

#include <vector>
template<class T>
T Mean(std::vector<T> v){
    T sum = T();
    for(T u:v){
        sum += u;
    }
    T size = v.size();
    return sum/size;
}

#endif //JIMP_EXERCISES_MEAN_H
