# RayGret
Compile command:
cd /Users/franco/Desktop/RayGret
mkdir -p build
g++ -std=c++17 index.cpp -o build/RayGret && \
build/RayGret > image.ppm
open image.ppm