#include <vector>
#include <ostream>
#include "matrix_base.hpp"

#ifndef MATRIX_NUMERICAL_H
#define MATRIX_NUMERICAL_H

using namespace std;

template <typename T>
class MatrixNumerical : public MatrixBase<T>
{
public:
    MatrixNumerical();
    MatrixNumerical(std::vector<std::vector<T>> data);
    MatrixNumerical(size_t rows, size_t cols, T value);

    virtual T getDeterminant() const;
    virtual MatrixNumerical<T> getInverse() const;

    MatrixNumerical<T> operator+(const MatrixNumerical<T>& other) const;
    MatrixNumerical<T> operator-(const MatrixNumerical<T>& other) const;
    MatrixNumerical<T> operator*(const MatrixNumerical<T>& other) const;
};

#include "matrix_numerical.tpp"

#endif

