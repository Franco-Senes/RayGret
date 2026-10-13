#include <iostream>
#include "utils/color.h"
#include "utils/vec3.h"
#include "utils/ray.h"

// Task 1: Rendeiring an image
// Finished: False Mar 13 oct 11:02am
using namespace std;
int main() {
    // Image
    int image_width = 256;
    int image_height = 256;

    // render
    cout << "P3\n" << image_width << " " << image_height << "\n255\n";
    // loop for image
    for (int j = 0; j < image_height; j++) {
        for (int i = 0; i < image_width; i++) {
             clog << "Scanlines remaining: " << (image_height - j) << ' ' << flush;
             auto pixel_color = color(double(i) / (image_width - 1), double(j) / (image_height - 1), 0.25);
            write_color(cout, pixel_color);
        }
    }
     clog << "done" << endl;
}