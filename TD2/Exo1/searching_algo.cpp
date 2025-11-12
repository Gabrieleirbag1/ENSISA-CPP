
#include<iostream>
#include "searching_algo.h"

SearchingAlgo::SearchingAlgo() {}

int SearchingAlgo::search(std::vector<int> elements, int searchKey) {
    for (int num : elements) {
        std::cout << num << std::endl;
    }
}

void SearchingAlgo::displaySearchResults(std::ostream& os, int result, int target) {

}