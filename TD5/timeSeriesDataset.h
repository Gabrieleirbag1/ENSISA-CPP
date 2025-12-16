#ifndef TIME_SERIES_DATA_H
#define TIME_SERIES_DATA_H

#include <vector>

using namespace std;

class TimeSeriesDataset
{
public:
    TimeSeriesDataset();
    
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
private:
    bool znormalise;
    bool isTrain;
    vector<double> data;
    vector<int> labels;
    int maxLength;
    int numberOfSamples;
};
#endif