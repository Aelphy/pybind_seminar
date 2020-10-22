#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>
#include <pybind11/stl.h>
#include "my_file.hpp"

namespace py = pybind11;

PYBIND11_MODULE(my_module, m) {
    m.doc() = "my_module description"; // optional module docstring
    m.def("my_function", &my_function, "my_function help string",
        py::arg("arg1"), py::arg("arg2"), py::arg("arg3"), py::arg("arg4"));
    m.def("my_function2", [](Eigen::Vector3i arg1, Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> arg2, Eigen::Vector3d arg3, Eigen::Vector3d arg4) {
    
        return 1;
    }, "my_function2 help string",
        py::arg("arg1"), py::arg("arg2"), py::arg("arg3"), py::arg("arg4"));
}
