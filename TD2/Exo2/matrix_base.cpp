#include "matrix_base.h"
#include <algorithm>
#include <cmath>
#include<iostream>

template <class T>
MatrixBase<T>::MatrixBase()
{
}

template <class T>
void MatrixBase<T>::addElement(int rowIndex, int colIndex)
{}
template <class T>
vector<T, T> MatrixBase<T>::getElement(int rowIndex, int colIndex) const
{}

template <class T>
size_t MatrixBase<T>::getRows() const
{}

template <class T>
size_t MatrixBase<T>::getCols() const
{}