//
// Created by kilimich on 20.03.18.
//

#include "Square.h"

#include <cmath>
#include <ostream>

using ::std::ostream;
using ::std::endl;
using ::std::pow;
using ::std::sqrt;
namespace geometry{
/* Aby wskazać, ze definicja funkcji dotyczy metody danej klasy
  stosujemy tzw. operator zasięgu - "::"
*/

//Specjalna inicjalizacja zmiennych. Zmienne są inicjowane
//nim zostanie wywołane ciało konstruktora

    Square::Square(Point x1, Point x2, Point x3, Point x4) {
        this->x1 = x1;
        this->x2 = x2;
        this->x3 = x3;
        this->x4 = x4;

    }

    Square::~Square() {
    }


    void Square::CalculateCircumference()  {
        double circumference = 0;
        circumference += this->x1.Distance(&x2);
        circumference += this->x2.Distance(&x3);
        circumference += this->x3.Distance(&x4);
        circumference += this->x4.Distance(&x1);
        this->circumference = circumference;
    }

    void Square::CalculateArea()  {
        double area = 0;
        area = this->x1.Distance(&x2) * this->x1.Distance(&x2);
        this->area = area;
    }

    double Square::Circumference() const {
        return this->circumference;
    }

    double Square::Area() const {
        return this->area;
    }
}