#ifndef KALMAN_FILTER_
#define KALMAN_FILTER_

#include "Eigen/Dense"

using vec = Eigen::VectorXd;
using mat = Eigen::MatrixXd;

class KalmanFilter
{
    private:
        vec x;  // State Vector
        mat P;  // State Covariance Matrix
        mat F;  // State Transition Matrix
        mat Q;  // Process Covariance Matrix
        mat H;  // Measurement Matrix
        mat R;  // Measurement Covariance Matrix
    
    public:
        KalmanFilter() = default;   // Constructor
        KalmanFilter(vec x_, mat P_, mat F_, mat Q_, mat H_, mat R_);  // Constructor with all members initialized
        /*
        Getters and Setters for all the private memebers
        */
        void setX(const vec x);  
        vec getX() const;
        void setP(const mat P);
        mat getP() const;
        void setF(const mat F);
        mat getF() const;
        void setQ(const mat Q);
        mat getQ() const;
        void setH(const mat H);
        mat getH() const;
        void setR(const mat R);
        mat getR() const;

        /*
        Predict(): Predicts x & P using the Process Model
        Update(): Updates x & z
        */
        void Predict();
        void Update(const vec &z);
};

#endif