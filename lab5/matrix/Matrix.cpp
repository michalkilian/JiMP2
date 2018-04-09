//
// Created by Michał on 2018-04-09.
//

#include "Matrix.h"

namespace algebra {
    Matrix::Matrix() : x_(0), y_(0) {}

    Matrix::Matrix(unsigned int x, unsigned int y) : x_(x), y_(y) {
        int i = -1;
        matrix_.resize(x_);
        for (std::vector<std::complex<double>> &l : matrix_) {
            ++i;
            l.assign(y_, {0, 0});

        }
    }

    Matrix::Matrix(std::initializer_list<std::vector<std::complex<double>>> in) : x_(in.size()),
                                                                                  y_((*in.begin()).size()) {
        int i = -1;
        for (std::vector<std::complex<double>> l : in) {
            ++i;
            matrix_.push_back(l);

        }
    }

    void Matrix::set(unsigned long x, unsigned long y, std::complex<double> in) {
        this->matrix_[x][y] = in;
    }

    std::complex<double> Matrix::get(unsigned int x, unsigned int y) const {
        if (x < x_ && y < y_)
            return matrix_[x][y];
        else return {0, 0};
    }

    unsigned int Matrix::getx() const { return this->x_; }

    unsigned int Matrix::gety() const { return this->y_; }

    std::pair<size_t, size_t> Matrix::Size() const { return {x_, y_}; }

    Matrix Matrix::Add(const Matrix &mm) const {
        Matrix resultmx{x_, y_};
        if (this->x_ == mm.getx() && this->y_ == mm.gety()) {
            for (unsigned int i = 0; i < x_; ++i)
                for (unsigned int j = 0; j < y_; ++j) {
                    std::complex<double> tmpcomplex = this->get(i, j) + mm.get(i, j);
                    resultmx.set(i, j, tmpcomplex);
                }
            return resultmx;
        } else return Matrix();
    }

    Matrix Matrix::Sub(const Matrix &mm) const {
        Matrix resultmx{x_, y_};
        if (this->x_ == mm.getx() && this->y_ == mm.gety()) {
            for (int i = 0; i < x_; ++i)
                for (int j = 0; j < y_; ++j) {
                    std::complex<double> tmpcomplex = this->get(i, j) - mm.get(i, j);
                    resultmx.set(i, j, tmpcomplex);
                }
            return resultmx;
        } else
            return Matrix();
    }

    Matrix Matrix::Mul(const Matrix &in) const {
        unsigned int result_y = in.y_;
        unsigned int result_x = x_;
        if (y_ == in.x_) {
            Matrix res(result_x, result_y); //res(x_, in.y_)
            for (unsigned long m = 0; m < result_x; m++) {
                for (unsigned long i = 0; i < result_y; ++i) {
                    for (unsigned long j = 0; j < in.x_; j++) {
                        res.matrix_[m][i] += this->matrix_[m][j] * in.matrix_[j][i];
                    }
                }
            }
            return res;
        } else
            return Matrix();
    }

    Matrix Matrix::Pow(int n) const {
        if (this->x_ == this->y_) {
            Matrix out(x_, y_);
            if (n == 0) {
                for (unsigned long i = 0; i < this->x_; ++i)
                    out.matrix_[i][i] = 1.;
            } else if (n == 1) {
                for (int i = 0; i < x_; ++i)
                    for (int j = 0; j < y_; ++j)
                        out.matrix_[i][j] = matrix_[i][j];
                return out;
            } else if (n > 0) {
                for (int i = 0; i < x_; ++i)
                    for (int j = 0; j < y_; ++j)
                        out.matrix_[i][j] = matrix_[i][j];
                for (int i = 1; i < n; i++) {
                    out = out.Mul(*this);
                }
            }
            return out;
        } else
            return Matrix();
    }


    std::string Matrix::Print() const {
        if (x_ == 0 || y_ == 0) return "[]";
        std::stringstream result;
        result << "[";
        for (int i = 0; i < x_; ++i) {
            for (int j = 0; j < y_; ++j) {
                result << this->matrix_[i][j].real();
                result << "i" << this->matrix_[i][j].imag();
                if (j < y_ - 1)
                    result << ", ";
            }
            if (i < x_ - 1)
                result << "; ";
        }
        result << "]";
        return result.str();
    }

}