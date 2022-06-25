//#include "kalmanFilter.hpp"
#include "kalmanMatrices.hpp"
#include <iostream>

int main()
{
    // add for loop for doing this size of measurements times
    kalmanMatrices Matrices;
    Eigen::MatrixXd y;
    y = Matrices.Z - (Matrices.H * Matrices.x);
    Eigen::MatrixXd S;
    Eigen::MatrixXd H_transpose;
    H_transpose = Matrices.H.transpose();
    S = Matrices.H * (Matrices.P * H_transpose) + Matrices.R;
    Eigen::MatrixXd K;
    K = Matrices.P * H_transpose * S.inverse();
    Matrices.x = Matrices.x + (K * y);

    Matrices.P = (Matrices.I - (K * Matrices.H)) * Matrices.P;

    Matrices.x = (Matrices.F * Matrices.x) + Matrices.u; 
    Eigen::MatrixXd F_transpose;
    F_transpose = Matrices.F.transpose();
    //Add Q if Q is non-zero
    Matrices.P = Matrices.F * Matrices.P * F_transpose;

    std::cout << "Here";
}