#include <iostream>
#include "utils/rtRayGret.h"
#include "utils/hittable.h"
#include "utils/sphere.h"
#include "utils/hittable_list.h"
#include "utils/camera.h"
#include "utils/material.h"
#include <cmath>
#include <fstream>
#include "nlohmann/json.hpp"

using namespace std;
using json = nlohmann::json;

int main() {
    json settings;
    std::ifstream("settings.json") >> settings;
    hittable_list world;

    auto ground_material = make_shared<lambertian>(color(0.5, 0.5, 0.5));
    world.add(make_shared<sphere>(point3(0,-1000,0), 1000, ground_material));

    for (int a = -11; a < 11; a++) {
        for (int b = -11; b < 11; b++) {
            auto choose_mat = random_double();
            point3 center(a + 0.9*random_double(), 0.2, b + 0.9*random_double());

            if ((center - point3(4, 0.2, 0)).length() > 0.9) {
                shared_ptr<material> sphere_material;

                if (choose_mat < 0.8) {
                    // diffuse
                    auto albedo = color::random() * color::random();
                    sphere_material = make_shared<lambertian>(albedo);
                    world.add(make_shared<sphere>(center, 0.2, sphere_material));
                } else if (choose_mat < 0.95) {
                    // metal
                    auto albedo = color::random(0.5, 1);
                    auto fuzz = random_double(0, 0.5);
                    sphere_material = make_shared<metal>(albedo, fuzz);
                    world.add(make_shared<sphere>(center, 0.2, sphere_material));
                } else {
                    // glass
                    sphere_material = make_shared<dielectric>(1.5);
                    world.add(make_shared<sphere>(center, 0.2, sphere_material));
                }
            }
        }
    }

    auto material1 = make_shared<dielectric>(1.5);
    world.add(make_shared<sphere>(point3(0, 1, 0), 1.0, material1));

    auto material2 = make_shared<lambertian>(color(0.4, 0.2, 0.1));
    world.add(make_shared<sphere>(point3(-4, 1, 0), 1.0, material2));

    auto material3 = make_shared<metal>(color(0.7, 0.6, 0.5), 0.0);
    world.add(make_shared<sphere>(point3(4, 1, 0), 1.0, material3));

    camera cam;

    cam.aspect_ratio      = settings["cam"]["aspect_ratio"];
    cam.image_width       = settings["cam"]["image_width"];
    cam.samples_per_pixel = settings["cam"]["samples_per_pixel"];
    cam.max_depth         = settings["cam"]["max_depth"];

    cam.vfov     = settings["cam"]["vfov"];
    cam.lookfrom = point3(
        settings["cam"]["lookfrom"][0],
        settings["cam"]["lookfrom"][1],
        settings["cam"]["lookfrom"][2]
    );
    cam.lookat   = point3(
        settings["cam"]["lookat"][0],
        settings["cam"]["lookat"][1],
        settings["cam"]["lookat"][2]
    );
    cam.vup      = vec3(
        settings["cam"]["vup"][0],
        settings["cam"]["vup"][1],
        settings["cam"]["vup"][2]
    );

    cam.defocus_angle = settings["cam"]["defocus_angle"];
    cam.focus_dist    = settings["cam"]["focus_dist"];

    cam.render(world);
}