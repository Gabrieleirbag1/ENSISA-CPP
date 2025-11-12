#include<iostream>
#include "linear_search.h"
#include "binary_search.h"

using namespace std;

int main() {
    LinearSearch linearObj;
    vector<int> testVector = {1, 0, 2, 3, 5};
    vector<int> testVector2 = {1, 4, 2, 3, 5};

    int linear_results = linearObj.search(testVector, 4);
    linearObj.displaySearchResults(std::cout, linear_results, 4);
    std::cout << "----------------" << std::endl;
    int linear_results2 = linearObj.search(testVector2, 4);
    linearObj.displaySearchResults(std::cout, linear_results2, 4);
    std::cout << "----------------" << std::endl;

    BinarySearch binaryObj;

    int binary_results = binaryObj.search(testVector, 4);
    linearObj.displaySearchResults(std::cout, binary_results, 4);
    std::cout << "----------------" << std::endl;
    int binary_results2 = binaryObj.search(testVector2, 4);
    linearObj.displaySearchResults(std::cout, binary_results2, 4);
    std::cout << "----------------" << std::endl;


    return 0;
}