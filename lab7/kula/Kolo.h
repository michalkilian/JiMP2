//
// Created by kilimich on 18.04.18.
//

#ifndef JIMP_EXERCISES_KOLO_H
#define JIMP_EXERCISES_KOLO_H


class Kolo{
public:
    Kolo();
    Kolo(double x,double y);
    Kolo(double x,double y,double r);
    virtual double Pole();
    double GetR() const;

protected:
    double x,y,r;
};



#endif //JIMP_EXERCISES_KOLO_H
