#include "linear_search.h"

LinearSearch::LinearSearch() : SearchingAlgo()
{
}

int LinearSearch::search(std::vector<int> elements, int searchKey)
{
    numberComparisons = 0;
    unsigned int vecSize = elements.size();
    for (unsigned int i = 0; i < vecSize; i++)
    {
        numberComparisons++;
        if (elements[i] == searchKey) {
            return i;
        }
    }
    return -1;
}