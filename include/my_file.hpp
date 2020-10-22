#include <Eigen/Dense>

struct Triangle3D {
    Eigen::Vector3d p1;
    Eigen::Vector3d p2;
    Eigen::Vector3d p3;

    Eigen::Vector3d normal;
    
    Eigen::Vector3d get_upper() const;
    Eigen::Vector3d get_lower() const;
};
