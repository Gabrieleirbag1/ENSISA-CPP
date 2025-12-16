#include "timeSeriesDataset.h"

TimeSeriesDataset::TimeSeriesDataset() {}

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