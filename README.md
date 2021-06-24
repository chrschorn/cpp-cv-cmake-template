# C++ Computer Vision CMake Template

A minimal C++ OpenCV CMake template project that can be used as a starting-off point for development or rapid prototyping. Googletest is setup and included as the unit testing framework.

The included files are mostly targeted at Windows. Prerequisites are cmake >=3.14 and Visual Studio >=2015.

## Setup
1. Clone submodules (`git submodule update --init`)
2. Download OpenCV 4 (https://opencv.org/releases/) and unpack to lib/opencv
3. Replace "Template" in CMakeLists.txt with desired name
4. Run `build.bat`