#include "timeSeriesDataset.h"

TimeSeriesDataset::TimeSeriesDataset() {}
TimeSeriesDataset::TimeSeriesDataset(bool _znormalise, bool _isTrain, vector<double> _data, vector<int> _labels, int _maxLength, int _numberOfSamples) :
    znormalise(_znormalise), isTrain(_isTrain), data(_data), labels(_labels), maxLength(_maxLength), numberOfSamples(_numberOfSamples) {}

bool TimeSeriesDataset::getZnormalise() const {
    return znormalise;
}
bool TimeSeriesDataset::getIsTrain() const {
    return isTrain;
}
vector<double> TimeSeriesDataset::getData() const {
    return data;
}
vector<int> TimeSeriesDataset::getlabels() const {
    return labels;
}
int TimeSeriesDataset::getMaxLength() const {
    return maxLength;
}
int TimeSeriesDataset::getNumberOfSamples() const {
    return numberOfSamples;
}
void TimeSeriesDataset::setZnormalise(bool _znormalise) {
    znormalise = _znormalise;
}
void TimeSeriesDataset::setIsTrain(bool _isTrain) {
    isTrain = _isTrain;
}
void TimeSeriesDataset::setData(vector<double> _data) {
    data = _data;
}
void TimeSeriesDataset::setLabels(vector<int> _labels) {
    labels = _labels;
}
void TimeSeriesDataset::setMaxLength(int _maxLength) {
    maxLength = _maxLength;
}
void TimeSeriesDataset::setNumberOfSamples(int _numberOfSamples) {
    numberOfSamples = _numberOfSamples;
}

double TimeSeriesDataset::euclidean_distance(const vector<double> distance1, const vector<double> distance2 ) {
    double sum = 0.0;
    for (size_t i = 0; i < distance1.size(); ++i) {
        double diff = distance1[i] - distance2[i];
        sum += diff * diff;
    }
    return sqrt(sum);
}

double TimeSeriesDataset::dynamicTimeWarping(const vector<double> &ts1, const vector<double> &ts2) {
    size_t n = ts1.size();
    size_t m = ts2.size();
    vector<vector<double>> dtw(n + 1, vector<double>(m + 1, numeric_limits<double>::infinity()));
    dtw[0][0] = 0.0;
    dtw[1][0] = numeric_limits<double>::infinity();
    dtw[0][1] = numeric_limits<double>::infinity();

    for (size_t i = 1; i <= n; ++i) {
        for (size_t j = 1; j <= m; ++j) {
            double cost = fabs(ts1[i - 1] - ts2[j - 1]);
            dtw[i][j] = cost + min({dtw[i - 1][j],    // insertion
                                    dtw[i][j - 1],    // deletion
                                    dtw[i - 1][j - 1] // match
                                   });
        }
    }
    return sqrt(dtw[n][m]);
}