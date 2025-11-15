#include <vector>
#include <ostream>
#include "matrix_base.hpp"

#ifndef MATRIX_NUMERICAL_H
#define MATRIX_NUMERICAL_H

using namespace std;

template <typename T>
class MatrixNumerical : MatrixBase<T>
{
public:
    MatrixNumerical();
    MatrixNumerical(size_t rows, size_t cols, T value);
};

#endif