//
// Created by kilimich on 20.03.18.
//

#ifndef JIMP_EXERCISES_POINT_H
#define JIMP_EXERCISES_POINT_H

#include <ostream>
namespace geometry{
    class Point {
    public:
        //Konstruktor bezparametrowy
        Point();

        //Konstruktor parametrowy
        Point(double x, double y);

        //Destruktor wykonywany przed zwolnieniem pamięci
        ~Point();

        //Metody nie modyfikujące stanu obiektu (const na końcu metody)
        //nie mogą zmodyfikować tego obiektu.
        void ToString(std::ostream *out) const;

        double Distance(const Point &other) const;


        //metody akcesorów są publiczne i tylko w przy ich pomocy
        //można się dostać z zewnątrz do pól klasy
        double GetX() const;

        double GetY() const;

        //metody seterów pozwalające zmienić stan obiektu
        //po jego zainicjalizowaniu


    private:
        //w przeciwienstwie do pythona C++ wymaga jawnej deklaracji składowych pól klasy:
        double x_, y_;
    };
}

#endif //JIMP_EXERCISES_POINT_H
