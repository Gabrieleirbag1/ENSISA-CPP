#include "matrix_base.h"
#include <iostream>

template <typename T>
MatrixBase<T>::MatrixBase()
{
}

template <typename T>
MatrixBase<T>::MatrixBase(vector<T> data, size_t rows, size_t cols, T value)
{
    data.assign(rows, (cols, value));
}

template <typename T>
void MatrixBase<T>::addElement(size_t row, size_t col, T value)
{
    data[row][col] = value;
}

template <typename T>
vector<T> MatrixBase<T>::getElement(T value) const
{
    unsigned int dataSize = data.size();
    for (unsigned int i=0; i < dataSize; i++) {

    }
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