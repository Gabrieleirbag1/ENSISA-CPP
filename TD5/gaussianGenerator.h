#ifndef GAUSSIAN_GENERATOR_H
#define GAUSSIAN_GENERATOR_H

#include "timeSeriesGenerator.h"

class GaussianGenerator : public TimeSeriesGenerator {
    public:
        GaussianGenerator();
        GaussianGenerator(int);


        double getMoyenne() const;
        double getEcartType() const;

        void setMoyenne(double);
        void setEcartType(double);

    private:
        double moyenne;
        double ecartType;
};

#endif