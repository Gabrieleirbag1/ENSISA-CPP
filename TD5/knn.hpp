#ifndef KNN_H
#define KNN_H

#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

class TimeSeriesDataset; // forward declaration

class KNN {
    public:
        KNN();
        KNN(int, string);
        ~KNN();

        int getK() const;
        string getSimilarityMeasure() const;

        void setK(int);
        void setSimilarityMeasure(string);

        double evaluate(const TimeSeriesDataset& train, const TimeSeriesDataset& test, const vector<int>& ground_truth);

    private:
        int k;
        string similarity_measure;
};

#include "knn.tpp"

#endif