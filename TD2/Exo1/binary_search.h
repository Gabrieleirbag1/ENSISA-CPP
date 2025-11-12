#include <stdio.h>
#include <vector>
#include <ostream>
#include "searching_algo.h"

#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

class BinarySearch : public SearchingAlgo {
    public:
    BinarySearch();
    int search(const std::vector<int> elements, int searchKey) override;
};

#endif