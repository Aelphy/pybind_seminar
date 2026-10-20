# Binding C++ with Python

This repo provides a quick jump into binding C++ code with Python. In the comments of CMakeLists.txt you can find how to make it work with __CUDA__  files.

In order to compile the project:
 - [ ] `cd PATH_TO_PROJECT`
 - [ ] `mkdir build`
 - [ ] `cd build`
 - [ ] `cmake -DCMAKE_BUILD_TYPE=Release -DPython_EXECUTABLE=$(which python3) ..`
 - [ ] `make`
