/*
This is a one dimensional Kalman Filter
*/

#include "Data.hpp"
#include "kalmanFilter.hpp"

#include "Data.hpp"

int main()
{
    Data filterData;
    filterData.setMeasurements();
    filterData.setMotions();
    filterData.setVarMeasurement();
    filterData.setVarMotion();
    filterData.setVar();
    filterData.setMean();
    
    std::vector<double> measurements = filterData.getMeasurements();
    std::vector<double> motions = filterData.getMotions();
    double varMeasurement = filterData.getVarMeasurement();
    double varMotion = filterData.getVarMotion();
    double var = filterData.getVar();
    double mean = filterData.getMean();

    int dataSize = measurements.size();

    std::vector<double> means;
    std::vector<double> vars;

    means.push_back(mean);
    vars.push_back(var);

    kalmanFilter Filter;

    double newMean{0}, newVar{0};

    for(int i = 0; i < dataSize; i++)
    {
       Filter.update(means.back(), vars.back(), measurements[i], varMeasurement, newMean, newVar);
       means.push_back(newMean);
       vars.push_back(newVar);
       Filter.predict(means.back(), vars.back(), motions[i], varMotion, newMean, newVar);
       means.push_back(newMean);
       vars.push_back(newVar);
    }

    // means and vars has all the predictions and updates stored alternatively
}