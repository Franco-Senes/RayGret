# RayGret
##
>Raygret is a small project based on the Ray Tracing in One Weekend.
>It adds features like settings a better project structure and other features.

# RayGret

>Raygret is a small project based on the  [*Ray Tracing in One Weekend*](https://raytracing.github.io/books/RayTracingInOneWeekend.html). guide.
> Compared to [*Ray Tracing in One Weekend*](https://raytracing.github.io/books/RayTracingInOneWeekend.html) it adds features like settings and a more organize file structure.


## Requirements

- Git
- A C++ compiler with C++17 support
- An image viewer that can open PPM files

The project already includes the
[nlohmann/json](https://github.com/nlohmann/json) header, so no additional
JSON library installation is required.

## Installation

Clone the repository:

```bash
git clone https://github.com/Franco-Senes/RayGret.git
cd RayGret
```

## Build and run

Create the build directory, compile the program, and render an image:

```bash
mkdir -p build
g++ -std=c++17 index.cpp -o build/RayGret && \
build/RayGret > image.ppm
```

The rendered image is saved as `image.ppm`.

On macOS, open it with:

```bash
open image.ppm
```

On Linux, use an image viewer such as:

```bash
xdg-open image.ppm
```

## Settings

The camera and render quality are configured in `settings.json`:

```json
"cam": {
  "image_width": 400,
  "samples_per_pixel": 10,
  "max_depth": 5
}
```

- `image_width`: output image width in pixels.
- `samples_per_pixel`: number of samples per pixel.
- `max_depth`: maximum number of ray bounces.
- `vfov`: vertical field of view.
- `lookfrom`: camera position.
- `lookat`: point the camera looks at.
- `vup`: camera up direction.
- `defocus_angle`: depth-of-field blur angle.
- `focus_dist`: focus distance.

Lower values render faster. Higher values produce a cleaner image but take
longer to render.



> RayGret is a customized and JSON-configurable version of the final scene
> from *Ray Tracing in One Weekend*.

Made by Francosenes.