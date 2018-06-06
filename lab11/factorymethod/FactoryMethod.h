//
// Created by kilimich on 23.05.18.
//

#ifndef JIMP_EXERCISES_FACTORYMETHOD_H
#define JIMP_EXERCISES_FACTORYMETHOD_H

#include <string>

namespace  factoryMethod{
    template<class T>
    T Create(){
        return T();
    }
    class MyType {
    public:
        MyType(){};
        std::string SayHello() const {return "hello";}
    };
}


#endif //JIMP_EXERCISES_FACTORYMETHOD_H
