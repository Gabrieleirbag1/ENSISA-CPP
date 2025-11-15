#include "matrix_numerical.hpp"

template <typename T>
MatrixNumerical<T>::MatrixNumerical() : MatrixBase<T>()
{
}

template <typename T>
MatrixNumerical<T>::MatrixNumerical(size_t rows, size_t cols, T value) : MatrixBase<T>(rows, cols, value)
{
}
