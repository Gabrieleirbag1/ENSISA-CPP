#include <stdio.h>
#include <vector>
#include <ostream>
#include "searching_algo.h"

#ifndef LINEAR_SEARCH_H
#define LINEAR_SEARCH_H

class LinearSearch : public SearchingAlgo {
    public:
    LinearSearch();
    int search(const std::vector<int> elements, int searchKey) override;
};

#endif