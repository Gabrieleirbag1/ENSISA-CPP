#include<iostream>
#include "matrix_base.hpp"

using namespace std;

int main() {

    MatrixBase<int> matrixObj;   
    
    MatrixBase<int> matrixObj2(5, 5, 0);

    matrixObj2.addElement(0, 0, 5);

    vector<vector<int>> test = matrixObj2.getElement(5);

    matrixObj2.display(cout);
    matrixObj2.getRows();
    matrixObj2.getCols();
    
    return 0;
}