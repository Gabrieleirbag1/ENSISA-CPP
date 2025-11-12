
#include <iostream>
#include "searching_algo.h"

SearchingAlgo::SearchingAlgo() {}

int SearchingAlgo::search(std::vector<int> elements, int searchKey)
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

void SearchingAlgo::displaySearchResults(std::ostream &os, int results, int target)
{
    totalComparisons += numberComparisons;
    totalSearch++;
    averageComparisons = static_cast<double>(totalComparisons) / totalSearch;
    
    if (results != -1) {
        os << "Element " << target << " trouvé à l'indice " << results << std::endl;
        os << "Nombre de comparaisons: " << numberComparisons << std::endl;
    } else {
        os << "Element " << target << " non trouvé" << std::endl;
        os << "Nombre de comparaisons: " << numberComparisons << std::endl;
    }
    
    os << "Total de comparaisons: " << totalComparisons << std::endl;
    os << "Nombre total de recherches: " << totalSearch << std::endl;
    os << "Moyenne de comparaisons: " << averageComparisons << std::endl;
}