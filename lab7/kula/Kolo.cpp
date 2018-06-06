//
// Created by kilimich on 18.04.18.
//

#include "Kolo.h"

double Kolo::GetR() const {
    return r;
}

double Kolo::Pole(){
    r = this->GetR();
    return 3.14*r*r;
}

Kolo::Kolo(){
    this->x = 0;
    this->y = 0;
    this->r = 1;
}

Kolo::Kolo(double x, double y){
    this->x = x;
    this->y = y;
    this->r = 1;
}

Kolo::Kolo(double x, double y, double r){
    this->x = x;
    this->y = y;
    this->r = r;
}