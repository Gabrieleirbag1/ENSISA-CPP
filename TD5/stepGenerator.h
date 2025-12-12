#ifndef STEP_GENERATOR_H
#define STEP_GENERATOR_H

#include "timeSeriesGenerator.h"

class StepGenerator : public TimeSeriesGenerator {
    public:
        StepGenerator();
        StepGenerator(int);

        vector<double> generateTimeseries(int) const override;
};

#endif