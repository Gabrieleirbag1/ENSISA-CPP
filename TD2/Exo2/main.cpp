#include<iostream>
#include<cmath>
#include "matrix_base.hpp"
#include "matrix_numerical.hpp"

using namespace std;

int main() {

    MatrixBase<int> matrixObj;   
    
    cout << "MATRIX BASE TESTS" << endl;
    MatrixBase<int> matrixObj2(5, 5, 0);
    matrixObj2.addElement(0, 0, 5);
    matrixObj2.display(cout);
    int testElement = matrixObj2.getElement(0, 0);
    cout << endl << "TESTING METHODS" << endl;
    cout << "getRows: " << matrixObj2.getRows() << endl;
    cout << "getCols: " << matrixObj2.getCols() << endl;
    cout << "getelement " << testElement << endl;

    cout << endl << "-----------------------" << endl;
    cout << "MATRIX NUMERICAL TESTS" << endl;
    cout << "Matrix 1: " << endl;
    MatrixNumerical<int> matrixNumObj(4, 4, 0);
    matrixNumObj.addElement(0, 0, 5);
    matrixNumObj.addElement(1, 1, 2);
    matrixNumObj.addElement(2, 2, 2);
    matrixNumObj.addElement(3, 3, 2);
    matrixNumObj.display(cout);

    cout << "Matrix 2: " << endl;
    MatrixNumerical<int> matrixNumObj2(4, 4, 0);
    matrixNumObj2.addElement(0, 0, 8);
    matrixNumObj2.addElement(1, 1, 3);
    matrixNumObj2.addElement(2, 2, 2);
    matrixNumObj2.addElement(3, 3, 9);
    matrixNumObj2.display(cout);

    MatrixNumerical<int> matrixAddition = matrixNumObj + matrixNumObj2;
    MatrixNumerical<int> matrixSubtraction = matrixNumObj - matrixNumObj2;
    MatrixNumerical<int> matrixMultiplication = matrixNumObj * matrixNumObj2;
    MatrixNumerical<int> matrixDivision = matrixNumObj / matrixNumObj2;
    cout << endl << "After Addition: " << endl;
    matrixAddition.display(cout);
    cout << "After Subtraction: " << endl;
    matrixSubtraction.display(cout);
    cout << "After Multiplication: " << endl;
    matrixMultiplication.display(cout);
    cout << "After Division: " << endl;
    matrixDivision.display(cout);
    cout << "Determinant: " << matrixNumObj.getDeterminant() << endl << endl;

    cout << endl << "-----------------------" << endl;
    cout << "INVERSE MATRIX TEST" << endl;
    MatrixNumerical<double> matrixInvObj(2, 2, 0.0);
    matrixInvObj.addElement(0, 0, 4.0);
    matrixInvObj.addElement(0, 1, 7.0);
    matrixInvObj.addElement(1, 0, 2.0);
    matrixInvObj.addElement(1, 1, 6.0);
    cout << "Matrix to invert: " << endl;
    matrixInvObj.display(cout);
    MatrixNumerical<double> matrixInverse = matrixInvObj.getInverse();
    cout << "Inverse Matrix: " << endl;
    matrixInverse.display(cout);

    cout << endl << "-----------------------" << endl;
    cout << "MATRIX IDENTITY TEST" << endl;
    MatrixNumerical<int> matrixIdentity = MatrixNumerical<int>::getIdentity(16);
    matrixIdentity.display(cout);
    
    return 0;
}