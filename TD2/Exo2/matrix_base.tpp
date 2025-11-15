#include "matrix_base.hpp"
#include <iostream>

template <typename T>
MatrixBase<T>::MatrixBase()
{
}

template <typename T>
MatrixBase<T>::MatrixBase(std::vector<std::vector<T>> _data) : data(_data), rows(_data.size()), cols(_data.empty() ? 0 : _data[0].size())
{
}


template <typename T>
MatrixBase<T>::MatrixBase(size_t rows, size_t cols, T value)
{
    data.assign(rows, vector<T>(cols, value));
    this->rows = rows;
    this->cols = cols;
}

template <typename T>
void MatrixBase<T>::addElement(size_t row, size_t col, T value)
{
    data[row][col] = value;
}

template <typename T>
T MatrixBase<T>::getElement(size_t row, size_t col) const
{
    return data[row][col];
}

template <typename T>
size_t MatrixBase<T>::getRows() const
{
    return rows;
}

template <typename T>
size_t MatrixBase<T>::getCols() const
{
    return cols;
}

template <typename T>
ostream &MatrixBase<T>::display(ostream &os) const
{
    unsigned int dataSize = data.size();
    for (unsigned int i = 0; i < dataSize; i++)
    {
        unsigned int rowSize = data[i].size();
        for (unsigned int j = 0; j < rowSize; j++)
        {
            os << data[i][j] << " ";
        }
        os << endl;
    }
    return os;
}