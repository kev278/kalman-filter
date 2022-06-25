#include "kalman_filter.hpp"

KalmanFilter::KalmanFilter(vec x_, mat P_, mat F_, mat Q_, mat H_, mat R_)
: x(x_), P(P_), F(F_), Q(Q_), H(H_), R(R_)
{

}