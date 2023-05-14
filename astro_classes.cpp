#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class CelestialBody {
    public:
        float mass, radius, density, pos[3];
        string name;

        float calc_density() {
            density = mass/(4/3*M_PI*pow(radius, 3));
            return density;
        }
}; // namespace astro_classes

class Planet : public CelestialBody {
    public:
        float orbital_radius, orbital_period, orbital_speed, orbital_eccentricity, orbital_inclination, axial_tilt, rotation_period, rotation_speed, g_surf;
        int num_moons;

        float calc_orbital_speed() {
            // v = sqrt(G*M/r)
            float G = 6.67408e-11;
            orbital_speed = sqrt(G*mass/orbital_radius);
            return orbital_speed;
        }

        float calc_g_surf() {
            // g = G*M/r^2
            float G = 6.67408e-11;
            g_surf = G*mass/pow(radius, 2);
            return g_surf;
        }

        float rotation_speed() {
            // v = 2*pi*r/T
            rotation_speed = 2*M_PI*radius/rotation_period;
            return rotation_speed;
        }
}; // namespace astro_classes::Planet

class Star : public CelestialBody {
    public:
        float luminosity, temp_surface;

        float calc_luminosity() {
            // L = 4*pi*R^2*sigma*T^4
            float sigma = 5.670374419e-8;
            luminosity = 4*M_PI*pow(radius, 2)*sigma*pow(temp_surface, 4);
            return luminosity;
        }
}; // namespace astro_classes::Star