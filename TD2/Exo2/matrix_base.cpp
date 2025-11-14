#include "matrix_base.h"
#include <algorithm>
#include <cmath>
#include <iostream>

template <typename T>
MatrixBase<T>::MatrixBase()
{
}

template <typename T>
void MatrixBase<T>::addElement(int rowIndex, int colIndex)
{
}

template <typename T>
vector<T, T> MatrixBase<T>::getElement(int rowIndex, int colIndex) const
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