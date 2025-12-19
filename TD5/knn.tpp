#include "knn.hpp"
#include "timeSeriesDataset.hpp"

KNN::KNN() {}
KNN::KNN(int _k, string _similarity_measure) : k(_k), similarity_measure(_similarity_measure) {}
KNN::~KNN() {}

int KNN::getK() const {
    return k;
}

string KNN::getSimilarityMeasure() const {
    return similarity_measure;
}

void KNN::setK(int _k) {
    k = _k;
}

void KNN::setSimilarityMeasure(string _similarity_measure) {
    similarity_measure = _similarity_measure;
}

double KNN::evaluate(const TimeSeriesDataset& train, const TimeSeriesDataset& test, const vector<int>& ground_truth) {
    if ((int)ground_truth.size() != test.getNumberOfSamples()) throw runtime_error("Ground truth size mismatch");
    int correct = 0;
    for (int i = 0; i < test.getNumberOfSamples(); ++i) {
        vector<double> test_ts = test.getTimeSeries(i);
        vector<pair<double, int>> distances;
        for (int j = 0; j < train.getNumberOfSamples(); ++j) {
            vector<double> train_ts = train.getTimeSeries(j);
            double dist;
            if (similarity_measure == "euclidean_distance") {
                dist = TimeSeriesDataset::euclidean_distance(test_ts, train_ts);
            } else if (similarity_measure == "dtw") {
                dist = TimeSeriesDataset::dynamicTimeWarping(test_ts, train_ts);
            } else {
                throw runtime_error("Unknown similarity measure");
            }
            distances.push_back({dist, train.getlabels()[j]});
        }
        sort(distances.begin(), distances.end());
        int pred;
        if (k == 1) {
            pred = distances[0].second;
        } else {
            map<int, int> count;
            for (int m = 0; m < k; ++m) {
                count[distances[m].second]++;
            }
            int max_count = 0;
            pred = -1;
            for (auto& p : count) {
                if (p.second > max_count) {
                    max_count = p.second;
                    pred = p.first;
                }
            }
        }
        if (pred == ground_truth[i]) correct++;
    }
    return (double)correct / ground_truth.size();
}