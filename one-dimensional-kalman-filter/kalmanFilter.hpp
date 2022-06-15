class kalmanFilter
{
    public:

        void update(double meanBelief, double varBelief, double meanMeasurement, double varMeasurement, double &newMean, double &newVar)
        {
            newMean = (varMeasurement * meanBelief + varBelief * meanMeasurement) / (varBelief + varMeasurement);
            newVar = 1 / (1 / varBelief + 1 / varMeasurement);
        }

        void predict(double meanBelief, double varBelief, double meanMotion, double varMotion, double &newMean, double &newVar)
        {
            newMean = meanBelief + meanMotion;
            newVar = varBelief + varMotion;
        }
};