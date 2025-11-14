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

    vector<T, T> data;
    size_t rows;
    size_t cols;

    void addElement(int rowIndex, int colIndex);
    vector<T, T> getElement(int rowIndex, int colIndex) const;
    size_t getRows() const;
    size_t getCols() const;

    ostream &display(ostream &os) const;
};

#endif