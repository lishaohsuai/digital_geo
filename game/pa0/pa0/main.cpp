#include<cmath>
#include<eigen3/Eigen/Core>
#include<eigen3/Eigen/Dense>
#include<iostream>
#define _USE_MATH_DEFINES
int main(){
    Eigen::Vector3d test(2.0f,1.0f,1.0f);
    Eigen::Matrix3d rota;
    Eigen::Matrix3d tran;
    double theta = 45.0/180.0*M_PI;
    rota << cos(theta), -1.0*sin(theta), 0,
            sin(theta), cos(theta), 0, 
            0, 0, 1;
    tran << 1, 0, 1, 
            0, 1, 2, 
            0, 0, 1;
    test = tran * rota * test;
    std::cout << test << std::endl;
    std::cout <<  "After rotation and transform the point sits at " 
        << test[0] << "," << test[1] << std::endl;
    return 0;
}
