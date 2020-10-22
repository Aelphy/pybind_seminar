cmake_minimum_required(VERSION 3.13)

project(my_project)

# Set up include and lib paths
include_directories("${CMAKE_SOURCE_DIR}/include")
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)
set(EIGEN3_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/external/eigen")

# Find up and set up core dependency libs
find_package(Eigen3 REQUIRED)
find_package(PythonLibs REQUIRED)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

set(PYBIND11_CPP_STANDARD -std=c++11)
add_subdirectory("${CMAKE_SOURCE_DIR}/external/pybind11")

list(APPEND dl)

# Enable C++11 for host code
set(CMAKE_CXX_STANDARD 11)

# Crucial magic for CUDA linking
# find_package(CUDA 10.0 REQUIRED)
# set(CUDA_NVCC_FLAGS ${CUDA_NVCC_FLAGS}; -O3; -Xcompiler -fPIC; -std=c++11; --expt-extended-lambda;)
# list(APPEND CUDA_NVCC_FLAGS_DEBUG -G -g)

# set(CUDA_ATTACH_VS_BUILD_RULE_TO_CUDA_FILE ON)
# set(CUDA_SEPARABLE_COMPILATION ON)

# cuda_add_library(my_project_cu SHARED
#  src/my_file.cu src/my_other_file.cu
#)

# target_link_libraries(my_project_cu ${CUDA_LIBRARIES})
# target_include_directories(my_project_cu PUBLIC ${CUDA_INCLUDE_DIRS} ${PYTHON_INCLUDE_DIRS})

# cuda_add_executable(my_project_cu_test
#  src/test.cu
# )

# target_link_libraries(my_project_cu ${CUDA_LIBRARIES})
# target_link_libraries(my_project_cu_test my_project_cu)
# target_include_directories(my_project_cu_test PUBLIC ${CUDA_INCLUDE_DIRS} ${PYTHON_INCLUDE_DIRS})

# set_target_properties(my_project_cu PROPERTIES
#    POSITION_INDEPENDENT_CODE ON
#    CUDA_VISIBILITY_PRESET "hidden"
#)

add_library(my_project MODULE
    src/pybind_connector.cpp
)

set_target_properties(my_project PROPERTIES
    CXX_VISIBILITY_PRESET "hidden"
    INTERPROCEDURAL_OPTIMIZATION TRUE
    PREFIX "${PYTHON_MODULE_PREFIX}"
    SUFFIX "${PYTHON_MODULE_EXTENSION}"
)

# target_link_libraries(my_project PRIVATE my_project_cu)
target_link_libraries(my_project PRIVATE pybind11::module)
target_include_directories(my_project PUBLIC ${PYTHON_INCLUDE_DIRS})
