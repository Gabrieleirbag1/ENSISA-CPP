#include <vector>
#include <ostream>

#ifndef MATRIX_BASE_H
#define MATRIX_BASE_H

using namespace std;

template <typename T>
class MatrixBase
{
public:
    MatrixBase();
    MatrixBase(vector<T, T> data, size_t rows, size_t cols);

    vector<T, T> data;
    size_t rows;
    size_t cols;

    virtual void addElement(size_t row, size_t col);
    virtual vector<T, T> getElement(size_t row, size_t col) const;
    virtual size_t getRows() const;
    virtual size_t getCols() const;

    virtual ostream &display(ostream &os) const;
};

#include "matrix_base.tpp"

#endif