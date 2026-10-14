#ifndef RTRAYGRET_H
#define RTRAYGRET_H

#include <cmath>
#include <iostream>
#include <limits>
#include <memory>
#include <cstdlib>

using namespace std;
using std::make_shared;
using std::shared_ptr;

const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.14159265358979323846;

inline double degrees_to_radians(double degrees) {
    return degrees * pi / 180.0;
}

inline double random_double() {
    // Returns a random real in [0,1).
    return rand() / (RAND_MAX + 1.0);
}

inline double random_double(double min, double max) {
    // Returns a random real in [min,max).
    return min + (max-min)*random_double();
}

#include "color.h"
#include "ray.h"
#include "vec3.h"
#include "interval.h"
#endif