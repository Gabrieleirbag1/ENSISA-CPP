#include<iostream>
#include "matrix_base.hpp"
#include "matrix_numerical.hpp"

using namespace std;

int main() {

    MatrixBase<int> matrixObj;   
    
    MatrixBase<int> matrixObj2(5, 5, 0);

    MatrixNumerical<int> matrixNumObj(5, 5, 0);
    matrixNumObj.getDeterminant();

    matrixObj2.addElement(0, 0, 5);

    int testElement = matrixObj2.getElement(0, 0);

    matrixObj2.display(cout);

    cout << "\nTESTING METHODS" << endl;
    cout << "getRows: " << matrixObj2.getRows() << endl;
    cout << "getCols: " << matrixObj2.getCols() << endl;
    cout << "getelement " << testElement << endl;
    
    return 0;
}