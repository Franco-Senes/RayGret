#ifndef CAMERA_H
#define CAMERA_H
#include "hittable.h"
#include "color.h"

class camera {
    public:
        void render(const hittable& world) {

        }
    
    private:
        void initialize() {

        }
        color ray_color(const ray& r, const hittable& world) const {

        }
};
#endif