// made with copilot
// remove time
// used as example.
#include <fstream>
#include <iostream>
#include "nlohmann/json.hpp"

using json = nlohmann::json;

int main() {
    json settings;
    std::ifstream("settings.json") >> settings;

    std::cout << "Configuracion general\n";
    std::cout << "  samples_per_pixel: " << settings["samples_per_pixel"] << '\n';
    std::cout << "  max_depth: " << settings["max_depth"] << '\n';
    std::cout << "  aspect_ratio: " << settings["aspect_ratio"] << '\n';
    std::cout << "  image_width: " << settings["image_width"] << "\n\n";

    auto cam = settings["cam"];
    std::cout << "Configuracion de camara\n";
    std::cout << "  aspect_ratio: " << cam["aspect_ratio"] << '\n';
    std::cout << "  image_width: " << cam["image_width"] << '\n';
    std::cout << "  samples_per_pixel: " << cam["samples_per_pixel"] << '\n';
    std::cout << "  max_depth: " << cam["max_depth"] << '\n';
    std::cout << "  vfov: " << cam["vfov"] << '\n';
    std::cout << "  lookfrom: " << cam["lookfrom"] << '\n';
    std::cout << "  lookat: " << cam["lookat"] << '\n';
    std::cout << "  vup: " << cam["vup"] << '\n';
    std::cout << "  defocus_angle: " << cam["defocus_angle"] << '\n';
    std::cout << "  focus_dist: " << cam["focus_dist"] << '\n';
}
