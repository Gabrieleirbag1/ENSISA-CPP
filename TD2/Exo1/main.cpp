#include<iostream>
#include "linear_search.h"

using namespace std;

int main() {
    LinearSearch linearObj;
    vector<int> testVector = {1, 0, 2, 3, 5};
    vector<int> testVector2 = {1, 4, 2, 3, 5};

    int results = linearObj.search(testVector, 4);
    linearObj.displaySearchResults(std::cout, results, 4);
    std::cout << "----------------" << std::endl;
    int results2 = linearObj.search(testVector2, 4);
    linearObj.displaySearchResults(std::cout, results2, 4);

    return 0;
}