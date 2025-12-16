#ifndef TIME_SERIES_DATA_H
#define TIME_SERIES_DATA_H

#include <vector>
#include <cmath>
#include <limits>
#include <algorithm>

using namespace std;

class TimeSeriesDataset
{
public:
    TimeSeriesDataset();
    TimeSeriesDataset(bool, bool, vector<double>, vector<int>, int, int);
    
    bool getZnormalise() const;
    bool getIsTrain() const;
    vector<double> getData() const;
    vector<int> getlabels() const;
    int getMaxLength() const;
    int getMaxLength() const;
    int getNumberOfSamples() const;

    void setZnormalise(bool);
    void setIsTrain(bool);
    void setData(vector<double>);
    void setLabels(vector<int>);
    void setMaxLength(int);
    void setNumberOfSamples(int);

    double euclidean_distance(const vector<double> distance1, const vector<double> distance2 );
    double dynamicTimeWarping(const vector<double> &ts1, const vector<double> &ts2);
private:
    bool znormalise;
    bool isTrain;
    vector<double> data;
    vector<int> labels;
    int maxLength;
    int numberOfSamples;
};
#endif