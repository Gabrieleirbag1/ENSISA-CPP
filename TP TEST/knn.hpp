#ifndef KNN_H
#define KNN_H

#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
class KNN
{
    protected:
        int k;

    public:
        KNN();
        KNN(int k);

        int getK() const;

        vector<int> findNearestNeighbours(
            vector<T>& trainData,
            T& target
        );

        virtual double similarityMeasure(
            T& a,
            T& b
        ) const = 0;
};

#include "knn.tpp"

#endif