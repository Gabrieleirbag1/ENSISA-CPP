#ifndef SWIN_WAVE_GENERATOR_H
#define SWIN_WAVE_GENERATOR_H
#include "timeSeriesGenerator.h"
#include <cmath>

class SinWaveGenerator : public TimeSeriesGenerator {
    public:
        SinWaveGenerator();
        SinWaveGenerator(int);
        SinWaveGenerator(double _amplitude, double _frequency, double _phase, int _seed);

        vector<double> generateTimeseries(int) const override;

        double getAmplitude() const;
        double getFrequency() const;
        double getPhase() const;

        void setAmplitude(double);
        void setFrequency(double);
        void setPhase(double);

    private:
        double amplitude;
        double frequency;
        double phase;
};
#endif