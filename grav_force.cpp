#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

vector<float> grav_force(float m1, float m2, float *r1, float *r2) {
    // returns the force vector on m1 due to m2
    // r1 = 3D vector of the position of m1
    // r2 = 3D vector of the position of m2
    // r12 = r2 - r1
    // G = 6.67408e-11 m^3 kg^-1 s^-2
    float G = 6.67408e-11;
    float r12[3];
    for (int i = 0; i < 3; i++) {
        r12[i] = r2[i] - r1[i];
    }
    float r = sqrt(pow(r12[0], 2) + pow(r12[1], 2) + pow(r12[2], 2));
    float F = G*m1*m2/pow(r, 2);
    vector<float> F_vec;
    for (int i = 0; i < 3; i++) {
        F_vec.push_back(F*r12[i]/r);
    }
    return F_vec;
}

int main() {
    // m1, m2 in kg
    // r1, r2 in m
    float m1, m2, r1[3], r2[3];
    // input format:
    // m1 m2
    // r1_x r1_y r1_z
    // r2_x r2_y r2_z
    cin >> m1 >> m2;
    for (int i = 0; i < 3; i++) {
        cin >> r1[i];
    }
    for (int i = 0; i < 3; i++) {
        cin >> r2[i];
    }
    vector<float> F_vec = grav_force(m1, m2, r1, r2);
    cout << "F = (" << F_vec[0] << ", " << F_vec[1] << ", " << F_vec[2] << ")" << endl;
}