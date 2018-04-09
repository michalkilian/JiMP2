//
// Created by Michał on 2018-04-09.
//

#ifndef JIMP_EXERCISES_MATRIX_H
#define JIMP_EXERCISES_MATRIX_H

#include <initializer_list>
#include<iostream>
#include <complex>
#include <vector>

namespace algebra {

    class Matrix {
    public:
        Matrix();

        Matrix(unsigned int x, unsigned int y);

        Matrix(std::initializer_list<std::vector<std::complex<double>>> in);

        void set(unsigned long x, unsigned long y, std::complex<double> in);

        std::complex<double> get(unsigned int x, unsigned int y) const;

        unsigned int getx() const;

        unsigned int gety() const;

        std::pair<size_t, size_t> Size() const;


        Matrix Add(const Matrix &mm) const;

        Matrix Sub(const Matrix &mm) const;

        Matrix Pow(int n) const;

        Matrix Mul(const Matrix &mm) const;

        std::string Print() const;

    private:
        std::vector<std::vector<std::complex<double>>> matrix_;
        unsigned int x_, y_;
    };

}
#endif //JIMP_EXERCISES_MATRIX_H
