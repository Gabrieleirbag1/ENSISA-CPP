#include <stepGenerator.h>

StepGenerator::StepGenerator() : TimeSeriesGenerator() {}

StepGenerator::StepGenerator(int _seed) : TimeSeriesGenerator(_seed) {}

vector<double> StepGenerator::generateTimeseries(int length) const {
    vector<double> series;
    series.reserve(length);

    double currentValue = 0.0;
    for (int i = 0; i < length; ++i) {
        if (i % 10 == 0 && i != 0) {
            currentValue += (rand() % 3 - 1);
        }
        series.push_back(currentValue);
    }

    return series;
}