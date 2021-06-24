@echo off
setlocal

mkdir build
cd build

cmake .. -A x64 -DCMAKE_INSTALL_PREFIX:PATH=%cd%
cmake --build . --config Release
cmake --install . --config Release 

bin\Release\test.exe