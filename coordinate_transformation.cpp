# include <iostream>
#include <Eigen/Dense>

#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

using namespace std;
using namespace Eigen;

void camera_coordinations(double *xc, double *yc){
    cout << "Write the coordinations of the frame B (camera): \n";
    cout << "x: ";
    cin >> *xc;
    cout << "y: ";
    cin >> *yc;
    cout << "\n";
}

void camera_angle(double *theta){
    cout << "Write the angle of the frame B: \n";
    cout << "theta: ";
    cin >> *theta;
    cout << "\n";
}

void point_coordinations(double *x, double *y){
    cout << "Write the coordinations of the point P with respect to the frame B: \n";
    cout << "x: ";
    cin >> *x;
    cout << "y: ";
    cin >> *y;
    cout << "\n";
}

int main()
{
    double xc, yc, theta, xp, yp;
    camera_coordinations(&xc, &yc);
    camera_angle(&theta);
    point_coordinations(&xp, &yp);
    double theta_rad = theta * M_PI / 180.0;
    Matrix2d R;

    R << cos(theta_rad), -sin(theta_rad),
        sin(theta_rad), cos(theta_rad);

    Vector2d t(xc, yc);
    Vector2d p(xp, yp);
    Matrix3d T;

    T << R(0, 0), R(0, 1), t(0),
        R(1, 0), R(1, 1), t(1),
        0, 0, 1;
    Vector3d p_homo(p(0), p(1), 1);
    Vector3d result = T * Vector3d(p_homo);

    cout << "The coordinates of the point P with respect to the frame A are: " << result(0) << ", " << result(1) << endl;
    return 0;
}