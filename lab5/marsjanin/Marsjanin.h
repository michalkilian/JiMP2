//
// Created by kilimich on 28.03.18.
//

#ifndef JIMP_EXERCISES_MARSJANIN_H
#define JIMP_EXERCISES_MARSJANIN_H

#include <iostream>

namespace marsjanin {
    class Marsjanin {
    public:
        Marsjanin(){
            liczbaMarsjan++;
        }
        void Atakuj(){
            std::cout << "Atak!";
        }

    private:
        static int liczbaMarsjan;
    };
}

#endif //JIMP_EXERCISES_MARSJANIN_H
