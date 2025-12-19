#ifndef TIME_SERIES_DATA_H
#define TIME_SERIES_DATA_H

#include <vector>
#include <cmath>
#include <limits>
#include <algorithm>
#include <stdexcept>

using namespace std;

class TimeSeriesDataset
{
public:
    TimeSeriesDataset();
    TimeSeriesDataset(bool, bool);
    TimeSeriesDataset(bool, bool, vector<double>, vector<int>, int, int);
    
    bool getZnormalise() const;
    bool getIsTrain() const;
    vector<double> getData() const;
    vector<int> getlabels() const;
    int getMaxLength() const;
    int getNumberOfSamples() const;

    void setZnormalise(bool);
    void setIsTrain(bool);
    void setData(vector<double>);
    void setLabels(vector<int>);
    void setMaxLength(int);
    void setNumberOfSamples(int);

    void addTimeSeries(const vector<double>& series);
    void addTimeSeries(const vector<double>& series, int label);
    vector<double> getTimeSeries(int index) const;

    static double euclidean_distance(const vector<double> distance1, const vector<double> distance2 );
    static double dynamicTimeWarping(const vector<double> &ts1, const vector<double> &ts2);
private:
    bool znormalise;
    bool isTrain;
    vector<double> data;
    vector<int> labels;
    int maxLength;
    int numberOfSamples;
};

#include "timeSeriesDataset.tpp"

#endif