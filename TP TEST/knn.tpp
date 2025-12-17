#include "knn.hpp"

template <typename T>
KNN<T>::KNN() : k(3) {}

template <typename T>
KNN<T>::KNN(int _k) : k(_k) {}

template <typename T>
int KNN<T>::getK() const {
    return k;
}

template <typename T>
vector<int> KNN<T>::findNearestNeighbours(
    vector<T>& trainData,
    T& target
) {
    vector<pair<double, int>> distances; // pair of (distance, index)
    for (size_t i = 0; i < trainData.size(); ++i) {
        double distance = similarityMeasure(trainData[i], target);
        distances.push_back(make_pair(distance, i));
    }
    sort(distances.begin(), distances.end());
    vector<int> neighbours;
    for (int i = 0; i < k && i < distances.size(); ++i) {
        neighbours.push_back(distances[i].second);
    }
    return neighbours;
}