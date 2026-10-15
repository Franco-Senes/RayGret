#ifndef COLOR_H
#define COLOR_H
#include <iostream>
#include "vec3.h"
#include "interval.h"

using color = vec3;
using namespace std;

void write_color(ostream& out, const color& pixel_color) {
    auto r = pixel_color.x();
    auto g = pixel_color.y();
    auto b = pixel_color.z();

    // Clamp the color values to the range [0, 1]
    static const interval intensity(0.000, 0.999);
    int rbyte = int(256 * intensity.clamp(r));
    int gbyte = int(256 * intensity.clamp(g));
    int bbyte = int(256 * intensity.clamp(b));

    //output
    out << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
}

#endif