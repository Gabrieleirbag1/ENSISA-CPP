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
    MatrixNumerical<int> matrixNumObj(4, 4, 0);
    matrixNumObj.addElement(0, 0, 5);
    matrixNumObj.addElement(1, 1, 2);
    matrixNumObj.addElement(2, 2, 2);
    matrixNumObj.addElement(3, 3, 2);
    matrixNumObj.display(cout);
    MatrixNumerical<int> matrixAddition = matrixNumObj + matrixNumObj;
    MatrixNumerical<int> matrixSubtraction = matrixNumObj - matrixNumObj;
    MatrixNumerical<int> matrixMultiplication = matrixNumObj * matrixNumObj;
    cout << "After Addition: " << endl;
    matrixAddition.display(cout);
    cout << "After Subtraction: " << endl;
    matrixSubtraction.display(cout);
    cout << "After Multiplication: " << endl;
    matrixMultiplication.display(cout);
    cout << "Déterminant: " << matrixNumObj.getDeterminant() << endl << endl;
    
    return 0;
}