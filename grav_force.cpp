#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

vector<float> grav_force(float m1, float m2, float *r1, float *r2) {
    // returns the force vector on m1 due to m2
    // r_com = 3D vector of the position of the center of mass of the system
    // r1 = 3D vector of the position of m1
    // r2 = 3D vector of the position of m2
    // r12 = r2 - r1
    // r1 = r_com - (m2/(m1+m2))*r12
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
    float m1, m2, r1[3], r_com[3];
    m1 = 1; m2 = 1; r_com[0] = 1; r_com[1] = 2; r_com[2] = 3; r1[0] = 0; r1[1] = 2; r1[2] = 0;
    vector<float> F_vec = grav_force(m1, m2, r1, r_com);
    cout << "F = (" << F_vec[0] << ", " << F_vec[1] << ", " << F_vec[2] << ")" << endl;
}