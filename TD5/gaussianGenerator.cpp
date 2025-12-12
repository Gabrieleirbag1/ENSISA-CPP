#include "gaussianGenerator.h"

GaussianGenerator::GaussianGenerator() : TimeSeriesGenerator() {}

GaussianGenerator::GaussianGenerator(int _seed) : TimeSeriesGenerator(_seed) {}

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