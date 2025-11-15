#include "matrix_numerical.hpp"

template <typename T>
MatrixNumerical<T>::MatrixNumerical() : MatrixBase<T>()
{
}

template <typename T>
MatrixNumerical<T>::MatrixNumerical(std::vector<std::vector<T>> data) : MatrixBase<T>(data)
{
}

template <typename T>
MatrixNumerical<T>::MatrixNumerical(size_t rows, size_t cols, T value) : MatrixBase<T>(rows, cols, value)
{
}

template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator+(const MatrixNumerical<T> &other) const
{
    unsigned int dataSize = this->data.size();

    std::vector<std::vector<T>> result(this->rows, std::vector<T>(this->cols, T()));

    for (unsigned int i = 0; i < dataSize; i++)
    {
        unsigned int rowSize = this->data[i].size();
        for (unsigned int j = 0; j < rowSize; j++)
        {
            result[i][j] = this->getElement(i, j) + other.getElement(i, j);
        }
    }
    return MatrixNumerical<T>(result);
}

template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator-(const MatrixNumerical<T> &other) const
{
    unsigned int dataSize = this->data.size();

    std::vector<std::vector<T>> result(this->rows, std::vector<T>(this->cols, T()));

    for (unsigned int i = 0; i < dataSize; i++)
    {
        unsigned int rowSize = this->data[i].size();
        for (unsigned int j = 0; j < rowSize; j++)
        {
            result[i][j] = this->getElement(i, j) - other.getElement(i, j);
        }
    }
    return MatrixNumerical<T>(result);
}

template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator*(const MatrixNumerical<T> &other) const
{
    unsigned int dataSize = this->data.size();

    std::vector<std::vector<T>> result(this->rows, std::vector<T>(this->cols, T()));

    for (unsigned int i = 0; i < dataSize; i++)
    {
        unsigned int rowSize = this->data[i].size();
        for (unsigned int j = 0; j < rowSize; j++)
        {
            result[i][j] = this->getElement(i, j) * other.getElement(i, j);
        }
    }
    return MatrixNumerical<T>(result);
}

template <typename T>
T MatrixNumerical<T>::getDeterminant() const
{
    if (this->rows != this->cols)
    {
        throw std::invalid_argument("Determinant is only defined for square matrices.");
        return 0;
    }

    size_t matrice_size = this->rows;

    if (matrice_size == 1)
    {
        return this->getElement(0, 0);
    }
    else if (matrice_size == 2)
    {
        return (this->getElement(0, 0) * this->getElement(1, 1)) - (this->getElement(1, 0) * this->getElement(0, 1));
    }

    T determinant = T();

    for (size_t p = 0; p < matrice_size; p++)
    {
        MatrixNumerical<T> subMatrix(matrice_size - 1, matrice_size - 1, T());

        for (size_t i = 1; i < matrice_size; i++)
        {
            size_t sub_j = 0;
            for (size_t j = 0; j < matrice_size; j++)
            {
                if (j == p)
                    continue;
                subMatrix.addElement(i - 1, sub_j, this->getElement(i, j));
                sub_j++;
            }
        }

        T subDeterminant = subMatrix.getDeterminant();
        determinant += (p % 2 == 0 ? 1 : -1) * this->getElement(0, p) * subDeterminant;
    }

    return determinant;
}