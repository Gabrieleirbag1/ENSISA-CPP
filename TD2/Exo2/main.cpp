#include<iostream>
#include<cmath>
#include "matrix_base.hpp"
#include "matrix_numerical.hpp"

using namespace std;

template <typename T>
void runMatrixTests(const string& typeName) {
    cout << "\n=======================================" << endl;
    cout << "TESTING WITH TYPE: " << typeName << endl;
    cout << "=======================================" << endl;
    
    // Matrix Base Tests
    cout << "\nMATRIX BASE TESTS" << endl;
    MatrixBase<T> matrixObj2(5, 5, T(0));
    matrixObj2.addElement(0, 0, T(5));
    matrixObj2.display(cout);
    T testElement = matrixObj2.getElement(0, 0);
    cout << "\nTESTING METHODS" << endl;
    cout << "getRows: " << matrixObj2.getRows() << endl;
    cout << "getCols: " << matrixObj2.getCols() << endl;
    cout << "getElement: " << testElement << endl;

    // Matrix Numerical Tests
    cout << "\n-----------------------" << endl;
    cout << "MATRIX NUMERICAL TESTS" << endl;
    cout << "Matrix 1: " << endl;
    MatrixNumerical<T> matrixNumObj(4, 4, T(0));
    matrixNumObj.addElement(0, 0, T(5));
    matrixNumObj.addElement(1, 1, T(2));
    matrixNumObj.addElement(2, 2, T(2));
    matrixNumObj.addElement(3, 3, T(2));
    matrixNumObj.display(cout);

    cout << "Matrix 2: " << endl;
    MatrixNumerical<T> matrixNumObj2(4, 4, T(0));
    matrixNumObj2.addElement(0, 0, T(8));
    matrixNumObj2.addElement(1, 1, T(3));
    matrixNumObj2.addElement(2, 2, T(2));
    matrixNumObj2.addElement(3, 3, T(9));
    matrixNumObj2.display(cout);

    // Operations
    MatrixNumerical<T> matrixAddition = matrixNumObj + matrixNumObj2;
    MatrixNumerical<T> matrixSubtraction = matrixNumObj - matrixNumObj2;
    MatrixNumerical<T> matrixMultiplication = matrixNumObj * matrixNumObj2;
    MatrixNumerical<T> matrixDivision = matrixNumObj / matrixNumObj2;
    
    cout << "\nAfter Addition: " << endl;
    matrixAddition.display(cout);
    cout << "After Subtraction: " << endl;
    matrixSubtraction.display(cout);
    cout << "After Multiplication: " << endl;
    matrixMultiplication.display(cout);
    cout << "After Division: " << endl;
    matrixDivision.display(cout);
    cout << "Determinant: " << matrixNumObj.getDeterminant() << endl;

    // Inverse Matrix Test
    cout << "\n-----------------------" << endl;
    cout << "INVERSE MATRIX TEST" << endl;
    MatrixNumerical<T> matrixInvObj(2, 2, T(0));
    matrixInvObj.addElement(0, 0, T(4));
    matrixInvObj.addElement(0, 1, T(7));
    matrixInvObj.addElement(1, 0, T(2));
    matrixInvObj.addElement(1, 1, T(6));
    cout << "Matrix to invert: " << endl;
    matrixInvObj.display(cout);
    MatrixNumerical<T> matrixInverse = matrixInvObj.getInverse();
    cout << "Inverse Matrix: " << endl;
    matrixInverse.display(cout);

    // Identity Matrix Test
    cout << "\n-----------------------" << endl;
    cout << "MATRIX IDENTITY TEST (4x4)" << endl;
    MatrixNumerical<T> matrixIdentity = MatrixNumerical<T>::getIdentity(4);
    matrixIdentity.display(cout);
}

int main() {
    runMatrixTests<int>("int");
    runMatrixTests<float>("float");
    runMatrixTests<double>("double");
    
    return 0;
}