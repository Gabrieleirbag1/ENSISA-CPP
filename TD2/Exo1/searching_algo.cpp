
#include <iostream>
#include "searching_algo.h"

SearchingAlgo::SearchingAlgo() {}

int SearchingAlgo::search(std::vector<int> elements, int searchKey)
{
    unsigned int vecSize = elements.size();
    for (unsigned int i = 0; i < vecSize; i++)
    {
        if (elements[i] == searchKey) {
            return i;
        }
    }
    return -1;
}

void SearchingAlgo::displaySearchResults(std::ostream &os, int result, int target)
{
}