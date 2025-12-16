#include "stepGenerator.hpp"

StepGenerator::StepGenerator() : TimeSeriesGenerator() {}

StepGenerator::StepGenerator(int _seed) : TimeSeriesGenerator(_seed) {}

vector<double> StepGenerator::generateTimeseries(int length) const {
    vector<double> series;
    series.reserve(length);

    double currentValue = 0.0;
    for (int i = 0; i < length; ++i) {
        if (i != 0) {
            if (rand() % 2 == 0) {
                currentValue = rand() % 101;
            }
        }
        series.push_back(currentValue);
    }

    return series;
}