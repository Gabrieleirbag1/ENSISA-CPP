#include<iostream>
#include "linear_search.h"

using namespace std;

int main() {
    LinearSearch linearObj;
    vector<int> testVector = {1, 4, 2, 3, 5};
    int results = linearObj.search(testVector, 3);
    linearObj.displaySearchResults(std::cout, results, 4);
    return 0;
}