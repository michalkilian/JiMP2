//
// Created by kilimich on 11.04.18.
//

//Definicja w Point.cpp
#include "Point.h"
#include <iomanip>
#include <istream>

using ::std::ostream;
using ::std::istream;
using ::std::ws;
using ::std::runtime_error;

void Point::SetX(double x){
    x_ = x;
}
void Point::SetY(double y) {
    y_ = y;
}

//Helper functions:
void CheckNextChar(char c, istream* is) {
    int next_char = is->peek();
    if (next_char != c) {
        throw runtime_error("invalid character");
    }
    is->ignore();
}

void IgnoreWhitespace(istream* is) {
    (*is) >> ws;
}

double ReadNumber(istream* is) {
    double d;
    (*is) >> d;
    return d;
}


// Właściwa definicja, obydwa argumenty funkcji nie
//są zadeklarowane jako const, bo obydwa są modyfikowane
//wewnątrz funkcji (STL nie używa naszej konwencji z przekazywaniem
//przez wskaźnik)
istream& operator>>(istream & input, Point& p){
    CheckNextChar('(', &input);
    p.SetX(ReadNumber(&input));
    CheckNextChar(',', &input);
    IgnoreWhitespace(&input);
    p.SetY(ReadNumber(&input));
    CheckNextChar(')', &input);
    return input;      // Umożliwia cin >> a >> b >> c;
}

ostream& operator<<(ostream & output, Point& p){
    return output << '(' << p.x_ << ',' << p.y_ << ')';
}