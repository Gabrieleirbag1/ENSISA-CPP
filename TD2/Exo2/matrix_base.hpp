#ifndef MATRIX_BASE_H
#define MATRIX_BASE_H

#include <vector>
#include <ostream>

using namespace std;

template <typename T>
class MatrixBase
{
public:
    MatrixBase();
    MatrixBase(size_t rows, size_t cols, T value);

    vector<vector<T>> data;
    size_t rows;
    size_t cols;

    virtual void addElement(size_t row, size_t col, T value);
    virtual vector<vector<T>> getElement(T value) const;
    virtual size_t getRows() const;
    virtual size_t getCols() const;

    virtual ostream &display(ostream &os) const;
};

#include "matrix_base.tpp"

#endif