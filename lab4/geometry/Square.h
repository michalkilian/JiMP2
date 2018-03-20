//
// Created by kilimich on 20.03.18.
//

#ifndef JIMP_EXERCISES_SQUARE_H
#define JIMP_EXERCISES_SQUARE_H

#include "Point.h"
namespace geometry {

    class Square {
    public:
        //Konstruktor bezparametrowy
        //Konstruktor parametrowy
        Square(Point x1, Point x2, Point x3, Point x4);

        //Destruktor wykonywany przed zwolnieniem pamięci
        ~Square();

        void CalculateCircumference() const;

        void CalculateArea() const;

        double Circumference() const;

        double Area() const;

    private:
        //w przeciwienstwie do pythona C++ wymaga jawnej deklaracji składowych pól klasy:
        Point x1, x2, x3, x4;
        double circumference;
        double area;
    };
}
#endif //JIMP_EXERCISES_SQUARE_H
