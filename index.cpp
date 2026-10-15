#include <iostream>
#include "utils/rtRayGret.h"
#include "utils/hittable.h"
#include "utils/sphere.h"
#include "utils/hittable_list.h"
#include "utils/camera.h"
#include <cmath>

using namespace std;

int main() {
    hittable_list world;
    world.add(make_shared<sphere>(point3(0,0,-1), 0.5));
    world.add(make_shared<sphere>(point3(0,-100.5,-1), 100));

    camera cam;

    cam.aspect_ratio = 16.0 / 9.0;
    cam.image_width = 800;
    cam.samples_per_pixel = 500;
    cam.render(world);
}