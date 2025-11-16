#include "matrix_numerical.hpp"

template <typename T>
MatrixNumerical<T> getCofactor(const MatrixNumerical<T> &matrix, size_t p, size_t q, size_t matrice_size)
{
    MatrixNumerical<T> cofactorMatrix(matrice_size - 1, matrice_size - 1, T());
    size_t i_cofactor = 0, j_cofactor = 0;

    for (size_t i = 0; i < matrice_size; i++)
    {
        for (size_t j = 0; j < matrice_size; j++)
        {
            if (i != p && j != q)
            {
                cofactorMatrix.addElement(i_cofactor, j_cofactor, matrix.getElement(i, j));
                j_cofactor++;
                if (j_cofactor == matrice_size - 1)
                {
                    j_cofactor = 0;
                    i_cofactor++;
                }
            }
        }
    }
    return cofactorMatrix;
}

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

template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::getInverse() const
{
    if (this->rows != this->cols)
    {
        throw std::invalid_argument("Inverse is only defined for square matrices.");
    }
    size_t matrice_size = this->rows;
    T determinant = this->getDeterminant();

    if (determinant == T())
    {
        throw std::runtime_error("Matrix is singular and cannot be inverted.");
    }

    MatrixNumerical<T> adjugate(matrice_size, matrice_size, T());
    for (size_t i = 0; i < matrice_size; i++)
    {
        for (size_t j = 0; j < matrice_size; j++)
        {
            MatrixNumerical<T> cofactorMatrix = getCofactor(*this, i, j, matrice_size);
            T cofactorDet = cofactorMatrix.getDeterminant();
            T sign = ((i + j) % 2 == 0) ? 1 : -1;
            adjugate.addElement(j, i, sign * cofactorDet); // Note the transpose here
        }
    }
    MatrixNumerical<T> inverse(matrice_size, matrice_size, T());
    for (size_t i = 0; i < matrice_size; i++)
    {
        for (size_t j = 0; j < matrice_size; j++)
        {
            inverse.addElement(i, j, adjugate.getElement(i, j) / determinant);
        }
    }
    return inverse;
}