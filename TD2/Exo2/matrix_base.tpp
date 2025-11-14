#include "matrix_base.h"
#include <iostream>

template <typename T>
MatrixBase<T>::MatrixBase()
{
}

template <typename T>
MatrixBase<T>::MatrixBase(vector<T, T>, size_t row, size_t col)
{
}

template <typename T>
void MatrixBase<T>::addElement(size_t row, size_t col)
{
}

template <typename T>
vector<T, T> MatrixBase<T>::getElement(size_t row, size_t col) const
{
}

template <typename T>
size_t MatrixBase<T>::getRows() const
{
}

template <typename T>
size_t MatrixBase<T>::getCols() const
{
}

template <typename T>
ostream &MatrixBase<T>::display(ostream &os) const
{
}