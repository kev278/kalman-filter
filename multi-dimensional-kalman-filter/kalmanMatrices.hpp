#include "Eigen/Dense"

class kalmanMatrices
{
    public:
    Eigen::MatrixXd x;
    Eigen::MatrixXd P;
    Eigen::MatrixXd u;
    Eigen::MatrixXd F;
    Eigen::MatrixXd H;
    Eigen::MatrixXd R;
    Eigen::MatrixXd I;
    Eigen::MatrixXd Z;


    

        void setX()
        {
            x(0, 0) = 0;
            x(1, 0) = 0;
        }

        void setP()
        {
            P(0, 0) = 1000;
            P(0, 1) = 0;
            P(1, 0) = 0;
            P(1, 1) = 1000;
        }

        void setU()
        {
            u(0, 0) = 0;
            u(1, 0) = 0;
        }

        void setF()
        {
            F(0, 0) = 1;
            F(0, 1) = 1;
            F(1, 0) = 0;
            F(1, 1) = 1;
        }

        void setH()
        {
            H(0, 0) = 1;
            H(0, 1) = 0;
        }

        void setR()
        {
            R(0, 0) = 1;
        }

        void setI()
        {
            I(0, 0) = 1;
            I(0, 1) = 0;
            I(1, 0) = 0;
            I(1, 1) = 1;
        }

        void setZ()
        {
            Z(0, 0) = 1;
            Z(0, 1) = 2;
            Z(0, 2) = 3;
        }


};