#include "sinWaveGenerator.hpp"
#include "stepGenerator.hpp"
#include "gaussianGenerator.hpp"
#include "timeSeriesDataset.hpp"
#include "knn.hpp"
#include<iostream>
#include<vector>
using namespace std;
int main(){
TimeSeriesDataset trainData(false, true), testData(false, false);

GaussianGenerator gsg;
SinWaveGenerator swg;
StepGenerator stg;

vector<double> gaussian1 = gsg.generateTimeseries(11);
trainData.addTimeSeries(gaussian1, 0);
vector<double> gaussian2 = gsg.generateTimeseries(11);
trainData.addTimeSeries(gaussian2, 0);

vector<double> sin1 = swg.generateTimeseries(11);
trainData.addTimeSeries(sin1, 1);
vector<double> sin2 = swg.generateTimeseries(11);
trainData.addTimeSeries(sin2, 1);

vector<double> step1 = stg.generateTimeseries(11);
trainData.addTimeSeries(step1, 2);
vector<double> step2 = stg.generateTimeseries(11);
trainData.addTimeSeries(step2, 2);

vector<int> ground_truth;
testData.addTimeSeries(gsg.generateTimeseries(11));
ground_truth.push_back(0);

testData.addTimeSeries(swg.generateTimeseries(11));
ground_truth.push_back(1);

testData.addTimeSeries(stg.generateTimeseries(11));
ground_truth.push_back(2);

KNN knn_1(1, "dtw");

cout << knn_1.evaluate(trainData, testData, ground_truth) << endl;

KNN knn_2(2, "euclidean_distance");

cout << knn_2.evaluate(trainData, testData, ground_truth) << endl;

KNN knn_3(3, "euclidean_distance");

cout << knn_3.evaluate(trainData, testData, ground_truth) << endl;
}