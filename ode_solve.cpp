#include <iostream>
#include <cmath>
using namespace std;

int main() {
    // x' = f(t, x), x(t0) = x0
    // t0 = initial time, x0 = initial value, t_f = final time, h = step size
    // Assuming that x(0) = x(12*M_PI) since sin is a periodic function with periodicity 2*M_PI
    // and the closest even multiple of M_PI to 76.5 is 12*M_PI
    float t0=12*M_PI, x0, t_f=76.5, h=0.765; // h = step size, is a crucial factor in the accuracy of the solution
    float f(float t, float x);
    float rk4(float t0, float x0, float t_f, float h, float f(float t, float x));
    x0 = 1;
    cout << "For x(0) = " << x0 << ", x(" << t_f << ") = " << rk4(t0, x0, t_f, h, f) << endl;
    x0 = 0;
    cout << "For x(0) = " << x0 << ", x(" << t_f << ") = " << rk4(t0, x0, t_f, h, f) << endl;
    x0 = -1;
    cout << "For x(0) = " << x0 << ", x(" << t_f << ") = " << rk4(t0, x0, t_f, h, f) << endl;
    x0 = 1.0/sqrt(2);
    cout << "For x(0) = " << x0 << ", x(" << t_f << ") = " << rk4(t0, x0, t_f, h, f) << endl;
    x0 = 1.0/2.0;
    cout << "For x(0) = " << x0 << ", x(" << t_f << ") = " << rk4(t0, x0, t_f, h, f) << endl;
    return 0;
}

float f(float t, float x) {
    // x' = sin(xt)
    return sin(x*t);
}

float rk4(float t0, float x0, float t_f, float h, float f(float t, float x)) {
    // Runge-Kutta 4th order method for solving ODEs
    float t, x, N, dx, k1, k2, k3, k4;
    N = (t_f - t0)/h;
    t = t0; x = x0;
    for (int i = 0; i < N; i++) {
        k1 = f(t, x);
        k2 = f(t+(h/2), x+(h*k1/2));
        k3 = f(t+(h/2), x+(h*k2/2));
        k4 = f(t+h, x+(h*k3));
        t += h;
        x += h*(k1+3*k2+3*k3+k4)/6;
    }
    return x;
}