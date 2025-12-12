#include "gaussianGenerator.h"

GaussianGenerator::GaussianGenerator() : TimeSeriesGenerator() {}

GaussianGenerator::GaussianGenerator(int _seed) : TimeSeriesGenerator(_seed) {}

vector<double> GaussianGenerator::generateTimeseries(int length) const {
    vector<double> series;
    series.reserve(length);

    for (int i = 0; i < length; ++i) {
        double u1 = static_cast<double>(rand()) / RAND_MAX;
        double u2 = static_cast<double>(rand()) / RAND_MAX;
        double z0 = sqrt(-2.0 * log(u1)) * cos(2.0 * M_PI * u2);
        double value = z0 * ecartType + moyenne;
        series.push_back(value);
    }

    return series;
}

double GaussianGenerator::getMoyenne() const {
    return moyenne;
}

double GaussianGenerator::getEcartType() const {
    return ecartType;
}

void GaussianGenerator::setMoyenne(double _moyenne) {
    moyenne = _moyenne;
}

void GaussianGenerator::setEcartType(double _ecartType) {
    ecartType = _ecartType;
}

