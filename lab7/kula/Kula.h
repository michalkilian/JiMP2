//
// Created by kilimich on 18.04.18.
//

#ifndef JIMP_EXERCISES_KULA_H
#define JIMP_EXERCISES_KULA_H


#include "Kolo.h"
class Kula : public Kolo {
double z;
public:
    Kula();
    Kula(double x, double y, double z);
    Kula(double x, double y, double z, double r);
    double Pole() override;
};


#endif //JIMP_EXERCISES_KULA_H
