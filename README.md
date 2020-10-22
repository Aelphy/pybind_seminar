# Binding C++ with Pyth

This repo provides a quick jump into binding C++ code with Python. In the comments of CMakeLists.txt you can find how to make it work with __CUDA__  files.

In order to compile the project:
 - [ ] `cd PATH_TO_PROJECT`
 - [ ] `mkdir build`
 - [ ] `cd build`
 - [ ] `cmake -DCMAKE_BUILD_TYPE=RELEASE -DPYTHON_EXECUTABLE=/usr/local/anaconda3/bin/python3 -DCMAKE_CXX_STANDARD=11  ..`
 - [ ] `make`
