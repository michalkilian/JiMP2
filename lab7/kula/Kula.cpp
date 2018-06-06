//
// Created by kilimich on 18.04.18.
//

#include "Kula.h"

Kula::Kula() {
    this->x = 0;
    this->y = 0;
    this->z = 0;
    this->r = 1;
}
Kula::Kula(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
    this->r = 1;
}
Kula::Kula(double x, double y, double z, double r) {
    this->x = x;
    this->y = y;
    this->z = z;
    this->r = r;
}
double Kula::Pole() {
    r = this->GetR();
    return 4*3.14*r*r;
}
